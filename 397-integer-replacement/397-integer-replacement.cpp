class Solution {
    unordered_map<int,int>dp;
    int f(int n)
    {
        if(n==1)return 0;
        if(dp.find(n)!=dp.end())
        {
            return dp[n];
        }
        if(n%2==0)
        {
            return dp[n]=f(n/2)+1;
        }
        return dp[n]=min(f(n/2),f(n/2+1))+2;
    }
public:
    int integerReplacement(int n) {
        return f(n);
    }
};