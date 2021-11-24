#include <iostream>
#include <vector>

auto make_even(int& value)
{
    value += value % 2;
}

auto main() -> int {
    std::vector<int> vec {11, 15, 16, 19, 20};

    for (auto& val: vec)
    {
        make_even(val);
    }

    for (auto& val: vec)
    {
        std::cout << val << " " << std::endl;
    }
}
