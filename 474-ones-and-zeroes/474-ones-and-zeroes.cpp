class Solution {
private:
    int rec(vector<vector<int>>&nums,int idx,int m,int n)
    {
        // cout<<dp[0][0][0]<<"\n";
        int sz=nums.size();
        if(idx==sz || (m==0 && n==0))return 0;
        if(dp[idx][m][n]!=-1)return dp[idx][m][n];
        int exclude=0,include=0,flag=0;
        if(nums[idx][0]<=m && nums[idx][1]<=n)
        {
            include=1+rec(nums,idx+1,m-nums[idx][0],n-nums[idx][1]);
        }
        exclude=rec(nums,idx+1,m,n);
        return dp[idx][m][n]=max(exclude,include);
    }
public:
    int dp[601][101][101]={};
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>nums;
        memset(dp,-1,sizeof(dp));
        for(auto s:strs)
        {
            int c1=0,c2=0;
            for(auto i:s)
            {
                c1+='1'-i;
                c2+=i-'0';
            }
            nums.push_back({c1,c2});
        }
        int ans=rec(nums,0,m,n);
        return ans;
    }
};