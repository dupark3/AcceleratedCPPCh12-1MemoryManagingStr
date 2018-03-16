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

    for (size_t i = 0; i != defaultStr.size(); ++i)
        std::cout << defaultStr[i];
    std::cout << std::endl;

    for (size_t i = 0; i != argStr.size(); ++i)
        std::cout << argStr[i];
    std::cout << std::endl;

    for (size_t i = 0; i != nullTermCharArrayStr.size(); ++i)
        std::cout << nullTermCharArrayStr[i];
    std::cout << std::endl;

    for (size_t i = 0; i != iteratorStr.size(); ++i)
       std::cout << iteratorStr[i];
    std::cout << std::endl;

    char* nullTerminated = argStr.c_str();
    for (size_t i = 0; i != std::strlen(nullTerminated); ++i)
        std::cout << nullTerminated[i];
    std::cout << std::endl;

}
