/*
  for(i=0->n-1)  
    for(j=0->i-1)
    if(nums[j]<nums[i])
        dp[i]=max(dp[j]+1,dp[i]) 
    Time Complexity:O(N^2) Space:O(N)
    
    Optimising:
        vector<int>dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        for(i=0->n-1)
        {
            auto itr=upper_bound(dp.begin(),dp.end(),nums[i]);
        }
        
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        int mx_size=0;
        for(int i=0;i<n;i++)
        {
            int idx=upper_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(dp[idx-1]!=nums[i])
            {
                dp[idx]=nums[i];
                mx_size=max(mx_size,idx);
            }
        }
        return mx_size;
    }
};