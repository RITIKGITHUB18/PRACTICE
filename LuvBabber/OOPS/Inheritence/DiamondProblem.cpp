#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    void walk()
    {
        cout << "Walking..." << endl;
    }
};

class Teacher : virtual public Person
{
public:
    void teaching()
    {
        cout << "Teacher is teaching..." << endl;
    }
};

class Researcher : virtual public Person
{
public:
    void researching()
    {
        cout << "Researcher doing Research..." << endl;
    }
};

class Professor : public Teacher, public Researcher
{
public:
    void professors()
    {
        cout << "Making Bored..." << endl;
    }
};

//     Person
//   /         \
// Teacher     Researcher [ here walking is inherited differently to both teacher and researcher class during the compile time
//     \       / but after using the virutal keyword inheritence is carried out at runtime and produce the single copy of method at runtime].
//     Professor
int main()
{
    Professor p;
    p.walk();
    return 0;
}
