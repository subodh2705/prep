//matrix chain multiplication
#include <bits/stdc++.h>
using namespace std;


int  MCM(int arr[],int i,int j)
{
    if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;
    
    for ( k = i; k < j; k++)
    {
         count = MCM(arr,i,k) + MCM(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
       	if (count < min)
			min = count;
        
    }
    
    return min;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n =5;
    cout<<MCM(arr,1, n-1);
}