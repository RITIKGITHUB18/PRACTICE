#include <bits/stdc++.h>
using namespace std;

void printPermutation(string &str, int index)
{
    // base case
    if (index >= str.length())
    {
        cout << str << " ";
        return;
    }

    // processing

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);

        // Recursive call
        printPermutation(str, index + 1);

        // backtracking krr rhe hai issliye upar wale swap function ko nulify krne k liye humme phir se swap krna padega

        swap(str[index], str[j]);
    }
}

int main()
{
    string str = "abc";
    int index = 0;
    printPermutation(str, index);
    return 0;
}
