//count the number of subsets with given diffrence
#include<bits/stdc++.h>
using namespace std;
int dp[5][21];

int subsetsum(int arr[],int sum,int n)
{

       dp[0][0] = 1;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;


    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if (j>=arr[i-1])
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
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
    int arr[] = {1,1,3,2};
    int totalsum =0;
    int n=4;
    for (int i = 0; i < n; i++)
    {
        totalsum+=arr[i];
    }
    int diff=1;
    int sum1 = (diff + totalsum)/2;
    cout<<subsetsum(arr,sum1,n);
    
    
   
}