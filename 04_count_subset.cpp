#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::max;
using std::vector;
int subset_sum_count(int sum, vector<int> arr, int n)
{
    // int t[n + 1][sum + 1];
    vector<vector<int>> t(n + 1, vector<int>(sum + 1));
    for (int i = 0; i < sum + 1; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }
    for (int i = 1; i < n + 1; i++) //-->time comlexity of this loop O(sum*n)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {

                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }

            if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main(void)
{
    int n; //->The total numbers of elements
    int sum;

    vector<int> arr;
    cin >> n;
    cin >> sum;
    for (int i = 0; i < n; i++) //-->> complexity: of this loopO(n)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    int result = subset_sum_count(sum, arr, n);

    cout << result;
    return 0;
}