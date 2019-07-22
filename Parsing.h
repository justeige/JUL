#ifndef JUL_PARSING_H
#define JUL_PARSING_H

#include <optional>
#include <string>

namespace jul {

    template <class Number>
    std::optional<Number> try_parse(const std::string& str)
    {
        try
        {
            if constexpr (std::is_same<Number, int>::value) {
                return std::stoi(str, nullptr, 0);
            }
            else if constexpr (std::is_same<Number, long>::value) {
                return std::stol(str, nullptr, 0);
            }
            else if constexpr (std::is_same<Number, float>::value) {
                return std::stof(str, nullptr, 0);
            }
            else if constexpr (std::is_same<Number, double>::value) {
                return std::stod(str, nullptr, 0);
            }
            else {
                static_assert(false, "Type is not supported!");
            }
        }
        catch (const std::exception&)
        {
            // all std:: conversation functions throw exceptions on a bad value...
            return std::nullopt;
        }
    }

    // broken?
    template<class TargetType, class SourceType>
    std::optional<TargetType> try_narrow_cast(SourceType value)
    {
        auto converted = static_cast<TargetType>(value);
        auto back      = static_cast<SourceType>(converted);

        if (back != value) {
            return std::nullopt;
        }
        return converted;
    }

}
#endif // JUL_PARSING_H
