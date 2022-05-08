#include<bits/stdc++.h>
using namespace std;

int dp[10][10];

void printlcs(char* X,char* Y,int n,int m)
{
 for (int i = 0; i < n+1; i++)
    {
        for (int j= 0; j < m+1; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(X[i-1]==Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1] );
            }
        }
    }



    int index = dp[n][m];
    char s[index+1];
    s[index]='\0';

    int i = n ,j=m;
   while (i>0 && j>0)
   {
           if(X[i-1]==Y[j-1]) 
           {
              s[index-1] = X[i-1];
              i--;j--;index--;
           } 
           else if(dp[i-1][j]>dp[i][j-1])
           {
               i--;
           }
           else
            j--;
   }
   
    cout<<s;
    
}


int main()
{
     char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
     
    int n= strlen(X);
    int m = strlen(Y);
   
    printlcs(X,Y,n,m);

}