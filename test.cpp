#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::vector;
int subset_sum(vector<int> &arr, int n)
{
    // int n=arr.size();
    int sum = 0;
    vector<int>::iterator iter;
    iter = arr.begin();
    sum = accumulate(iter, iter + n, sum);
    // bool **t;
    // t = new bool *[n + 1];
    // *t = new bool[sum + 1];
    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));

    // bool t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }
    for (int i = 0; i < sum + 1; i++)
    {
        t[0][i] = false;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }

            if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // vector<int> s1(sum + 1);
    // for (int i = 0; i < sum / 2; i++)
    // {
    //     if (t[n][i] == true)
    //     {
    //         s1.push_back(i);
    //     }
    // }
    // int mn = INT_MAX;
    // for (int i = s1.size(); i >= 0; i--)
    // {
    //     mn = min(mn, sum - (2 * s1[i]));
    // }

    int mn = INT_MAX;
    for (int j = sum / 2; j >= 0; j--)
    {
        if (t[n][j] == true)
        {
            mn = sum - 2 * j;
            break;
        }
    }
    return mn;
}

int main(void)
{
    // test case:: n=4, arr={1,6,11,5},o/p::1
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) //-->> complexity: of this loopO(n)
    {
        int val;
        // int  *val=new int;
        cin >> val;
        arr.push_back(val);
    }

    int result = subset_sum(arr, n);

    cout << "The mimimum subset sum diffrece is :" << result;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>
// using std::cout;
// using namespace std;

// using std::vector;

// int main()
// {
//     vector<int> arr(4, 1);
//     vector<int>::iterator iter;
//     // cout << arr[0] << endl;
//     cout << *arr.begin() << endl;
//     iter = arr.begin();
//     int sum = 0;
//     sum = accumulate(iter, iter + 4, sum);
//     // int sum = accumulate(*iter, *iter + 4, sum);
//     cout << sum;
//     // cout << (*iter);
// }