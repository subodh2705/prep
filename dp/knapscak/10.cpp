//coin change problem - count the number of occurances where we are a sum
#include<bits/stdc++.h>
using namespace std;



int coinchangecount(int coin[],int sum,int n)
{
    int dp[n+1][sum+1];

    dp[0][0]=1;
    for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;


    for (int i = 1; i <n+1 ; i++)
    {
       for (int j = 0; j < sum+1; j++)
       {
           
           if (j>=coin[i-1])
           {
               dp[i][j]=dp[i-1][j] + dp[i][j-coin[i-1]];
           }
           else
           {
               dp[i][j] = dp[i-1][j];
           }
           
       }
        
    }
    return dp[n][sum];
    
}
int main()
{
    int n=3;
    int coin[] = {1,2,3};
    int sum = 6;
    
    
    cout<<coinchangecount(coin,sum,n)<<endl;
}