#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int no_of_subset_with_given_diff(vector<int> arr, int diff, int n)
{
    /*s1(sum)=(diff+arr(sum))/2*/
    int arr_sum = 0;
    int s1_sum = 0;
    vector<int>::iterator iter;
    iter = arr.begin();
    arr_sum = accumulate(iter, iter + n, arr_sum);

    s1_sum = (diff + arr_sum) / 2;
    int next_n = n + 1;
    int next_s1_sum = s1_sum + 1;
    vector<vector<int>> t(next_n, vector<int>(next_s1_sum));
    for (int i = 0; i < next_s1_sum; i++)
        t[0][i] = 0;
    for (int i = 0; i < next_n; i++)
        t[i][0] = 1;

    for (int i = 1; i < next_n; i++)
    {
        for (int j = 1; j < next_s1_sum; j++)
        {
            int prev_index = i - 1;
            if (arr[prev_index] <= j)
            {
                t[i][j] = t[prev_index][j - arr[i - j]] + t[prev_index][j];
            }

            else
            {
                t[i][j] = t[prev_index][j];
            }
        }
    }
    return t[n][s1_sum];
}
int main()
{
    int n;    //->The numbers of elements in the array.
    int diff; //->given diffrence

    cin >> n;
    cin >> diff;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n];
    }

    cout << no_of_subset_with_given_diff(arr, diff, n);
}