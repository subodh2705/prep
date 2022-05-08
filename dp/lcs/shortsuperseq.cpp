#include<bits/stdc++.h>
using namespace std;

int dp[10][10];

int lcs(char* X,char* Y,int n,int m)
{
    for (int i = 0; i < n+1; i++)
    {
        for (int  j = 0; j < m+1; j++)
        {
            if (i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(X[i-1]==Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
    }
    return dp[n][m];
}
int superseq(char* X,char* Y,int n,int m)
{
    int lcs1 = lcs(X,Y,n,m);
     
     return m+n-lcs1;

}



int main()
{
     char X[] = "AGGTAB";
    char Y[] = "AXTXAYB";
     
    int n= strlen(X);
    int m = strlen(Y);
   
    cout<<superseq(X,Y,n,m);

}