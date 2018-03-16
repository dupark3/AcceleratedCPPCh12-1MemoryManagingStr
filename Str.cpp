#include <cstring> // str_len

#include "Str.h"

// Supports the default constructor
void Str::create(){
    data = last = limit = 0;
    arraySize = 0;
}

// Supports the constructor that takes a size and a char
// If no char provided, value initialized default argument for char
void Str::create(size_t n, const char& c){
    arraySize = n;
    data = alloc.allocate(arraySize);
    last = limit = data + arraySize;
    std::uninitialized_fill(data, last, c);
}

// Supports the constructor that takes a string literal
void Str::create(const char* cp){
    arraySize = std::strlen(cp);
    data = alloc.allocate(arraySize);
    last = limit = data + arraySize;
    std::uninitialized_copy(cp, cp + arraySize, data);
}

// Supports the destructor
void Str::uncreate(){
    if (data){
        clear();
        alloc.deallocate(data, limit - data);
    }
    data = last = limit = 0;
}

// Supports the uncreate() and operator>> function by deconstructing all existing elements
void Str::clear(){
    if (data){
        char* it = last;
        while (it != data)
            alloc.destroy(--it);
    }
    last = data;
}

// Overloaded append functions to take a character, string literal, or class object
void Str::append(const char& c){
    if (last == limit)
        grow();
    unchecked_append(c);
}

void Str::append(const char* c){
    for (size_t i = 0; i != sizeof c; ++i)
        append(*(c + i));
}

void Str::append(const Str& s){
    for (size_t i = 0; i != s.size(); ++i)
        append(*(s.data + i));
}

// Supports the append function
void Str::grow(){
    size_t new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    char* new_data = alloc.allocate(new_size);
    char* new_last = std::uninitialized_copy(data, last, new_data);
    uncreate();
    data = new_data;
    last = new_last;
    limit = data + new_size;
}

// Supports the append function. Only called with enough memory already allocated
void Str::unchecked_append(const char& c){
    alloc.construct(last++, c);
    ++arraySize;
}

// Returns a null-terminated string
char* Str::c_str(){
    // Allocate new memory for deep copy
    char* ret = new char[last - data];

    // Set one past the last element as NULL
    *last = '\0';

    // Copy into newly allocated char array, including the NULL element at "last"
    std::copy(data, last + 1, ret);

    return ret;
}






            /*********************
             NON MEMBER FUNCTIONS
             ********************/

// Output nonmember function
std::ostream& operator<<(std::ostream& os, const Str& s){
    for(Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

// Input friend function (gains access to private member data for writing)
std::istream& operator>>(std::istream& is, Str& s){
    s.clear();

    // read and discard all leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ;

    // if something still to read, read and append each char until next whitespace character
    if (is){
        do s.append(c);
        while(is.get(c) && !isspace(c));

        // if we read whitspace, then put it back on the stream
        if (is)
            is.unget();
    }

    return is;
}


// Concatenate nonmember operator overload function
Str& operator+ (const Str& first, const Str& second){
    Str ret = first;
    ret += second;
    return ret;
}
