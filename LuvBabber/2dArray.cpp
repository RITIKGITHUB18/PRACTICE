#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[2][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // for (int i = 0; i < col; i++)
    // {
    //     for (int j = 0; j < row; j++)
    //         cout << arr[j][i] << " ";

    //     cout << endl;
    // }
}

bool findTarget(int arr[3][3], int row, int col)
{
    int key;
    cout << "Enter the Value of key" << endl;
    cin >> key;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == key)
            {
                return true;
            }
        }
    }
    return false;
}

int findMaxElem(int arr[3][3], int row, int col)
{
    int maxElem = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (maxElem <= arr[i][j])
            {
                maxElem = arr[i][j];
            }
        }
    }
    return maxElem;
}

void rowWiseSum(int arr[3][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {

            sum = sum + arr[i][j];
        }
        cout << "sum of row : " << i << " is " << sum << endl;
    }
}
void diagonalSum(int arr[3][3], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {

        // for (int j = 0; j < col; j++)
        // {
        //     if (i == j)
        //         sum = sum + arr[i][j];
        // }

        // or

        sum = sum + arr[i][i];
    }
    cout << "sum of diagonal : "
         << " is " << sum << endl;
}

void transpose2dArray(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j > i)
            {
                swap(arr[i][j], arr[j][i]);
            }
            // or  we will start from j = i then also same result will be obtained.
        }
    }
    printArray(arr, row, col);
}

int main()
{

    // ! 2dArray Initialisation Technique conversion- C*i+j at least pass column value
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    int row = 2;
    int col = 3;
    printArray(arr, row, col);

    cout << "Enter the value in Array1" << endl;
    ;
    int arr1[3][3];
    int row1 = 3;
    int col1 = 3;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    printArray(arr1, row1, col1);
    bool value = findTarget(arr1, row1, col1);
    cout << value << endl;

    int maxElement = findMaxElem(arr1, row1, col1);
    cout << "Maximum element is : " << maxElement << endl;

    cout << "Row wise sum in a 2d Array is :" << endl;
    rowWiseSum(arr1, row1, col1);

    diagonalSum(arr1, row1, col1);
    cout << "Tranpose of an Array :" << endl;
    transpose2dArray(arr1, row1, col1);

    // ! 2d vector

    // ? creation of 2d vector
    vector<vector<int>> arr(5, vector<int>(10, 0));

    // for size of row -> arr.size()
    for (int i = 0; i < arr.size(); i++)
    {
        //  for size of col-> arr[i].size() it means size of i^th rows
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //! jagged 2d vector
    // ? creation of jagged array

    vector<vector<int>> brr;

    vector<int> vec1(10, 0);
    vector<int> vec2(5, 1);
    vector<int> vec3(3, -1);
    vector<int> vec4(4, 2);
    vector<int> vec5(8, 3);

    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);

    for (int i = 0; i < brr.size(); i++)
    {
        //  for size of col-> arr[i].size() it means size of i^th rows
        for (int j = 0; j < brr[i].size(); j++)
        {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}