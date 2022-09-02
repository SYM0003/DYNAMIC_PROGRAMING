// 0-1knapsack problem recursive solution.
/*
Time Complexity: O(N*W).
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W).
The use of 2-D array of size ‘N*W’.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;
/*
class object{
    int wt;
    int val;
    public:
    void setobj(int w,int val){wt=w;this->val=val;}
    //object(int w, int v):wt(w),val(v){}
};

class knapsack{
    int W;
    public:
    //knapsack(int w):W(w){}
    void setweight(int wt){W=wt;}
    void getweight(void){cout<<W;}
};*/

int knapsack(int n, int wt[], int val[], int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wt[n - 1] < W)
    {
        return (max(val[n - 1] + knapsack(n - 1, wt, val, W - wt[n - 1]), knapsack(n - 1, wt, val, W)));
    }

    if (wt[n - 1] > W)
    {
        return knapsack(n - 1, wt, val, W);
    }
}
int main()
{
    int n, W;
    cin >> n;
    cin >> W;
    // int *wt = new int[n];
    // int *val = new int[n];
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