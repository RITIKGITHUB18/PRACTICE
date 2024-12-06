#include <bits/stdc++.h>
using namespace std;

bool checkRedundant(string &str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    operatorCount++;
                }
                st.pop();
            }

            // this pop is for like there is an opening bracket, so we pop it
            st.pop();

            if (operatorCount == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string str;
    cout << "Insert the string for checking if redundant bracket is present or not " << endl;
    cin >> str;
    bool ans = checkRedundant(str);

    if (ans == true)
    {
        cout << "Redundant bracket is present" << endl;
    }
    else
    {
        cout << "No redundant Bracket is present" << endl;
    }
    return 0;
}
