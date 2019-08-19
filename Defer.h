#ifndef JUL_DEFER_H
#define JUL_DEFER_H

/*
MIT License

Copyright(c) 2019 Julian Steigerwald

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/



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