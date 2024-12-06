#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int x = 5; // initialization can be done, but we can't re-assign a value

    //! const with pointer

    int const *a = new int(2); // const data, non-const pointer;
    cout << *a << endl;
    // *a = 20; can't change the data of pointer
    // delete a;
    int b = 5;
    a = &b; // pointer itself can be reassigned.
    cout << *a << endl;

    // ! const pointer, but non const data
    int *const c = new int(2);
    cout << *c << endl;
    *c = 20; // chal jayega
    cout << *c << endl;
    int b = 50;
    // c= &b; nhi chalega, const pointer hai isliye

    // !Const Pointer and const data
    // const int * const d = new int(10);
    // cout<<*d<<endl;
    // *d = 50; None of it will work as both the pointer and its content is constant
    // int e = 100;
    // d = &e;

    return 0;
}

const int *const d = new int(2);