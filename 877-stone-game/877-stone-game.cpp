class Solution {
public:
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        for(int sz=1;sz<=n;sz++)
        {
            for(int i=0,j=sz-1;j<n;i++,j++)
            {
                if((j+i+n)%2==1)
                    dp[i+1][j+1]=max(piles[i]+dp[i+2][j+1],piles[j]+dp[i+1][j]);
                else
                    dp[i+1][j+1]=max(-piles[i]+dp[i+2][j+1],-piles[j]+dp[i+1][j]);
                
            }
        }
        return dp[1][n]>0;
    }
};