class Solution {
public:
    #define ll long long
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;
        ll ans=0,dvd=labs(dividend),dvs=labs(divisor);
        int sign=(dividend>0)^(divisor>0)?-1:1;
            while(dvd>=dvs)
            {
                ll tmp=dvs,m=1;
                while(tmp<<1<=dvd)
                {
                    tmp=tmp<<1;
                    m<<=1;
                }
                
            dvd-=tmp;
            ans+=m;
            }
        return ans*sign;
    }
};