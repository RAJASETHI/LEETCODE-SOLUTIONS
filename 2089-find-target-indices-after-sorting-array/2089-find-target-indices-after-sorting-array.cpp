class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ind;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++)
            if(nums[i]==target)
                ind.push_back(i);
        return ind;
    }
};