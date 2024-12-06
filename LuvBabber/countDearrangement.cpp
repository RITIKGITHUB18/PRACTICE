#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    // base condition
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    int count = (n - 1) * (solve(n - 1) + solve(n - 2));

    return count;
}

int main()
{
    int n = 4;
    int count = solve(n);
    cout << "count of dearrangement are: " << count << endl;
    return 0;
}
