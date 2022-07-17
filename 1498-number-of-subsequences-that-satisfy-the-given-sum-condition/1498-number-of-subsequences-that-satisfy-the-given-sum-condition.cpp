class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    ll pow(ll a,ll b)
    {
        ll ans=1;
        while(b)
        {
            if(b%2)
            {
                ans=(ans*a)%mod;
                b--;
            }
            else
            {
                a=(a*a)%mod;
                b/=2;
            }
        }
        return ans%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        ll sm=0,n=nums.size();
        sort(begin(nums),end(nums));
        int l=0,r=n-1;
        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
            {
                r--;
            }
            else
            {
                sm=(sm+pow(2,r-l))%mod;
                l++;
            }
        }
        return (sm%mod);
    }
};