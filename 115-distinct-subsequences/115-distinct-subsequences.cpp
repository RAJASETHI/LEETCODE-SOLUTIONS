class Solution {
public:
    int f1(string s, string t,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int cnt=f1(s,t,i-1,j,dp);
        if(s[i]==t[j])cnt+=f1(s,t,i-1,j-1,dp);
        return dp[i][j]=cnt;
    }
    
    int f2(string s, string t,int i,int j)
    {
        if(j<0)return 1;
        if(i<0)return 0;
        // if(dp[i][j]!=-1)return dp[i][j];
        int cnt=f2(s,t,i-1,j);
        if(s[i]==t[j])cnt+=f2(s,t,i-1,j-1);
        return cnt;
    }
    #define ll long long
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        int mod=1e9+7;
        
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(!j)continue;
                if(s[i-1]==t[j-1])dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
        }
    
    return dp[n][m];
    }
};