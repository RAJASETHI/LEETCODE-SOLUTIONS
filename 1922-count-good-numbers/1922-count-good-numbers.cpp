class Solution {
public:
    #define ll long long
    ll mod=1e9+7;
    ll pow(ll x,ll n)
    {
        ll ans=1;
        while(n)
        {
            if(n%2)
            {
                ans=(ans*x)%mod;
                n--;
            }
            else
            {
                x=x%mod;
                x=(x*x)%mod;
                n/=2;
            }
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        ll e=5,o=4;
        ll cnt=1;
        ll t=n/2,val=1;
        cnt=((ll)pow(e,t)%mod*(ll)pow(o,t)%mod)%mod;
        if(n%2)cnt=(cnt*e)%mod;
        return cnt;
    }
};