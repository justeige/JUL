#pragma once

#define defer(func) auto DEFER_UNIQUE_NAME = jul::detail::Deferred { []() { func } }

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