class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<=nums.size()-3;i++)
        {
            if(nums[i+0]<nums[i+1]+nums[i+2])return (nums[i+0]+nums[i+1]+nums[i+2]);   
        }
        return 0;
    }
};