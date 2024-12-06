// In header file we generally do the declaration part.

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString
{
private:
    char *data; // pointer to char array data
    int length; // size of my string

public:
    // Default ctor
    MyString();

    // Parameterised constructor
    MyString(const char *str);

    // copy ctor
    MyString(const MyString &other);

    // Dtor
    ~MyString();

    int size() const;

    bool empty() const;

    const char *c_str() const;

    char operator[](int index);

    // find substring
    int find(const MyString &substr) const;

    // overload insertion operator << for easy output
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif