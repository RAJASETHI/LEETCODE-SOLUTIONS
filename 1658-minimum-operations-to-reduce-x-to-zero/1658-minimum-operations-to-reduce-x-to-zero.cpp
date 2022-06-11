class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=0;
        int n=nums.size();
        vector<int>pre(n+1,0);
        unordered_map<int,vector<int>>mp;
        int mn=INT_MAX;
        mp[0]={0};
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+nums[i];
            mp[pre[i+1]].push_back(i+1);
            if(pre[i+1]==x)mn=min(mn,i+1);
        }
        int suf=0;
        for(int i=n-1;i>=0;i--)
        {
            suf+=nums[i];
            mp[pre[i+1]].pop_back();
            if(mp[x-suf].size())
            {
                mn=min(mn,n-i+mp[x-suf][0]);
            }
        }
        return (mn==INT_MAX?-1:mn);
    }
};