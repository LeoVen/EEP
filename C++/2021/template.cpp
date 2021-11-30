#include <iostream>

template<typename T, int N>
class Array
{
private:
    T _array[N];
public:
    constexpr int size() const noexcept { return N; }
    constexpr const char* type_name() const noexcept { return typeid(T).name(); }
};

template<typename T1, typename T2, typename Out = T1>
Out add(T1 a, T2 b)
{
    return a + b;
}

int main()
{
    Array<int, 10> a;

    std::cout << add(12.2, 10) << "\n";
    std::cout << add(10, 12.2) << "\n";

    std::cout << a.size() << "\n";
    std::cout << a.type_name() << "\n";
}
