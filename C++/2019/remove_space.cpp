#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: \n";
        std::cout << "    a.exe source destination \n";
        std::cout << "Where source and destination are file names.\n";
        return -1;
    }

    std::ifstream input(argv[1], std::ifstream::in);
    std::ofstream output(argv[2], std::ifstream::out);

    if (input.fail() || output.fail())
    {
        std::cerr << "Could not open file.\n";
        return -2;
    }

    while (input.good())
    {
        int c = input.get();

        if (!isspace(c) && c != EOF)
            output << (char)c;
    }

    input.close();
    output.close();

    return 0;
}
