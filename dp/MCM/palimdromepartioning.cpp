//minimum number of partioning to make all the string palimdromic
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}

int minipart(string s,int i,int j)
{
     if( i >= j || isPalindrome(s, i, j) )
      return 0;
   int ans = INT_MAX, count;
    for (int k=i;k<j;k++)
    {
       count = minipart(s,i,k) + minipart(s,k+1,j)+1;

        ans=min(count,ans);
        
    }
    

    return ans;
}


int main()
{
    string s; 
    s= "ababbbabbababa";
    int n = s.length();
    cout<<minipart(s,0,n-1);
}