#include <cstring>
#include <sstream>
#include "MyString.h"

using namespace Assignment06;

// Default Constructor
MyString::MyString() {
    this->initialize_Empty();
}

// Constructor with c-string param
MyString::MyString(const char str[]) {
    if (strlen(str) == 0) {
        this->initialize_Empty();
    } else {
        occupied = strlen(str);
        capacity = occupied + 1;
        sequence = new char[capacity];
        strcpy(sequence, str);
    }
}

// Constructor with cpp-string param
MyString::MyString(const std::string str) {
    if (strlen(str.c_str()) == 0) {
        this->initialize_Empty();
    } else {
        occupied = strlen(str.c_str());
        capacity = occupied + 1;
        sequence = new char[capacity];
        strcpy(sequence, str.c_str());
    }
}

// Copy Constructor.
MyString::MyString(const MyString &source) {

    occupied = source.occupied;
    capacity = source.capacity;
    sequence = new char[capacity];

    for (size_t i = 0; i < occupied; ++i) {
        sequence[i] = source.sequence[i];
    }
}

// Destructor
MyString::~MyString() {
    delete[] sequence;
}

// operator+= overloading with MyString obj
MyString &MyString::operator+=(const MyString &addend) {

    capacity += addend.capacity;
    occupied += addend.occupied;

    char *temp = new char[capacity];
    strcpy(temp, sequence);

    delete[]sequence;
    sequence = temp;
    strcat(sequence, addend.sequence);

    return *this;
}

// operator+= overloading with c-string
MyString &MyString::operator+=(const char addend[]) {
    occupied += strlen(addend);
    capacity += strlen(addend);

    char *temp = new char[capacity];
    strcpy(temp, sequence);

    delete[]sequence;
    sequence = temp;
    strcat(sequence, addend);

    return *this;
}

// operator+= overloading with single char
MyString &MyString::operator+=(char addend) {
    capacity += 1;

    char *temp = new char[capacity];
    strcpy(temp, sequence);

    delete[]sequence;

    sequence = temp;
    sequence[occupied] = addend;

    occupied += 1;
    return *this;
}

// operator= overloading
MyString &MyString::operator=(const MyString &source) {
    occupied = source.occupied;
    capacity = source.capacity;
    sequence = new char[capacity];
    strcpy(sequence, source.sequence);
    return *this;
}

// const overloading operator[]
const char &MyString::operator[](size_t position) const {
    if ((position >= 0) && (position < occupied)) {
        return sequence[position];
    } else {
        throw std::out_of_range("ILLEGAL OPERATION");
    }
}

// overloading operator[]
char &MyString::operator[](size_t position) {
    if ((position >= 0) && (position < occupied)) {
        return sequence[position];
    } else {
        throw std::out_of_range("ILLEGAL OPERATION");
    }
}

// Swapping two MyString Objs
void MyString::swap(MyString &source) {

    MyString temp = *this;

    *this = source;
    source = temp;
}

// Global Function, Overloading the operator+ for two MyString objects
MyString Assignment06::operator+(const MyString &s1, const MyString &s2) {

    MyString result;
    result += s1;
    result += s2;
    return result;
}

// Global Function, Overloading the operator+ for MyString object with C-string.
MyString Assignment06::operator+(const MyString &s1, const char *s2) {

    MyString result;
    result += s1;
    result += s2;
    return result;
}

// Global Function, Overloading the operator+ for C-string with MyString object.
MyString Assignment06::operator+(const char *s1, const MyString &s2) {

    MyString result;
    result += s1;
    result += s2;
    return result;
}

namespace Assignment06 {

    // Global Function, operator==
    bool operator==(const MyString &s1, const MyString &s2) {
        return ((s1.occupied == s2.occupied) && (*s1.sequence == *s2.sequence));
    }

    // Global Function, operator!=
    bool operator!=(const MyString &s1, const MyString &s2) {
        return !operator==(s1, s2);
    }

    // Global Function, operator>=
    bool operator>=(const MyString &s1, const MyString &s2) {
        return strcmp(s1.sequence, s2.sequence) >= 0;
    }

    // Global Function, operator<=
    bool operator<=(const MyString &s1, const MyString &s2) {
        return strcmp(s1.sequence, s2.sequence) <= 0;
    }

    // Global Function, operator>
    bool operator>(const MyString &s1, const MyString &s2) {
        return strcmp(s1.sequence, s2.sequence) > 0;
    }

    // Global Function, operator<
    bool operator<(const MyString &s1, const MyString &s2) {
        return strcmp(s1.sequence, s2.sequence) < 0;
    }

    // Global Function, operator<<
    std::ostream &operator<<(std::ostream &outs, const MyString &source) {
        for (size_t i = 0; i < source.occupied; ++i) {
            outs << source.sequence[i];
        }
        return outs;
    }

    // Initialize Empty object
    void MyString::initialize_Empty() {
        occupied = 0;
        capacity = 1;
        sequence = new char[capacity]{'\0'};
    }

    // Global Function, operator>>
    std::istream &operator>>(std::istream &ins, MyString &target) {
        std::string str;
        ins >> str;
        char temp[str.length() + 1];
        strcpy(temp, str.c_str());
        target += temp;
        return ins;
    }
}

