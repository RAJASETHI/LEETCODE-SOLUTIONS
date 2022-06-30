class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sm=0;
        int n=nums.size();
        sort(begin(nums),end(nums));
        int cnt=0;
        if(n%2)
        {
            int val=nums[n/2];
            for(auto i:nums)cnt+=abs(i-val);
        }
        else
        {
            int val=(nums[(n-1)/2]+nums[n/2])/2;
            for(auto i:nums)cnt+=abs(i-val);
        }
        return cnt;
    }
};