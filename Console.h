#ifndef JUL_CONSOLE_H
#define JUL_CONSOLE_H

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


#include <iostream>

#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  include <Windows.h>
#endif

namespace jul {

    // Wrapper for Console functions
    class Console final {
    public:

        enum Font_Color {
            dark_blue = 1,
            green,
            light_blue,
            red,
            purple,
            yellow,
            white,
            gray,
            blue,
            light_green,
            turqoise,
            light_red,
            light_purple,
            beige,
            text_white,

            default_color = white
        };

        static std::string GetLine(const std::string& query_text = "")
        {
            if (!query_text.empty()) {
                Write(query_text);
            }

            std::string input {};
            std::getline(std::cin, input);
            return input;
        }

        template <class T>
        static void Write(const T& value)
        {
            std::cout << value;
        }

        template <class T, class... Other>
        static void Write(const T& value, Other... values)
        {
            Write(value);
            Write(values...);
        }

        template <class T>
        static void WriteLine(const T& value)
        {
            std::cout << value << '\n';
        }

        template <class T, class... Other>
        static void WriteLine(const T& value, Other... values)
        {
            WriteLine(value);
            WriteLine(values...);
        }

        template <class T>
        static void Error(const T& value)
        {
            Set_Font_Color(Font_Color::red);
            std::cout << value << '\n';
            Set_Font_Color();
        }

        template <class T, class... Other>
        static void Error(const T& value, Other... values)
        {
            Set_Font_Color(Font_Color::red);
            std::cout << value;
            Error(values...);
            Set_Font_Color();
        }

        template <class T>
        static void Success(const T& value)
        {
            Set_Font_Color(Font_Color::green);
            std::cout << value << '\n';
            Set_Font_Color();
        }

        template <class T, class... Other>
        static void Success(const T& value, Other... values)
        {
            Set_Font_Color(Font_Color::green);
            std::cout << value;
            Success(values...);
            Set_Font_Color();
        }

        static void Set_Font_Color(Font_Color color = default_color)
        {
#ifdef _WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)color);
#endif            
        }

    private:
    };

}

#endif // JUL_CONSOLE_H