#pragma once

#include <random>
#include <vector>
#include <cassert>
#include <type_traits>

namespace jul {

    // --------------------------------------------------------
    // Get a random int between min/max
    // --------------------------------------------------------
    template <class Integer = int>
    Integer random_int(Integer min, Integer max)
    {
        // static checks:
        static_assert(std::is_integral<Integer>::value, "Type is no integer!");

        // runtime checks:
        assert(min < max);

        static std::random_device rd; // create object for seeding
        static std::mt19937 mt{ rd() }; // create engine and seed it

        std::uniform_int_distribution<> dist{ min, max };
        return dist(mt);
    }

    // --------------------------------------------------------
    // Get a number of random ints between min/max
    // --------------------------------------------------------
    template <class Integer = int>
    std::vector<Integer> random_ints(Integer min, Integer max, std::size_t num_of_ints)
    {
        // static checks:
        static_assert(std::is_integral<Integer>::value, "Type is no integer!");

        // runtime checks:
        assert(min < max);
        assert(num_of_ints != 0);

        static std::random_device rd; // create object for seeding
        static std::mt19937 mt{ rd() }; // create engine and seed it

        std::uniform_int_distribution<> dist{ min, max };

        std::vector<Integer> v;
        for (std::size_t n = 0; n < num_of_ints; ++n) {
            v.push_back(dist(mt));
        }
        return v;
    }

    // --------------------------------------------------------
    // Get a random boolean by percentage ratio:
    // random_bool(0.5)  => 50/50 split of true/false
    // random_bool(0.75) => 75/25 split of true/false
    // --------------------------------------------------------
    template <class FloatingPoint = double>
    bool random_bool(FloatingPoint percentage_of_true = FloatingPoint{ 0.5 })
    {
        // static checks:
        static_assert(std::is_floating_point<FloatingPoint>::value, "Type is no floating point!");

        static std::random_device rd; // create object for seeding
        static std::mt19937 mt{ rd() }; // create engine and seed it

        std::bernoulli_distribution dist{ percentage_of_true };
        return dist(mt);
    }

}