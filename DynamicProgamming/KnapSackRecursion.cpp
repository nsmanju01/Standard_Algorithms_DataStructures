#include <bits/stdc++.h>

using namespace std;

int KnapSack(vector<int> val, vector<int> wt,int W, int n)
{
    // if the number of elements of equal to 0 or the max possible wt of KnapSack is 0 
    if(n == 0 || W == 0)
        return 0;
    // if the nth element is greater than W at that instant then skip that element.
    if(wt[n-1] > W)
        return KnapSack(val,wt,W,n-1);
        
    // recurse over all the elements from end with/without including that element in the current run.
    
    return max(KnapSack(val,wt,W,n-1),val[n-1] + KnapSack(val,wt,W-wt[n-1],n-1));
}

int main()
{
	vector<int>val = {60, 100, 120};
	vector<int>wt = {10, 20, 30};
	int W = 50;
	cout << KnapSack(val,wt,W,val.size());
	return 0;
}
