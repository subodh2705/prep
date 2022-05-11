#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> MI( vector<vector<int>>&v)
{

    vector<vector<int>> MI;
    if (v.size()==0)
    {
        return MI; 
    }
    
    vector<int> temp=v[0];

    for(auto it:v)
    {
        if (it[0]<=temp[1])
        {
            temp[1] = max(it[1],temp[1]);
        }
        else{
            MI.push_back(temp);
            temp =it;
        }
    }
    MI.push_back(temp);
    return MI;
}

int main()
{
  vector<vector<int>>v ={{1,3},{2,6},{8,10},{15,18}};
   MI(v);

}