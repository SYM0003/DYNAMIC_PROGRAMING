
// 0-1knapsack problem recursive solution.
/*
Time Complexity: O(N*W).
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W).
The use of 2-D array of size ‘N*W’.
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstring>
using std::cin;
// using std::m
using std::cout;
using std::endl;
using std::max;
using std::vector;
int knapsack(int n, int wt[], int val[], int W)
{
    int t[n + 1][W + 1];

    for (int j = 0; j < W + 1; j++) //-->capacity of the knapsack

    {
        for (int i = 0; i < n + 1; i++) //-->no of object.
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    /*//-->This block of code can replace the above nested for loop but i don't no why it
    is working properly?
    when i run it, it automatically stoped after taking input.//

    for (int j = 0; j < (W + 1); j++) //-->capacity of the knapsack
    {
        int i = 0;
        t[i][j] = 0;
    }
    for (int i = 0; n < (n + 1); n++) //-->capacity of the knapsack
    {
        int j = 0;
        t[i][j] = 0;
    }
    */

    // The below for loop is running for n+1 and W+1 time because of we also have to
    // consider the condition when there is no element or zero capacity of knapsack.
    for (int i = 1; i < n + 1; i++)

    {
        for (int j = 1; j < W + 1; j++)
        {

            if (wt[i - 1] <= j)
            {
                t[i][j] = max((val[i - 1] + t[i - 1][j - wt[i - 1]]), t[i - 1][j]);
            }

            else if (wt[i] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    /*
    //this block of code can replace the code from line no 25 to 73 it is more optimized.

    for (int i = 0; i < n + 1; i++)

    {
        for (int j = 0; j < W + 1; j++)
        {

            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }

            if (wt[i - 1] <= j)
            {
                t[i][j] = max((val[i - 1] + t[i - 1][j - wt[i - 1]]), t[i - 1][j]);
            }

            else if (wt[i] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    */

    return t[n][W];
}
int main()
{
    int n, W;
    cin >> n;
    cin >> W;
    /*
        int **t;
        t = new int *[n + 1]; //-->numbers of elements
        *t = new int[W + 1];
    */
    // memset(t, -1, sizeof(int));

    int wt[n];
    int val[n];
    for (int i = 0; i < n; i++)
    {
        cout << "object " << i << endl;
        cin >> wt[i] >> val[i];
    }

    int profit = knapsack(n, wt, val, W);
    cout << profit;
}