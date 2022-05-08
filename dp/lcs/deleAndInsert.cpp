//count the minimum number of insertion and deletion 
//required to convert string a to b

#include<bits/stdc++.h>
using namespace std;
int dp[10][10];

void insertanddelete(char* X,char* Y,int n,int m)
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


    int x = dp[n][m];
    cout<<"insertion "<<m-x<<" deletion "<<n-x<<endl;
}

int main()
{
     char X[] = "SUB";
    char Y[] = "SUM";
     
    int n= strlen(X);
    int m = strlen(Y);
   
    insertanddelete(X,Y,n,m);

}