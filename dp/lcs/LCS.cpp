#include<bits/stdc++.h>
using namespace std;


int LCS(char* X,char* Y,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(X[n-1]==Y[m-1])
    {
        return 1+ LCS(X,Y,n-1,m-1);
    }
    else{
        return max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m)); 
    }
}

//memoization
int lcs1(char* X,char* Y,int n,int m,vector<vector<int>>&dp)
{
    if(n==0 || m==0){
        return 0;
    }
    if (dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(X[n-1]==Y[m-1])
        return dp[n][m] = 1+lcs1(X,Y,n-1,m-1,dp);
    
    return dp[n][m] = max(lcs1(X,Y,n-1,m,dp) ,lcs1(X,Y,n,m-1,dp));
    
    
}
int main()
{
     char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
     
    int n= strlen(X);
    int m = strlen(Y);
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<lcs1(X,Y,n,m,dp)<<endl;
    cout<<LCS(X,Y,n,m);
}