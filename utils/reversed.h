#pragma once 

#include <vector>
#include <iterator>


namespace Capybara
{
namespace utils
{
    template <typename T>
    struct ReversedVector
    {
        ReversedVector(std::vector<T>& list)
        : _list(list)
        {
        }

        std::reverse_iterator<typename std::vector<T>::iterator> begin()
        {
            return _list.rbegin();
        }

        std::reverse_iterator<typename std::vector<T>::iterator> end()
        {
            return _list.rend();
        }

    private:
        std::vector<T>& _list;
    };

    template <typename T>
    ReversedVector<T> reversed (std::vector<T> &list)
    {
        return ReversedVector<T>(list);
    }
} // namespace utils
} // namespace Capybara