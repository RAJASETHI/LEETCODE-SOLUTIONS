class Solution {
public:
    int f(int r,int sm,vector<set<int>>& mat, int target,vector<vector<int>>&dp)
    {
        if(r==mat.size())return abs(sm-target);
        int mn=INT_MAX;
        if(dp[r][sm]!=-1)return dp[r][sm];
        for(auto x:mat[r])
        {
            mn=min(mn,f(r+1,sm+x,mat,target,dp));
            if(mn==0 || sm+x>target)break;
        }
        return dp[r][sm]=mn;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<vector<int>>dp(mat.size(),vector<int>(5000,-1));
         vector<set<int>> m;
        for (auto &row : mat)
            m.push_back(set<int>(begin(row), end(row)));
        return f(0,0,m,target,dp);
    }
};