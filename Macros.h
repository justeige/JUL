#ifndef JUL_MACRO_H
#define JUL_MACRO_H

#include <cassert>



// macros for loops:
#define forever        for (;;)
#define repeat(cnt, N) for (int cnt = 0; cnt < N; ++cnt)



// assert that n is a valid number (NaN will fail this!)
#define nan_check(n) assert(n == n)



// disable copy and assignment
#define no_copy_and_assign(obj)     \
    obj(obj const& other) = delete; \
    void operator=(obj const& other) = delete;




// disable move and assignment
#define no_move_and_assign(obj) \
    obj(obj && other) = delete; \
    void operator=(obj && other) = delete;


#endif // JUL_MACRO_H