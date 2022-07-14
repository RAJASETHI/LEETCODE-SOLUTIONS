class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>a=nums;
        vector<int>res;
        sort(nums.begin(),nums.end(),greater<int>());
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
        }
        for(auto i:a)
        {
            if(mp[i])
            {
                res.push_back(i);
                mp[i]--;
            }
        }
        return res;
    }
};