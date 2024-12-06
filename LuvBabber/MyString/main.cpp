#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;
int main()
{
    MyString s("Ritik is handsome");
    MyString t = "Kumar";

    cout << s << endl;
    cout << s.find("handsome") << endl;
    cout << t << endl;
    cout << t[0] << endl;
    return 0;
}
