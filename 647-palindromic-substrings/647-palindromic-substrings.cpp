class Solution {
public:
    int countSubstrings(string s) {
        int sz=s.size();
        vector<vector<int>>dp(sz,vector<int>(sz,0));
        int cnt=0;
        for(int i=sz-1;i>=0;i--)
        {
            for(int j=sz-1;j>=i;j--)
            {
                if(j==i)dp[i][j]=1;
                else if(j-i==1)dp[i][j]=(s[i]==s[j]);
                else
                {
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                cnt+=dp[i][j];
            }
        }
        return cnt;
    }
};