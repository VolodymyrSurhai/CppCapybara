#pragma once

#include <vector>
#include <iterator>
#include <string>


namespace Capybara {

    template<class T>
    void concatenate (std::string& result, const T &add) {
        result += std::to_string(add);
    }

    void concatenate (std::string &result, const char *add) {
        result += add;
    }

    template<class Tuple, std::size_t N>
    struct TuplePrinter {
        static void add (std::string &result, const Tuple &t) {
            TuplePrinter<Tuple, N - 1>::add(result, t);
            const auto param = std::get<N - 1>(t);
            concatenate(result, param);
        }
    };

    template<class Tuple>
    struct TuplePrinter<Tuple, 1> {
        static void add (std::string &result, const Tuple &t) {
            result += std::get<0>(t);
        }
    };

    template<class... Args>
    void add (std::string &result, const std::tuple<Args...> &t) {
        TuplePrinter<decltype(t), sizeof...(Args)>::add(result, t);
    }

    class FormattedString {
    public:
        FormattedString (std::string pattern)
                : _pattern(std::move(pattern)) {
        }

        template<class ...Args>
        std::string operator() (Args... args) {
            const auto params = std::make_tuple(args...);

            auto result = _pattern;


            add(result, params);

            return result;
        }

    private:
        const std::string _pattern;
    };

    FormattedString operator ""_format (const char *pattern, size_t) {
        return FormattedString(pattern);
    }


} // namespace Capybara