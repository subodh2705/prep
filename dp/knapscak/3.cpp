//subset sum problem
#include <bits/stdc++.h>
using namespace std;

 int tab[100][100];


//recursion
bool subsum(int sub[],int sum,int n)
{
    if(sum==0)
    {
        return true;
    }
    if(n==0)
        return false;
     if(sub[n-1]>sum)
     {
     return subsum(sub,sum,n-1);

     }

    else{
        return subsum(sub,sum,n-1) || subsum(sub,sum-sub[n-1],n-1);
    }
    
}
//memoization
int subsetSum(int a[], int n, int sum)
{
     
    // If the sum is zero it means
    // we got our expected sum
    if (sum == 0)
        return 1;
         
    if (n <= 0)
        return 0;
   
    // If the value is not -1 it means it
    // already call the function
    // with the same value.
    // it will save our from the repetition.
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
   
    // if the value of a[n-1] is
    // greater than the sum.
    // we call for the next value
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else
    {
         
        // Here we do two calls because we
        // don't know which value is
        // full-fill our criteria
        // that's why we doing two calls
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
                       subsetSum(a, n - 1, sum - a[n - 1]);
    }
}
 
int main()
{
	int sub[] = { 3,7,8,11,14 };
    memset(tab, -1, sizeof(tab));
    int sum=11;
	int n=5;
	cout<< subsetSum(sub,sum,n)<<endl;
	
	return 0;
}
