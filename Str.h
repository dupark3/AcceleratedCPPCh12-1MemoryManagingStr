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

    // CONSTRUCTORS AND DESTRUCTOR
    Str() { create(); }
    explicit Str(size_t n, const char& c = char()) { create(n, c); }
    Str(const char* cp) { create(cp); }
    template <class In> Str(In b, In e) { create(b, e); }
    ~Str() { uncreate(); }

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
    size_t size() { return arraySize; }
    const size_t size() const { return arraySize; }
    char* begin() { return data; }
    const char* begin() const { return data; }
    char* end() { return last; }
    const char* end() const { return last; }

    void clear();

    void append(const char*);
    void append(const Str&);
    void append(const char&);

private:
    char* data;
    char* last;
    char* limit;
    size_t arraySize;
    std::allocator<char> alloc;

    void create();
    void create(size_t, const char&);
    void create(const char*);
    template <class In> void create(In, In);
    void uncreate();
    void grow();
    void unchecked_append(const char&);
};

template <class In>
void Str::create (In b, In e){
    data = alloc.allocate(e - b);
    last = limit = std::copy(b, e, data);
}

// OUTPUT NONMEMBER FUNCTION
std::ostream& operator<<(std::ostream&, const Str&);

// CONCATENATE NONMEMBER FUNCTION
Str& operator+ (const Str&, const Str& );

#endif // GUARD_Str_h
