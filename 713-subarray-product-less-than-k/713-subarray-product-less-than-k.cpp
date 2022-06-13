class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(), cnt=0,ans=1;
        if(!k)return 0;
        while(r<n)
        {
            ans*=nums[r];
            if(ans<k)
            {
                r++;
            }
            else
            {
                while(ans>=k)
                {
                    ans/=nums[l++];
                }
                r++;
            }
            if(l<=r)
                cnt+=r-l;
        }
        return cnt;
    }
};