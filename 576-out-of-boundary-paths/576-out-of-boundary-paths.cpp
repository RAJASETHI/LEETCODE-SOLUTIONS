class Solution {
public:
    int mod=pow(10,9)+7;
    vector<vector<int>>dd={{-1,0},{1,0},{0,1},{0,-1}};
    int f(vector<int>pos,vector<int>&sz,int mxMove,vector<vector<vector<int>>>&dp)
    {
        if(pos[0]>=sz[0] || pos[1]>=sz[1] || pos[0]<0 || pos[1]<0)return 1;
        if(mxMove<=0)return 0;
        if(dp[pos[0]][pos[1]][mxMove]!=-1)return dp[pos[0]][pos[1]][mxMove];
        int ans=0;
        for(auto i:dd)
        {
                int t_x=i[0]+pos[0],t_y=i[1]+pos[1];
                ans=(ans+f({t_x,t_y},sz,mxMove-1,dp))%mod;
        }
        return dp[pos[0]][pos[1]][mxMove]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<int>sz={m,n};
        return f({startRow,startColumn},sz,maxMove,dp);
    }
};