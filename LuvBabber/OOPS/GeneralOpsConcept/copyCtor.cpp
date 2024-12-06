#include <bits/stdc++.h>
using namespace std;

class student
{

public:
    string name;
    int rollNo;

    student(string _name, int _roll)
    {
        name = _name;
        rollNo = _roll;
    }

    student() {}
    // copy Ctor
    student(const student &srcObj)
    {
        name = srcObj.name;
        rollNo = srcObj.rollNo;
    }
};

int main()
{
    student s1("ritik", 4441);
    student s2;
    student s3(s1);

    return 0;
}
