#pragma once

#include <string>
#include <algorithm>

namespace CppPrimer::Utils
{
    inline std::string trim(const std::string &s)
    {
        auto start = s.begin();
        while (start != s.end() && std::isspace(*start))
        {
            start++;
        }

        auto end = s.end();
        do
        {
            end--;
        } while (std::distance(start, end) > 0 && std::isspace(*end));

        return std::string(start, end + 1);
    }

    template <typename T>
        requires std::integral<T>
    inline bool is_even(T num)
    {
        return num % 2 == 0;
    }

    template <typename T>
    inline typename std::enable_if<std::is_integral<T>::value, bool>::type is_even_cpp11(T num)
    {
        return num % 2 == 0;
    }
}