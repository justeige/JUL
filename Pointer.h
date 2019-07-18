#ifndef JUL_POINTER_H
#define JUL_POINTER_H

#include <memory> // for std::unique_ptr, std::shared_ptr
#include <cassert>

namespace jul {

    // reference counted non-sharing
    template <class T>
    using Unique = std::unique_ptr<T>;



    // reference counted sharing
    template <class T>
    using Shared = std::shared_ptr<T>;



    // raw pointer
    template <class T>
    using Ptr = T *;



    // reference
    template <class T>
    using Ref = T &;



    // RAII wrapper for raw pointer, no reference counting
    template <class T>
    class Scoped {
    public:
        explicit Scoped()       : m_ptr{nullptr} {}

        explicit Scoped(T* ptr) : m_ptr{ptr}     
        {
            assert(ptr != nullptr);
        }

        ~Scoped() { release(); }

        void release() 
        { 
            if (m_ptr) {
                delete(m_ptr);
                m_ptr = nullptr;
            }
        }

        void operator = (T* ptr) 
        { 
            assert(ptr != nullptr   && "Assignment of a nullptr is now allowed!");
            assert(m_ptr == nullptr && "Reassigment without releasing the memory!");

            m_ptr = ptr; 
        }

        T& operator * () { return *m_ptr; }
        T* operator ->() { return m_ptr;  }

    private:
        T* m_ptr;
    };
}

#endif // JUL_POINTER_H