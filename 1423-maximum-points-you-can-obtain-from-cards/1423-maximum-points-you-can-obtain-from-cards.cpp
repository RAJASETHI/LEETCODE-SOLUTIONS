class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+nums[i];
        }
        int mx=pre[k];
        int suff=0;
        for(int i=n-1;i>=n-k;i--)
        {
            suff+=nums[i];
            int cnt=n-i;
            mx=max(suff+pre[k-cnt],mx);
        }
        return mx;
    }
};