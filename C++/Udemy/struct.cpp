/**
 * @file struct.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/05/2018
 * 
 * Showcase for structures in C++
 */
#include <iostream>
#include <string>

struct Date
{
private:
    unsigned year, month, day;

public:
    Date(unsigned y, unsigned m, unsigned d)
    {
        if (m > 12 || d > 31)
            throw std::out_of_range("Date out of valid range");

        unsigned max_d = 31;

        if (m == 4 || m == 6 || m == 9 || m == 11)
            max_d = 30;
        else if (m == 2) {
            max_d = 28;
            if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
                max_d = 29;
        }

        if (d > max_d)
            throw std::out_of_range("Date out of valid range");

        this->year = y;
        this->month = m;
        this->day = d;
    }

    std::string to_str()
    {
        return std::to_string(this->day) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year);
    }

};

int main(int argc, char const *argv[])
{
    struct Date date1 = Date(2018, 5, 14);
    
    std::cout << date1.to_str() << std::endl;

    return 0;
}
