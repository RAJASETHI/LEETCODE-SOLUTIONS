class Solution {
public:
    int twoEggDrop(int n) {
        int k=2;
        vector<vector<int>>dp(k+2,vector<int>(n+2,0));
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(!i)dp[i][j]=INT_MAX;
                else if(!j)dp[i][j]=0;
                else if(j==1)dp[i][j]=1;
                else if(i==1)dp[i][j]=j;
                else
                {
                    int mn=INT_MAX;
                    for(int p=1;p<j;p++)
                    {
                        mn=min(max(dp[i-1][p-1],dp[i][j-p]),mn);
                    }
                    dp[i][j]=mn+1;
                }
            }
        }
        return dp[k][n];
    }
};