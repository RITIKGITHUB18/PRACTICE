// ! in this question we are utilising both max heap and min heap

#include <bits/stdc++.h>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int element)
{

    if (maxi.size() == mini.size())
    {
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
    }

    else if (maxi.size() == mini.size() + 1)
    {
        if (element > median)
        {
            mini.push(element);
        }
        else
        {
            int temp = maxi.top();
            maxi.pop();
            mini.push(temp);
            maxi.push(element);
        }
        // size of both max heap and min heap become equal
        median = (mini.top() + maxi.top()) / 2.0;
    }
    else if (maxi.size() + 1 == mini.size())
    {
        if (element > median)
        {
            int temp = mini.top();
            mini.pop();
            maxi.push(temp);
            mini.push(element);
        }
        else
        {
            maxi.push(element);
        }
        median = (mini.top() + maxi.top()) / 2.0;
    }
}

int main()
{
    int arr[] = {12, 10, 8, 4, 2, 3, 15};
    int n = 7;

    double median = 0;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        solveForMedian(median, maxi, mini, element);
        cout << "Median Found: " << median << endl;
    }
    return 0;

    // ans should be
    // 12 -> 12
    // l0 12 -> 11
    // 8 10 12 -> 10
    // 4 8 10 12 ->9
    // 2 4 8 10 12 -> 8
    // 2 3 4 8 10 12 -> 6
    // 2 3 4 8 10 12 15 -> 8
}
