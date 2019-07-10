#pragma once

#include <map>
#include <vector>

namespace jul 
{
    // ---------------------------------------------------------------------------------
    // Does a map contain a certain key? This function will NOT create that value in the map.
    // example:
    // std::map<int, std::string> m{ {1, "one"}, {2, "two"}, {3, "three"} };
    // bool has_one = contains(m, 1);
    //
    // => has_one = true
    // ---------------------------------------------------------------------------------
    template <class Key, class Value>
    bool contains(const std::map<Key, Value>& m, const Key& key)
    {
        auto it = m.find(key);
        return it != std::end(m);
    }



    // ---------------------------------------------------------------------------------
    // Copy all keys from a map into a vector.
    // example:
    // std::map<int, std::string> m{ {1, "one"}, {2, "two"}, {3, "three"} };
    // auto keys = copy_keys(m);
    //
    // => keys = {1,2,3}
    // ---------------------------------------------------------------------------------
    template<typename Key, typename Value>
    std::vector<Key> copy_keys(std::map<Key, Value> const& m)
    {
        std::vector<Key> keys;
        for (auto kv : m) {
            keys.push_back(kv.first);
        }
        return keys;
    }



    // ---------------------------------------------------------------------------------
    // Copy all values from a map into a vector.
    // example:
    // std::map<int, std::string> m{ {1, "one"}, {2, "two"}, {3, "three"} };
    // auto values = copy_values(m);
    //
    // => values = {"one", "two", "three"}
    // ---------------------------------------------------------------------------------
    template<typename Key, typename Value>
    std::vector<Value> copy_values(std::map<Key, Value> const& m)
    {
        std::vector<Value> values;
        for (auto kv : m) {
            values.push_back(kv.second);
        }
        return values;
    }



    // ---------------------------------------------------------------------------------
    // Split a map by copying its keys and values into vectors.
    // example:
    // std::map<int, std::string> m{ {1, "one"}, {2, "two"}, {3, "three"} };
    // auto [keys, values] = split_map(m);
    //
    // => keys = {1,2,3}, values = {"one", "two", "three"}
    // ---------------------------------------------------------------------------------
    template<typename Key, typename Value>
    std::pair<std::vector<Key>, std::vector<Value>> split_map(std::map<Key, Value> const& m)
    {
        std::vector<Key>   keys;
        std::vector<Value> values;
        for (auto [key, value] : m) {
            keys.push_back(key);
            values.push_back(value);
        }
        return {keys, values};
    }
}
