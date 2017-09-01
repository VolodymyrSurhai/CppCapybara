# CppCapybara.
I will be glad if you find some useful stuff in this code.
## Disclaimer.
The code is distributed as is. The author is not responsible for the correctness of the code works. You automatically agree to this license when you turn the project code in your project.
# Features.
## Capybara::reversed.
Simple function for getting reversed iteration in modern "for".
```cpp
std::vector<int> container = {1, 2, 3, 4};

for (const auto& item : reversed(container))
{
    use_item(item);
}
```
## Capybara::format
```cpp
auto formatted_text = "{}-{}-{}::{}::{}<={}={}"_format("a", "b", 23, "dsf", 1.234345, "d", "Вжух");
std::cout << formatted_text << std::endl;
```
Result:
> a-b-23::dsf::1.234345<=d=Вжух
## Capybara::zip.
This function returns of a tuple from iterators.
```cpp
std::vector<int> numbers = {11, 21, 31, 41};
std::vector<std::string> text = {"first", "second", "third", "fourth"};

for (auto& zipped : zip(numbers, text)) {
    result += std::to_string(zipped.second);
    result += zipped.first;
  }
```
Result:
> first11second21third31fourth41
