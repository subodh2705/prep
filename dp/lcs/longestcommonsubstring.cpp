#include<bits/stdc++.h>
using namespace std;

int longsubstring(char *X,char *Y,int n,int m)
{
    int dp[n+1][m+1];
    int result=0;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
           if (i==0 || j==0)
            {
                dp[i][j]=0;
            }  
            else if(X[i-1]==Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1] +1; 
                result = max(result,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
        
    }
    
    return result;
   
    
}


int main()
{
  char X[] = "ABCDE";
  char Y[] = "ABGHI";

    int n= strlen(X);
    int m = strlen(Y);
    cout<<longsubstring(X,Y,n,m)<<endl;
}