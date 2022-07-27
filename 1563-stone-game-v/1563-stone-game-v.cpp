class Solution {
public:
    vector<vector<int>>dp;
    int f(int l,int r,vector<int>&stone)
    {
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        
        int sm=accumulate(stone.begin()+l,stone.begin()+r+1,0);
        int curr=0;
        int mx=0;
        for(int i=l;i<=r;i++)
        {
            curr+=stone[i];
            if(curr<sm-curr)
            {
                mx=max(mx,curr+f(l,i,stone));
            }
            if(curr==sm-curr)
            {
                mx=max(mx,curr+f(l,i,stone));
                mx=max(mx,curr+f(i+1,r,stone));
            }
            if(curr>sm-curr)
            {
                mx=max(mx,sm-curr+f(i+1,r,stone));
            }
        }
        return dp[l][r]=mx;
    }
    int stoneGameV(vector<int>& stone) {
        int n=stone.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return f(0,stone.size()-1,stone);
    }
};