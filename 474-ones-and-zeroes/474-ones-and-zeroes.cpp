class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(auto s:strs)
        {
            int c1=0,c2=0;
            for(auto i:s)
            {
                c1+='1'-i;
                c2+=i-'0';
            }
            for(int i=m;i>=c1;i--)
            {
                for(int j=n;j>=c2;j--)
                {
                    dp[i][j]=max(dp[i][j],dp[i-c1][j-c2]+1);
                }
            }
            
        }
        
        
        return dp[m][n];
    }
};