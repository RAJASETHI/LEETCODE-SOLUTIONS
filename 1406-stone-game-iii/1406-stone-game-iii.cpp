class Solution {
public:
    vector<int>dp;
    int f(int idx,vector<int>&stone)
    {
        if(idx>=stone.size())return 0;
        int sm=0,mn=INT_MIN;
        if(dp[idx]!=-1)return dp[idx];
        for(int i=idx;i<min(idx+3,(int)stone.size());i++)
        {
            sm+=stone[i];
            mn=max(mn,sm-f(i+1,stone));
        }
        return dp[idx]=mn;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        string res="Tie";
        int n=stoneValue.size();
        dp.resize(n,-1);
        int val=f(0,stoneValue);
        if(val>0)res="Alice";
        else if(val<0)res="Bob";
        return res;
    }
};