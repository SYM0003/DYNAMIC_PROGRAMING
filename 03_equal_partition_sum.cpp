#include <iostream>
#include <vector>
#include <numeric>
using std::accumulate;
using std::cin;
using std::cout;
using std::vector;
bool equal_sum_partition_sum(int n, vector<int> arr)
{

    /*
    The biggest power of c++ is STL
    I don't need algo for finding the sum of array
    I can use accumulate() method which can do the same work.
    It is available in numeric library
    It takes three argumet as below:-
    stating pointer
    ending pointer
    target variable

    */
    vector<int> ::iterator iter1,iter2;
    iter1=arr.begin();
    int sum=0;
    sum = accumulate(iter1,iter1+n, sum);
    // sum = accumulate(arr,arr+n, sum);
    // cout << sum;
    if (sum % 2 != 0)
    {
        return false;
    }

    if (sum % 2 == 0)
    {
        sum = sum / 2;
        bool t[n + 1][sum + 1];

        for(int i=0;i<sum+1;i++) t[0][i]=false;
        for(int i=0;i<n+1;i++) t[i][0]=true;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                // this is the main code block of whole code.
                if (arr[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                }

                else if (arr[i - 1] > j)
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
}
int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    bool result = equal_sum_partition_sum(n, arr);
    if (result==true)
    {
        cout << "Equal sum partion possible\n";
    }
    else
    {
        cout << "Equal sum partion not possible";
    }
    return 0;
}