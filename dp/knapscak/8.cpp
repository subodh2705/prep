//unbounded knapsack



#include<bits/stdc++.h>
using namespace std;
// const int n=4;
//  const int w=50;
 

int kp(int wt[],int val[], int w,int n)
{
    int dp[n+1][w+1];
        if(n==0 || w==0)
        {
            return 0;

        }
        if(dp[n][w]!=-1)
            return dp[n][w];
        if(w<wt[n-1])
        {
            return dp[n][w]= kp(wt,val,w,n-1);
        }
        
        else//  if(w>=wt[n-1])
        {
            return dp[n][w]= max( (val[n-1] + kp(wt,val,w-wt[n-1],n)) , kp(wt,val,w,n-1) );
        }
}
int kp1(int wt[],int val[],int W,int n){
    int dp[n+1][W+1];
    for (int i = 0; i < n+1 ;i++)
    {
     for (int j = 0; j < W+1; j++)
     {
            if (i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j]= max(val[i-1] + dp[i][j-wt[i-1]],dp[i-1][j]); 
            }
     }
        
    }
    return dp[n][W];    
}
int main()
{
    int n=4;
    // cin>>n;
    int wt[n]={3,5,1,4};
    int val[n]={5,2,1,4};
    int w=10;
    // memset(dp,-1,sizeof(dp));
    // int dp[n+1][w+1];
    cout<<kp1(wt,val,w,n)<<endl;
}