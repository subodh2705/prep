

#include<bits/stdc++.h>
using namespace std;
int dp[7][11];
//count the number of subset withgiven sum
//memoization
int countsubset(int arr[],int sum,int n)
{
    if(sum==0)
        return 1;
    if(n==0)
    {
        return 0;

    }
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    if(arr[n-1]<=sum)
    {
        return dp[n][sum]= countsubset(arr,sum,n-1) + countsubset(arr,sum-arr[n-1],n-1);
    }
    else
        return dp[n][sum]= countsubset(arr,sum,n-1);
}

//top - down
    int subsetcount(int arr[],int sum,int n)
    {
        dp[0][0] = 1;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;
        for (int i = 1; i < n+1;i++)
        {
            for (int j = 0; j < sum+1; j++)
            {
                if(j>=arr[i-1])
                {
                    dp[i][j]= dp[i-1][j] + dp[i-1][j-arr[i-1]]; 
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            
        }
        return dp[n][sum];
    }

int main()
{
    int arr[] = {2,3,5,8,10,5};
      memset(dp,-1,sizeof(dp));
    int sum =10;
    int n=6;
    cout<<subsetcount(arr,sum,n)<<endl;
    // cout<<countsubset(arr,sum,n)<<endl;
}