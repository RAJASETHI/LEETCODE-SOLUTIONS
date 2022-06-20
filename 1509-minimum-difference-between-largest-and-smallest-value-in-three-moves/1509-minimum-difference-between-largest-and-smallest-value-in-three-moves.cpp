class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4)return 0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>dd={{0,-3},{1,-2},{2,-1},{3,0}};
        int mn=INT_MAX;
        for(auto x:dd)
        {
            mn=min(mn,nums[n-1+x[1]]-nums[x[0]]);
        }
        return mn;
    }
};