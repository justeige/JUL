#ifndef JUL_PROFILING_H
#define JUL_PROFILING_H

// helper macros to create a scope timer
#if defined(_DEBUG) || defined(DEBUG)
#define measure_time() jul::detail::Scope_Timer scope_timer {__func__, std::cout}
#else
#define measure_time() ((void)0)
#endif

namespace jul {
namespace detail {

    template <class Out = std::ostream>
    struct Scope_Timer {
        using Clock = std::chrono::steady_clock;

        const char* function_name = {};
        const Clock::time_point start = {};
        Out& out;

        Scope_Timer(const char* func_name, Out& output) :
            function_name{ func_name },
            start{ Clock::now() },
            out{ output }
        {}
        ~Scope_Timer()
        {
            using namespace std::chrono;

            auto end = Clock::now();
            auto duration_in_ms = duration_cast<milliseconds>(end - start).count();
            if (duration_in_ms != 0) {
                out << function_name << ": " << duration_in_ms << " ms\n";
                return;
            }

            auto duration_in_ns = duration_cast<nanoseconds>(end - start).count();
            out << function_name << ": 0." << duration_in_ns << " ms\n";
        }
    };

 }
}

#endif // JUL_PROFILING_H