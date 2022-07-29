class Solution {
public:
    #define ll long long 
    ll res=0,mod=1e9+7;
    vector<vector<int>>dp;
    int f(int idx,int finish,int fuel,vector<int>&l)
    {
        if(fuel<0)return 0;
        if(dp[idx][fuel]!=-1)return dp[idx][fuel];
        ll cnt=finish==idx;
        for(int i=0;i<l.size();i++)
        {
            if(i==idx)continue;
            if(abs(l[i]-l[idx])<=fuel)
            {
                cnt=(cnt+f(i,finish,fuel-abs(l[i]-l[idx]),l))%mod;
            }
        }
        return dp[idx][fuel]=cnt;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp.resize(locations.size(),vector<int>(fuel+1,-1));
        return f(start,finish,fuel,locations);
    }
};