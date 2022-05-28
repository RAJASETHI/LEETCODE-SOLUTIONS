class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size(),xx=n;
        for(int i=0;i<n;i++)
        {
            xx^=i;
            xx^=nums[i];
        }
        return xx;
    }
};