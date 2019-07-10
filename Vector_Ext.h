#pragma once

#include <vector>
#include <algorithm>
#include <cassert>


namespace jul 
{
    // ---------------------------------------------------------------------------------
    // Does a vector contain a certain value?
    // example:
    // std::vector<int> ints = { 0,1,2,3 };
    // bool has_two = contains(ints, 2);
    //
    // => has_two = true
    // ---------------------------------------------------------------------------------
    template <class T>
    bool contains(const std::vector<T>& v, const T& value)
    {
        auto first = std::begin(v);
        auto last = std::end(v);
        return std::find(first, last, value) != last;
    }



    // ---------------------------------------------------------------------------------
    // Removes all values from a vector.
    // example:
    // std::vector<int> ints = { 0,1,0,3 };
    // remove_all(ints, 0);
    //
    // => ints = {1,3}
    // ---------------------------------------------------------------------------------
    template <class T>
    void remove_all(std::vector<T>& v, T value)
    {
        v.erase(std::remove(std::begin(v), std::end(v), value), std::end(v));
    }



    // ---------------------------------------------------------------------------------
    // Removes all values from a vector and returns a copy.
    // example:
    // std::vector<int> ints = { 0,1,0,3 };
    // auto without_zero = removed_all(ints, 0);
    //
    // => without_zero = {1,3}
    // ---------------------------------------------------------------------------------
    template <class T>
    std::vector<T> removed_all(std::vector<T> v, T value)
    {
        v.erase(std::remove(std::begin(v), std::end(v), value), std::end(v));
        return v;
    }



    // ---------------------------------------------------------------------------------
    // Wrapper for std::sort for a complete vector.
    // ---------------------------------------------------------------------------------
    template <class T>
    void sort(std::vector<T>& v)
    {
        std::sort(std::begin(v), std::end(v));
    }



    // ---------------------------------------------------------------------------------
    // Wrapper for std::sort for a complete vector with a custom predicate.
    // ---------------------------------------------------------------------------------
    template <class T, class Predicate>
    void sort(std::vector<T>& v, Predicate&& pred)
    {
        std::sort(std::begin(v), std::end(v), pred);
    }



    // ---------------------------------------------------------------------------------
    // Wrapper for std::sort for a complete vector, returns a copy of the vector.
    // ---------------------------------------------------------------------------------
    template <class T>
    std::vector<T> sorted(std::vector<T> v)
    {
        std::sort(std::begin(v), std::end(v));
        return v;
    }



    // ---------------------------------------------------------------------------------
    // Wrapper for std::sort for a complete vector, returns a copy and uses a custom predicate.
    // ---------------------------------------------------------------------------------
    template <class T, class Predicate>
    std::vector<T> sorted(std::vector<T> v, Predicate&& pred)
    {
        std::sort(std::begin(v), std::end(v), pred);
        return v;
    }



    // ---------------------------------------------------------------------------------
    // Wrapper for std::transform for a complete vector.
    // ---------------------------------------------------------------------------------
    template <class T, class Function>
    void apply_each(std::vector<T>& v, Function&& fn)
    {
        std::transform(std::begin(v), std::end(v), std::begin(v), fn);
    }



    // ---------------------------------------------------------------------------------
    // Returns the max value of the vector.
    // Precondition: vector can't be empty!
    // ---------------------------------------------------------------------------------
    template <class T>
    T max_value(const std::vector<T>& v)
    {
        assert(std::size(v) != 0);
        return *std::max_element(std::begin(v), std::end(v));
    }



    // ---------------------------------------------------------------------------------
    // Returns the max value of the vector with a custom compare function.
    // Precondition: vector can't be empty!
    // ---------------------------------------------------------------------------------
    template <class T, class Compare>
    T max_value(const std::vector<T>& v, Compare&& comp)
    {
        assert(std::size(v) != 0);
        return *std::max_element(std::begin(v), std::end(v), comp);
    }



    // ---------------------------------------------------------------------------------
    // Returns the min value of the vector.
    // Precondition: vector can't be empty!
    // ---------------------------------------------------------------------------------
    template <class T>
    T min_value(const std::vector<T>& v)
    {
        assert(std::size(v) != 0);
        return *std::min_element(std::begin(v), std::end(v));
    }



    // ---------------------------------------------------------------------------------
    // Returns the int value of the vector with a custom compare function.
    // Precondition: vector can't be empty!
    // ---------------------------------------------------------------------------------
    template <class T, class Compare>
    T min_value(const std::vector<T>& v, Compare&& comp)
    {
        assert(std::size(v) != 0);
        return *std::min_element(std::begin(v), std::end(v), comp);
    }



    // ---------------------------------------------------------------------------------
    // Get a copy of all elements within limits.
    // Example:
    // std::vector<int> ints = { 0,1,0,3 };
    // auto limited = within_limits(ints, 0, 1);
    //
    // => limited = {0,1,0}
    // ---------------------------------------------------------------------------------    
    template <class T>
    std::vector<T> within_limits(std::vector<T> values, T min, T max)
    {
        auto filter = [=](T value) {return value < min || value > max;};
        values.erase(std::remove_if(std::begin(values), std::end(values), filter), std::end(values));
        return values;
    }



    // ---------------------------------------------------------------------------------
    // Get a copy of all elements outside limits.
    // Example:
    // std::vector<int> ints = { 0,1,0,3 };
    // auto outside = out_of_limits(ints, 0, 1);
    //
    // => outside = {3}
    // --------------------------------------------------------------------------------- 
    template <class T>
    std::vector<T> out_of_limits(std::vector<T> values, T min, T max)
    {
        auto filter = [=](T value) {return value >= min && value <= max;};
        values.erase(std::remove_if(std::begin(values), std::end(values), filter), std::end(values));
        return values;
    }


    
    // ---------------------------------------------------------------------------------
    // Calculate the mean value of some values.
    // ---------------------------------------------------------------------------------
    template <class T>
    double mean(const std::vector<T>& values)
    {
        auto beg = std::begin(values);
        auto end = std::end(values);
        assert(beg != end && "Calculation of mean is not possible on empty range!");

        const double sum   = static_cast<double>(std::accumulate(beg, end, T {0}));
        const double count = std::size(values);

        return sum / count;
    }



    // ---------------------------------------------------------------------------------
    // Calculate the standard_deviation of some values.
    // ---------------------------------------------------------------------------------
    template <class T>
    double standard_deviation(const std::vector<T>& values)
    {
        const double m = mean(values);
        double sum = 0.0;
        std::for_each(std::begin(values), std::end(values), [&](const double d) {
            sum += (d - m) * (d - m);
        });

        return static_cast<double>(sqrt(sum / (values.size() - 1)));
    }

}