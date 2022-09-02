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

vector<vector<bool>> subset_sum(vector<int> &arr, int n, int sum)
{
    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));
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
    return t;
}
int mndif(int sum, int n, vector<vector<bool>> t)
{
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
int min_subset_sum_diff(vector<int> &arr, int n)
{
    int sum = 0;
    vector<int>::iterator iter;
    iter = arr.begin();
    sum = accumulate(iter, iter + n, sum);
    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));
    t = subset_sum(arr, n, sum);
    return mndif(sum, n, t);
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
        cin >> val;
        arr.push_back(val);
    }
    int result = min_subset_sum_diff(arr, n);
    cout << "The mimimum subset sum diffrece is :" << result;
    return 0;
}
