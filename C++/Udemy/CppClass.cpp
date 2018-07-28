/**
 * @file CppClass.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/05/2018
 * 
 * Showcase for classes in C++
 */
#include <iostream>
#include <string>

class DateTime
{
public:
    DateTime(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned minute, unsigned second);
    DateTime(unsigned year, unsigned month, unsigned day);
    ~DateTime() = default;
    std::string get_string();
private:
    unsigned year;
    unsigned month;
    unsigned day;
    unsigned hour;
    unsigned minute;
    unsigned second;
};

std::string DateTime::get_string()
{
    // dd/MM/yyyy hh:mm:ss
    std::string day_s = (this->day < 10) ? "0" + std::to_string(this->day) : std::to_string(this->day);
    std::string month_s = (this->month < 10) ? "0" + std::to_string(this->month) : std::to_string(this->month);
    std::string year_s = std::to_string(this->year);
    std::string hour_s = (this->hour < 10) ? "0" + std::to_string(this->hour) : std::to_string(this->hour);
    std::string minute_s = (this->minute < 10) ? "0" + std::to_string(this->minute) : std::to_string(this->minute);
    std::string second_s = (this->second < 10) ? "0" + std::to_string(this->second) : std::to_string(this->second);

    return day_s + "/" + month_s + "/" + year_s + " " + hour_s + ":" + minute_s + ":" + second_s;
}

DateTime::DateTime(unsigned year, unsigned month, unsigned day)
{
    if (month > 12 || day > 31)
            throw std::out_of_range("DateTime out of valid range");

        unsigned max_d = 31;

        if (month == 4 || month == 6 || month == 9 || month == 11)
            max_d = 30;
        else if (month == 2) {
            max_d = 28;
            if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
                max_d = 29;
        }

        if (day > max_d)
            throw std::out_of_range("DateTime out of valid range");

        this->year = year;
        this->month = month;
        this->day = day;

        this->hour = 0;
        this->minute = 0;
        this->second = 0;
}

DateTime::DateTime(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned minute, unsigned second)
{
    if (month > 12 || day > 31 || hour > 24 || minute > 60 || second > 60)
            throw std::out_of_range("DateTime out of valid range");

        unsigned max_d = 31;

        if (month == 4 || month == 6 || month == 9 || month == 11)
            max_d = 30;
        else if (month == 2) {
            max_d = 28;
            if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
                max_d = 29;
        }

        if (day > max_d)
            throw std::out_of_range("DateTime out of valid range");

        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        this->second = second;
}

int main(int argc, char const *argv[])
{
    DateTime d1(2018, 5, 14);
	DateTime d2(2018, 1, 20);
	DateTime d3(2018, 12, 2);
    DateTime d4(2018, 5, 14, 22, 21, 13);
    DateTime d5(2018, 5, 1, 9, 3, 7);

	std::cout << d1.get_string() << std::endl;
	std::cout << d2.get_string() << std::endl;
	std::cout << d3.get_string() << std::endl;
    std::cout << d4.get_string() << std::endl;
    std::cout << d5.get_string() << std::endl;

    return 0;
}
