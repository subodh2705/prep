//rod cutting problem

#include<bits/stdc++.h>
using namespace std;

int rodcutting(int length[],int price[],int N,int x)
{
    int dp[x+1][N+1];

        for (int  i = 0; i < x+1; i++)
        {
            for (int j = 0; j < N+1; j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] =0;
                }
                else if(j>=length[i-1])
                {
                    dp[i][j] = max(dp[i-1][j],price[i-1]+dp[i][j-length[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
            
        }
        return dp[x][N];
}


int main()
{
    int x=4;
    // cin>>n;
    int lenght[]={1,2,3};
    int price[]={6,7,8};
    int N=6;
    // memset(dp,-1,sizeof(dp));
    // int dp[n+1][w+1];
    cout<<rodcutting(lenght,price,N,x)<<endl;
}