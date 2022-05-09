#include<bits/stdc++.h>
using namespace std;

int dp[10][10];

void superseq(char* X,char* Y,int n,int m)
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


    int i=m,j=n;
    string s=" ";
    while (i>0 && j>0)
    {
        if (X[i-1]==Y[j-1])
        {
            s.push_back(X[i-1]);
            i--;j--;
        }
        else 
        {
            if(dp[i-1][j]<dp[i][j-1])
            {
                s.push_back(Y[j-1]);
                j--;
            }
            else
            {
                s.push_back(X[i-1]);
                i--;
            }
            
        }
    }
    
    while (i>0)
    {
        s.push_back(X[i-1]);
        i--;
    }
    while (j>0)
    {
        s.push_back(Y[j-1]);
        j--;
    }
     reverse(s.begin(),s.end());
    cout<<s;
}




int main()
{
     char X[] = "ABC";
    char Y[] = "ABD";
     
    int n= strlen(X);
    int m = strlen(Y);
   
    superseq(X,Y,n,m);

}