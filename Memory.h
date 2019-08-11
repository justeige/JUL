#ifndef JUL_MEMORY_H
#define JUL_MEMORY_H

// -------------------------------------------------------------------
// This is a collection of very special memory functions.
// These are mostly for replacing legacy code or should be used when REALLY
// needed.
// Quick reminder what few advantages 'malloc' has over 'new':
//
// - malloc() doesn't call constructors
// - malloc will return NULL instead of throwing on fail (only usefull in low mem. environments)
// - new() can't reallocate memory explicit
// -------------------------------------------------------------------

#include <cstddef>
#include <cassert>
#include <type_traits>

namespace jul {

    template <class T>
    T* allocate()
    {
        static_assert(std::is_pod<T>::value, "allocating a non-pod type!");
        return static_cast<T*>(std::malloc(sizeof(T)));
    }

    template <class T>
    T reallocate(T memory, std::size_t old_size, std::size_t new_size)
    {
        if (new_size == 0) {
            std::free(memory);
            return nullptr;
        }

        return static_cast<T>(std::realloc(memory, new_size));
    }

    template <class T>
    T grow_memory(T memory, std::size_t old_count, std::size_t new_count)
    {
        return jul::reallocate(memory, sizeof(T) * old_count, sizeof(T) * new_count);
    }


    template <class T>
    void free_array(T memory, std::size_t allocated)
    {
        const auto new_mem = reallocate(memory, sizeof(T) * allocated, 0);
        assert(new_mem == nullptr); // sanity check
    }

}


#endif // JUl_MEMORY_H
