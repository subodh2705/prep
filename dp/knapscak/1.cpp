//0-1 knapsack

#include<bits/stdc++.h>
using namespace std;
const int n=4;
 const int w=50;
 int dp[n+1][w+1];

int kp(int wt[],int val[], int w,int n)
{
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
            return dp[n][w]= max( (val[n-1] + kp(wt,val,w-wt[n-1],n-1)) , kp(wt,val,w,n-1) );
        }
}

int main()
{
    int n=4;
    // cin>>n;
    int wt[n]={3,5,1,4};
    int val[n]={5,2,1,4};
    int w=10;
    memset(dp,-1,sizeof(dp));
    // int dp[n+1][w+1];
    cout<<kp(wt,val,w,n)<<endl;
}