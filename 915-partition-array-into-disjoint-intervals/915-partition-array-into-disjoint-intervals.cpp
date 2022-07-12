class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int mx,curr;
        mx=curr=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<mx)
            {
                ans=i+1;
                mx=curr;
            }
            else if(nums[i]>curr)curr=nums[i];
                
        }
        return ans;
    }
};