#include <bits/stdc++.h>
using namespace std;

void findSubSequence(string str, string output, int index)
{
    // base case
    if (index >= str.size())
    {
        cout << "->" << output << endl;
        return;
    }

    char ch = str[index];

    // exclude -> exclude phele likhenge ni toh output string modify ho jayegi

    findSubSequence(str, output, index + 1);

    // include
    output.push_back(ch);
    findSubSequence(str, output, index + 1);
}

int main()
{
    string str = "abc";
    string output = "";
    int index = 0;
    // int size=3;

    findSubSequence(str, output, index);

    return 0;
}
