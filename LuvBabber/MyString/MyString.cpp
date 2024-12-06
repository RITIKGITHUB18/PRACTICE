#include "MyString.h"
#include <cstring> //strcopy

// Definitions of all the functions declared in MyString.h

// This is our defined default Ctor
MyString::MyString()
{
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

// This is our defined paramaterised ctor
MyString::MyString(const char *str)
{
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data, str);
}

// This is our defined copyctor
MyString::MyString(const MyString &other)
{
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);
}

// This is my defined destructor
MyString::~MyString()
{
    delete[] data;
}

// This is my Defined size Method
int MyString::size() const
{
    return length;
}

bool MyString::empty() const
{
    return length == 0 ? true : false;
}

const char *MyString::c_str() const
{
    return data;
}

std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.c_str(); // os is output stream
    return os;
}

char MyString::operator[](int index)
{
    if (index >= length)
    {
        return '\0';
    }
    return data[index];
}

int MyString::find(const MyString &substr) const
{
    if (substr.length > length)
    { // substr is the string that we want to find and length is the whole/parent string
        return -1;
    }

    // searching of substring in the parent string
    for (int i = 0; i <= length - substr.length; i++)
    {
        int j;
        for (j = 0; j < substr.length; j++)
        {
            if (data[i + j] != substr.data[j])
            {
                break;
            }
        }
        if (j == substr.length)
        {
            return i;
        }
    }
    return -1;
}
