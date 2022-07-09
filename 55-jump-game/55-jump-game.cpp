class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=0,i=0;
        while(i<=last)
        {
            last=max(last,i+nums[i]);
            last=min(last,n-1);
            // cout<<last<<" ";
            i++;
        }
        return last>=n-1;
    }
};