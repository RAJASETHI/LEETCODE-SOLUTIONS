class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(!i || !j)dp[i][j]=0;
                else if(j==1)dp[i][j]=1;
                else if(i==1)dp[i][j]=j;
                else
                {
                    int mn=100000,l=0,r=j;
                    while(l<=r)
                    {
                        int mid=l+(r-l)/2;
                        int left=dp[i-1][mid-1];
                        int right=dp[i][j-mid];
                        int temp=max(left,right);
                        if(left<right)l=mid+1;
                        else r=mid-1;
                        mn=min(mn,temp);
                    }
                    dp[i][j]=mn+1;
                }
            }
        }
        return dp[k][n];
    }
};