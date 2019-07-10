#ifndef JUL_DEFER_H
#define JUL_DEFER_H

// ---------------------------------------------------------------------------------
// This is a copy of the Golang keyword 'defer'.
// The concept is in C++ known under ScopeGuard, ExitGuard and similar constructs.
// Basically, it uses RAII for arbitrary code segments.
//
// Example:
// void my_function() {
//     m = allocate_memory();
//     defer(delete_memory(m););
//     /* other code */    
// } <- at function end, the defer-block will be called!
// ---------------------------------------------------------------------------------

#define defer(func) auto DEFER_UNIQUE_NAME = jul::detail::Deferred { []() { func } }

// helper macros to create a unique name for every defer-block
#define JUL_DEFER_CONCAT_(x,y) x##y
#define JUL_DEFER_CONCAT(x,y) DEFER_CONCAT_(x,y)
#define JUL_DEFER_UNIQUE_NAME DEFER_CONCAT(defer_, __LINE__)

namespace jul {
namespace detail {

    template <class Function>
    class Deferred {
    public:
        explicit Deferred(Function f) noexcept : m_f(std::move(f)) {}

        ~Deferred() { m_f(); }

    private:
        Function m_f;
    };

}
}

#endif // JUL_DEFER_H