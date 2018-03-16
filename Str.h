#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <algorithm> // copy
#include <cstddef> // size_t
#include <cstring> // strlen
#include <iostream>
#include <iterator> // back_inserter
#include <memory> // allocator


class Str{
public:
typedef size_t size_type;

    // CONSTRUCTORS
    Str() { create(); }
    explicit Str(size_t n, const char& c = char()) { create(n, c); }
    Str(const char* cp) { create(cp); }
    template <class In> Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }
    ~Str() { uncreate() }

    // OPERATOR OVERLOADS
    char& operator[](size_t i) { return data[i]; }
    const char& operator[](size_t i) const { return data[i]; }
    friend std::istream& operator>>(std::istream&, Str&);
    Str& operator+=(const Str& rvalue) {
        char* temp = alloc.allocate(arraySize + rvalue.size());
        std::copy(data, data + arraySize, temp);
        data = temp;
        std::copy(rvalue.begin(), rvalue.end(), data + arraySize);
        return *this;
    }

    // MEMBER FUNCTIONS
    size_t size() { return size(); }
    const size_t size() const { return size(); }
    char* begin() { return data; }
    const char* begin() const { return data; }
    char* end() { return data + arraySize; }
    const char* end() const { return data + arraySize; }

    void clear();

    void append(const char&);

    }

private:
    char* data;
    char* last;
    char* limit;
    size_t arraySize;
    std::allocator<char> alloc;

    void create();
    void create(size_t, const char&);
    void create(const char*);
    void uncreate();
    void grow();
    void unchecked_appened(const char&);
};

// OUTPUT NONMEMBER FUNCTION
std::ostream& operator<<(std::ostream&, const Str&);

// CONCATENATE NONMEMBER FUNCTION
Str& operator+ (const Str&, const Str& );

#endif // GUARD_Str_h
