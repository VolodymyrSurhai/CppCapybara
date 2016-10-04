#include "reversed.h"

#include <iostream>

namespace Capybara
{
namespace utils
{
namespace  tests
{
    template<typename T>
    void foo(std::vector<T> &list) {
        for (auto &item: reverse(list)) {
            item += 65;
            std::cout << item << std::endl;
        }
    }


} // namespace  tests
} // namespace utils
} // namespace Capybara

int main() {
    std::vector<int> a1 = {1, 2, 3, 4};
    std::vector<std::string> a2 = {"1", "2", "3", "4"};

    Capybara::utils::tests::foo(a1);
    Capybara::utils::tests::foo(a2);

    return 0;
}