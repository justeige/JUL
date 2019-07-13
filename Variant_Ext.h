#ifndef JUL_VARIANT_H
#define JUL_VARIANT_H

namespace jul {

    template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
    template<class... Ts> overloaded(Ts...)->overloaded<Ts...>;

    // ---------------------------------------------------------------------------------------
    // match: A nicer syntax for visiting variants... should be a keyword in c++... 
    // example:
    //
    // std::variant<int, float, std::string> ifs{ "Should be 2" };
    // int val = jul::match(ifs,
    //    [](const int& i)         -> int { return 0;},
    //    [](const float& f)       -> int { return 1;},
    //    [](const std::string& s) -> int { return 2;}
    // );
    // => val = 2
    // ---------------------------------------------------------------------------------------
    template <typename Variant, typename... Cases>
    auto match(Variant&& variant, Cases&& ... cases)
    {
        return std::visit(overloaded{ std::forward<Cases>(cases)... }, std::forward<Variant>(variant));
    }

}

#endif // JUL_VARIANT_H
