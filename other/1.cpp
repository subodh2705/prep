#include <iostream>
#include <vector>
using namespace std;
 bool isConsecutive(int A[], int i, int j, int min, int max){
     if(max-min!=j-i)
        return false;

    vector<bool> visited(j - i + 1);


    for (int k = i; k <= j; k++)
    {
        if (visited[A[k]-min])
        {
            return false;
        }
        visited[A[k]-min]=true;

        

    }


    return true;
    
 }


 int findMaxSubarray(int A[], int n){
     int min_val=0,max_val=0;
     int len =1;


     for (int i = 0; i < n; i++)
     {
         max_val=A[i];min_val=A[i];
         for (int j = i+1; j < n; j++)
         {
             min_val=min(min_val,A[j]);
             max_val=max(max_val,A[j]);

             if (isConsecutive(A,i,j,min_val,max_val))
             {
                 if (len < max_val - min_val + 1)
                {
                    len = max_val - min_val + 1;
        
                }
             }
             
         }
         
     }
     return len;
 }



int main()
{
    int A[] = {10,89, 5, 3, 1, 4, 2, 8, 7 };
    int n = sizeof(A) / sizeof(A[0]);
 
    cout<<findMaxSubarray(A, n);
 
    return 0;
}