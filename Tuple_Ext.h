#ifndef JUL_TUPLE_H
#define JUL_TUPLE_H

#include <tuple>

namespace jul {



        // --------------------------------------------------------------------------------------
        // std::for_each for tuples, applies a function for each element of a tuple. 
        // --------------------------------------------------------------------------------------
        template <class Function, std::size_t Index = 0, class... Types>
        void for_each(const std::tuple<Types ...> & t, Function && fn)
        {
            if constexpr (Index < std::tuple_size_v<std::tuple<Types ...>>) {
                fn(std::get<Index>(t));
                jul::for_each<Function, Index + 1>(t, fn); // iterate next
            }
        }



        // --------------------------------------------------------------------------------------
        // std::any_of for tuples, checks if any element of a tuple resolves a predicate.
        // --------------------------------------------------------------------------------------
        template <class Predicate, std::size_t Index = 0, class... Types>
        bool any_of(const std::tuple<Types ...>& t, Predicate && pred)
        {
            if constexpr (Index < std::tuple_size_v<std::tuple<Types ...>>) {
                if (bool is_true = pred(std::get<Index>(t)); is_true) {
                    return true; // found the first element thats true, stop iteration
                }
                // iterate next
                return jul::any_of<Predicate, Index + 1>(t, pred);
            }
            else {
                return false; // unrolling is done, no element returned true
            }
        }



        // --------------------------------------------------------------------------------------
        // std::all_of for tuples, checks if all element of a tuple resolves a predicate.
        // --------------------------------------------------------------------------------------
        template <class Predicate, std::size_t Index = 0, class... Types>
        bool all_of(const std::tuple<Types ...>& t, Predicate && pred)
        {
            if constexpr (Index < std::tuple_size_v<std::tuple<Types ...>>) {
                if (bool is_true = pred(std::get<Index>(t)); is_true) {
                    return jul::all_of<Predicate, Index + 1>(t, pred);
                }                
                return false;
            }
            else {
                return true;
            }
        }



        // --------------------------------------------------------------------------------------
        // std::none_of for tuples, checks if no element of a tuple resolves a predicate.
        // --------------------------------------------------------------------------------------
        template <class Predicate, std::size_t Index = 0, class ... Types>
        bool none_of(const std::tuple<Types ...>& t, Predicate && pred)
        {
            return !jul::any_of(t, pred);
        }


}

#endif // !JUL_TUPLE_H
