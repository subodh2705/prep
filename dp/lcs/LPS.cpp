//Longest palimdromic subsequence


#include<bits/stdc++.h>
using namespace std;
int dp[10][10];
int LCS(string X,string Y,int n,int m)
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
int main()
{
    string a = "AGBCBA";
    string x =a;
     reverse(x.begin(),x.end());
     string b=x;
     
    int n= 6;
    int m = 6;
   
    cout<<LCS(a,b,n,m);

}