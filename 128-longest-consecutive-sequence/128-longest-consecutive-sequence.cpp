class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int mx=0;
        for(auto i:nums)
        {
            int cnt=0;
            if(mp[i-1]==0)
            {
                int idx=i;
                while(mp[idx])
                {
                    cnt++;
                    idx++;
                }
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};