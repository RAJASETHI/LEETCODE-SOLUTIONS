class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        for(auto i:nums)
        {
            int idx=upper_bound(begin(dp),end(dp),i)-dp.begin();
            dp[idx]=min(dp[idx],i);
        }
        if(dp[n-1]!=INT_MAX)return true;
        return false;
    }
};