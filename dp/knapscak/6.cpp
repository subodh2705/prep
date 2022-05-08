//subset sum with minimum diffrence
//https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
#include<bits/stdc++.h>
using namespace std;
bool subset[5][21];
// bool subset[n + 1][sum + 1];
void helper(int set[],int sum,int n)
{



	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty,
	// then answer is false
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}
    
    
}

int subsetsummindiff(int sum,int n)
{
    int mn=-1;
   for (int i = 0; i < sum/2; i++)
   {
       if (subset[n-1][i]==true)
       {
           mn = (sum-(2*i));
       }
       
   }
   return mn;
   
}

int main()
{
    int arr[] = {3,4,6,7};
    //   memset(d,p,-1,sizeof(dp));
    
    int n=4;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    
    helper(arr,sum,n);
    cout<<subsetsummindiff( sum, n)<<endl;

    // cout<<countsubset(arr,sum,n)<<endl;
}