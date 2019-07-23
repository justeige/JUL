#pragma once

#include <string>
#include <algorithm>
#include <cassert>

namespace jul
{
    // -------------------------------------------------------------------------------------
    // Turn each char of a string to upper. Should work on both std::string and char[].
    // Example:
    // std::string hello_s = "hello";
    // char hello_c[]      = "hello";
    // => to_upper(hello_c) == to_upper(hello_s) == "HELLO"
    // -------------------------------------------------------------------------------------
    template <class String = std::string>
    void to_upper(String& str)
    {
        std::transform(std::begin(str), std::end(str), std::begin(str), ::toupper);
    }



    // -------------------------------------------------------------------------------------
    // Same as to_upper but return a copy of the string.
    // -------------------------------------------------------------------------------------
    template <class String = std::string>
    inline String to_uppererd(String str)
    {
        std::transform(std::begin(str), std::end(str), std::begin(str), ::toupper);
        return str;
    }



    // -------------------------------------------------------------------------------------
    // Turn each char of a string to lower. Should work on both std::string and char[].
    // Example:
    // std::string hello_s = "Hello";
    // char hello_c[]      = "Hello";
    // => to_lower(hello_c) == to_lower(hello_s) == "hello"
    // -------------------------------------------------------------------------------------
    template <class String = std::string>
    void to_lower(String& str)
    {
        std::transform(std::begin(str), std::end(str), std::begin(str), ::tolower);
    }



    // -------------------------------------------------------------------------------------
    // Same as to_lowered but return a copy of the string.
    // -------------------------------------------------------------------------------------
    template <class String = std::string>
    String to_lowered(String str)
    {
        std::transform(std::begin(str), std::end(str), std::begin(str), ::tolower);
        return str;
    }



    // -------------------------------------------------------------------------------------
    // Does a string str start with a specific prefix?
    // -------------------------------------------------------------------------------------
    inline bool starts_with(const std::string& str, const std::string& prefix)
    {
        if (prefix.size() > str.size()) {
            return false;
        }
        return std::equal(std::begin(prefix), std::end(prefix), std::begin(str));
    }



    // -------------------------------------------------------------------------------------
    // Does a string str end with a specific postfix?
    // -------------------------------------------------------------------------------------
    inline bool ends_with(const std::string& str, const std::string& postfix)
    {
        if (postfix.size() > str.size()) {
            return false;
        }
        return std::equal(std::rbegin(postfix), std::rend(postfix), std::rbegin(str));
    }
    


    // -------------------------------------------------------------------------------------
    // Return a string of specific length.
    // Example:
    // auto hello = truncated("Hello world!", 5);
    // => hello = "Hello"
    // -------------------------------------------------------------------------------------
    inline std::string truncated(const std::string& str, const std::size_t length) 
    {
        assert(length > 0);
        assert(str.size() > length);

        return str.substr(0, length);
    }



    // -------------------------------------------------------------------------------------
    // Left trim of a string.
    // Example:
    // std::string str = "   AAA  ";
    // ltrim(str);
    // => str == "AAA  "
    // -------------------------------------------------------------------------------------
    inline void ltrim(std::string& str) 
    {
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int c) {
            return !std::isspace(c);
        }));
    }



    // -------------------------------------------------------------------------------------
    // Right trim of a string.
    // Example:
    // std::string str = "   AAA  ";
    // rtrim(str);
    // => str == "   AAA"
    // -------------------------------------------------------------------------------------
    inline void rtrim(std::string& str) 
    {
        str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), str.end());
    }



    // -------------------------------------------------------------------------------------
    // Trim a string from both sides.
    // Example:
    // std::string str = "   AAA  ";
    // trim(str);
    // => str == "AAA"
    // -------------------------------------------------------------------------------------
    inline void trim(std::string& str) 
    {
        ltrim(str);
        rtrim(str);
    }



    // -------------------------------------------------------------------------------------
    // Return the copy of a left trimmed string.
    // -------------------------------------------------------------------------------------
    inline std::string ltrimmed(std::string str) 
    {
        ltrim(str);
        return str;
    }



    // -------------------------------------------------------------------------------------
    // Return the copy of a right trimmed string.
    // -------------------------------------------------------------------------------------
    inline std::string rtrimmed(std::string str) 
    {
        rtrim(str);
        return str;
    }



    // -------------------------------------------------------------------------------------
    // Return the copy of a trimmed string.
    // -------------------------------------------------------------------------------------
    inline std::string trimmed(std::string str) 
    {
        trim(str);
        return str;
    }
}