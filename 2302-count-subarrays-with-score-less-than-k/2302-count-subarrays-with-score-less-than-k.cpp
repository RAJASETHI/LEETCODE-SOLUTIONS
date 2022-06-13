class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n=nums.size();
        ll sm=0;
        ll cnt=0;
        for(int i=0,j=0;i<n;i++)
        {
            sm+=nums[i];
            while(sm*(i-j+1)>=k)
            {
                sm-=nums[j++];
            }
            cnt+=i-j+1;
        }
        return cnt;
    }
};