/* Accelerated C++ Exercise 12-0
Implement the Str class that simplifies the string class as defined by the standard library. */

/*  Accelerated C++ Exercise 12-1
Implement the Str class, but choose an implementation strategy that
requires that the class manage the storage itself. For example, you might
store an array of char and a length. */

/* Accelerated C++ Exercise 12-2
Implement the c_str, data, and copy functions that the string library implements in order to
convert a string into a null-terminated char array without causing memory management issues */

#include <cstring> // strlen
#include <iostream>

#include "Str.h"

int main()
{
    Str defaultStr;
    Str argStr(4, 'a');
    Str nullTermCharArrayStr("hello");
    Str iteratorStr(argStr.begin(), argStr.end());

    defaultStr.append("this");
    nullTermCharArrayStr.append('!');
    iteratorStr += defaultStr;

    std::cout << "Default constructed then append called: " << std::endl;
    for (size_t i = 0; i != defaultStr.size(); ++i)
        std::cout << defaultStr[i];

    std::cout << std::endl << "Argument constructed using Size and Value: " << std::endl;
    for (size_t i = 0; i != argStr.size(); ++i)
        std::cout << argStr[i];

    std::cout << std::endl << "String literal constructed: " << std::endl;
    for (size_t i = 0; i != nullTermCharArrayStr.size(); ++i)
        std::cout << nullTermCharArrayStr[i];

    std::cout << std::endl << "Begin and End iterator constructed: " << std::endl;
    for (size_t i = 0; i != iteratorStr.size(); ++i)
       std::cout << iteratorStr[i];

    std::cout << std::endl << "c_str function called to create null-terminated array of char: " << std::endl;
    char* nullTerminated = argStr.c_str();
    for (size_t i = 0; i != std::strlen(nullTerminated); ++i)
        std::cout << nullTerminated[i];

    std::cout << std::endl << "data function called to create array of char (no null terminator): " << std::endl;
    char* data = argStr.dataFunction();
    for (size_t i = 0; i != argStr.size(); ++i)
        std::cout << data[i];

    std::cout << std::endl << "Substring copy function, copying 3 elements from default: " << std::endl;
    char* substring = new char[3];
    defaultStr.copy(substring, 3);
    for (size_t i = 0; i != 3; ++i)
        std::cout << *(substring + i);
    delete[] substring;

    std::cout << std::endl << "Default < argument constructed? " << std::endl;
    if (defaultStr < argStr)
        std::cout << "Yes";
    else
        std::cout << "No";

    std::cout << std::endl << "Default > argument constructed? " << std::endl;
    if (defaultStr > argStr)
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}
