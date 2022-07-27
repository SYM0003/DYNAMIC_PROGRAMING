#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::max;
using std::vector;
bool subset_sum(int sum, vector<int> arr, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++) //-->time comlexity of this loop O(sum*n)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            /*
            this code block is not required! why? you know? just try to find out
            if (j == 0 && i == 0)
            {
                return t[i][j] = true;
            }

            */
            if (i == 0)
            {
                t[i][j] = false;
            }
            else if (j == 0)
            {
                t[i][j] = true;
            }

            /// below code is note sure.

            /*if (arr[i] == j)
            {
                t[i][j] = true;
            }*/

            /*I was using sum instead of j
             if (arr[i - 1] <= sum)
            */
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
    return t[n][sum];
}

int main(void)
{
    int n;
    int sum;

    vector<int> arr;
    cin >> sum;
    cin >> n;
    for (int i = 0; i < n; i++) //-->> complexity: of this loopO(n)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    bool result = subset_sum(sum, arr, n);

    if (result == true)
    {
        cout << "Subset is possible\n";
    }
    else
        cout << "Subset is not possible";

    return 0;
}