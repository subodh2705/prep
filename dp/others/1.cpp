//find the minimum number of cost such that no two adjacent houses has same color
//https://www.geeksforgeeks.org/minimize-cost-of-painting-n-houses-such-that-adjacent-houses-have-different-colors/


#include <bits/stdc++.h>
using namespace std;
 
// Function to find the minimum cost of
// coloring the houses such that no two
// adjacent houses has the same color
int minCost(vector<vector<int> >& costs,
            int N)
{
    // Corner Case
   if (N == 0)
        return 0;
 
    // Auxiliary 2D dp array
    vector<vector<int> > dp(
        N+1, vector<int>(3, 0));


        dp[0][0]=costs[0][0];
        dp[0][1]=costs[0][1];

        dp[0][2]=costs[0][2];

        for (int i = 1; i < N; i++)
        {
            dp[i][0] = min(dp[i-1][1],dp[i-1][2])+costs[i][0];
            
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+costs[i][1];
                   
            dp[i][2]= min(dp[i-1][0],dp[i-1][1])+costs[i][2];

        }
        return min(dp[N-1 ][0],
                min(dp[N -1][1],
                    dp[N -1][2]));

}
int main()
{
    vector<vector<int> > costs{ { 14, 2, 11 },
                                { 11, 14, 5 },
                                { 14, 3, 10 } };
    int N = costs.size();
 
    // Function Call
    cout <<minCost(costs, N);
 
    return 0;
}