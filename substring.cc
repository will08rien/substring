#include "substring.h"
#include <iostream>

namespace wob {
    std::tuple<bool, size_t> find(std::string_view needle, std::string_view haystack) {
        auto nl = needle.length();
        for (auto i = 0ul; i < 1 + haystack.length() - nl; i++) {
            auto found = true;
            for (auto j = 0ul; j < nl; j++)
                found &= haystack[i+j] == needle[j];
            if (found) return std::make_tuple(true, i);
        }
        return std::make_tuple(false, 0);
    }
}
