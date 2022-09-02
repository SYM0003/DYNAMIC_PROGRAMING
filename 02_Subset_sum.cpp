#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::max;
using std::vector;
bool subset_sum(int sum, vector<int> arr, int n)
{
    /*
    Time complexity of this function:O(n)+O(sum)+O(n*sum)=O(n*sum)
    space comlexity of this function:O(n+sum)+O(n)->why this one: O(n)?
    */
    bool t[n + 1][sum + 1];//->it must be of bool type, otherwise it won't give desired output
    
    /*
    <...>I can use optimla way for this block of code so i did same see m2
    for (int i = 0; i < n + 1; i++) //-->time comlexity of this loop O(sum*n)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            <....................................................>
            this code block is not required! why? you know? just try to find out
            if (j == 0 && i == 0)
            {
                return t[i][j] = true;
            }
            <....................................................>
            if (i == 0)
            {
                t[i][j] = false;
            }
            else if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }*/

    // m2 time complexity O(sum+n) it is batter than O(sum*n)
    for(int i=0;i<sum+1;i++) t[0][i]=false;
    for(int i=0;i<n+1;i++) t[i][0]=true;
            /*I was using sum instead of j
             if (arr[i - 1] <= sum)
            */
    for (int i = 1; i < n + 1; i++) //-->time comlexity of this loop O(sum*n)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                // this line of code is most important line in this code.
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                // <explanation>wel or operator gives true if any one argument is true
                // so it will give true if any one is true otherwise it will give false.
                // in other words it will give max of both arguments.

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
        // int  *val=new int;
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