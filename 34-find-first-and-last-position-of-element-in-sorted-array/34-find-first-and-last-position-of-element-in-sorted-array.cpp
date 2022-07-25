class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,n=nums.size(),r=n-1;
        vector<int>res={-1,-1};
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>=target)
            {
                if(nums[mid]==target)res[0]=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                
                if(nums[mid]==target)res[1]=mid;
                l=mid+1;
            }
        }
        return res;
    }
};