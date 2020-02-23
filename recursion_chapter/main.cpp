#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <algorithm>

void printRecursive(const std::string & str, int index)
{
    if (index == str.size())
    {
        return;
    }
    printRecursive(str, index + 1);
    std::cout << str[index];
}

int main(int argc, char * argv[])
{
    std::string str = "abcdefg";
    printRecursive(str, 0);

    return 0;
}