class Solution {
public:
    vector<int>dp;
    bool f(int idx,vector<int>&vis,vector<int>& arr)
    {
        if(idx>=arr.size() || idx<0 || vis[idx]==1)return false;
        vis[idx]=1;
        if(arr[idx]==0)return true;
        if(dp[idx]!=-1)return dp[idx];
        bool ans=f(idx+arr[idx],vis,arr) || f(idx-arr[idx],vis,arr);
        vis[idx]=0;
        return dp[idx]=ans;
    }
    bool canReach(vector<int>& arr, int start) {
        dp.resize(arr.size(),-1);
        vector<int>vis(arr.size(),0);
        return f(start,vis,arr);
    }
};