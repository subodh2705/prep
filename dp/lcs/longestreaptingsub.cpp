#include<bits/stdc++.h>
using namespace std;

//longest reapiting subsequence in a string
int LCS(char* X,char* Y,int n,int m){
    int dp[n+1][m+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(X[i-1]==Y[j-1] && i!=j)
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

    }
    return dp[n][m];
    
}

int main()
{
     char X[] = "AAEBB";
    char Y[] = "AAEBB";
     
    int n= strlen(X);
    int m = strlen(Y);
    
    cout<<LCS(X,Y,n,m);

}