#include "format_literal.h"

#include <array>

namespace Capybara
{
    void concatenate (std::string& result, const char* add)
    {
        result += add;
    }

    FormattedString::FormattedString (std::string pattern, size_t size)
            : _pattern(std::move(pattern))
    {
    }


    FormattedString operator ""_format (const char* pattern, const size_t size)
    {
        return FormattedString(pattern, size);
    }

} // namespace Capybara
