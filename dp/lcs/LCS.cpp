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

int main()
{
     char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
     
    int n= strlen(X);
    int m = strlen(Y);

    cout<<LCS(X,Y,n,m);
}