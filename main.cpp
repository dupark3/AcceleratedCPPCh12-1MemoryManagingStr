#include <cstring> // strlen
#include <iostream>

#include "Str.h"

int main()
{
    Str defaultStr;
    Str emptyStr;
    Str argStr(4, 'a');
    Str nullTermCharArrayStr("hello");
    Str iteratorStr(argStr.begin(), argStr.end());

    defaultStr.append("this");
    nullTermCharArrayStr.append('!');
    iteratorStr += defaultStr;

// EXERCISE 12-1 STR CLASS
    std::cout << "EXERCISE 12-0 STR CLASS" << std::endl;
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


// EXERCISE 12-2 C_STR, DATA, COPY
    std::cout << std::endl << std::endl << "EXERCISE 12-1 C_STR, DATA, COPY FUNCTIONS" << std::endl;
    std::cout << "c_str function called to create null-terminated array of char: " << std::endl;
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


// EXERCISE 12-3 AND 12-4 RELATIONAL AND EQUALITY OPERATORS
    std::cout << std::endl << std::endl << "EXERCISE 12-2 AND 12-3 RELATIONAL AND EQUALITY OPERATORS" << std::endl;
    std::cout << "Default < argument constructed? " << std::endl;
    if (defaultStr < argStr)
        std::cout << "Yes";
    else
        std::cout << "No";

    std::cout << std::endl << "Default > argument constructed? " << std::endl;
    if (defaultStr > argStr)
        std::cout << "Yes";
    else
        std::cout << "No";

    std::cout << std::endl << "Default == argument constructed? " << std::endl;
    if (defaultStr == argStr)
        std::cout << "Yes";
    else
        std::cout << "No";

    std::cout << std::endl << "Default != argument constructed? " << std::endl;
    if (defaultStr != argStr)
        std::cout << "Yes";
    else
        std::cout << "No";

// EXERCISE 12-6 OPERATOR VOID* CONVERSION
    std::cout << std::endl << std::endl << "EXERCISE 12-6 OPERATOR VOID* CONVERSION" << std::endl;
    std::cout << "Empty Default constructed Str empty? " << std::endl;
    if (emptyStr)
        std::cout << "No";
    else
        std::cout << "Yes";

// EXERCISE 12-7 GETLINE FUNCTION
    std::cout << std::endl << std::endl << "EXERCISE 12-7 GETLINE FUNCTION" << std::endl;
    std::cout << "Input line to store in getlineStr: ";
    Str getlineStr;
    getlineStr.getline(std::cin);
    std::cout << "You entered: ";
    for (size_t i = 0; i != getlineStr.size(); ++i)
        std::cout << getlineStr[i];


    return 0;
}
