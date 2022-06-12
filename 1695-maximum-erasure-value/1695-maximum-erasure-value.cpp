class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int l=0,r=0;
        int sm=0;
        int mx=INT_MIN;
        while(r<n)
        {
            if(mp.find(nums[r])==mp.end() || mp[nums[r]]==-1)
            {
                mp[nums[r]]=r;
                sm+=nums[r];
            }
            else
            {
                while(l<=mp[nums[r]])
                {
                    sm-=nums[l];
                    mp[nums[l]]=-1;
                    l++;
                }
                sm+=nums[r];
                mp[nums[r]]=r;
            }
            if(mx<sm)
            {
                
                // cout<<sm<<" ";
                mx=sm;
            }
            r++;
        }
        return mx;
    }
};