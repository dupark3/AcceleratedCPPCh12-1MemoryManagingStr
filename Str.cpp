

#include <iostream>
#include <memory>
#include "Str.h"

void Str::create(){
    data = last = limit = 0;
    arraySize = 0;
}

void Str::create(size_t n, const char& c){
    arraySize = n;
    data = alloc.allocate(arraySize);
    last = limit = data + arraySize;
    std::uninitialized_fill(data, last, c);
}

void Str::create(const char* cp){
    arraySize = std::strlen(cp);
    data = alloc.allocate(arraySize);
    last = limit = data + arraySize;
    std::uninitialized_copy(cp, cp + arraySize, data);
}

void Str::uncreate(){
    if (data){
        clear();
        alloc.deallocate(data, limit - data);
    }
    data = last = limit = 0;
}

void clear(){
    if (data){
        char* it = last;
        while (it != data)
            alloc.destroy(--it);
    }
    last = data;
}

void append(const char& c){
    if (last == limit)
        grow();
    unchecked_append(c);
}

void grow(){
    size_t new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    char* new_data = alloc.allocate(new_size);
    char* new_last = uninitialized_copy(data, last, new_data);
    uncreate();
    data = new_data;
    last = new_last;
    limit = data + new_size;
}

void unchecked_append(const char& c){
    alloc.construct(last++, c);
}

// OUTPUT NONMEMBER FUNCTION
std::ostream& operator<<(std::ostream& os, const Str& s){
    for(Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}


// INPUT FRIEND FUNCTION (gains access to private member data for writing)
std::istream& operator>>(std::istream& is, Str& s){
    // obliterate existing values
    s.clear();

    // read nad discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ; // nothing to do, just test the condition

    // if something still to read, do so until next whitespace character
    if (is){
        for (size_t i = 0; i != )
        do {
            data =
        } while(is.get(c) && !isspace(c));

        // if we read whitspace, then put it back on the stream
        if (is)
            is.unget();
    }

    return is;
}


// CONCATENATE NONMEMBER FUNCTION
Str& operator+ (const Str& first, const Str& second){
    Str ret = first;
    ret += second;
    return ret;
}


