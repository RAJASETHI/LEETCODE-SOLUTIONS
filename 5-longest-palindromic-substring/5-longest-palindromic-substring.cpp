class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int mx_len=0;
        string ans;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(j==i)dp[i][j]=1;
                else if(j-i==1)
                {
                    dp[i][j]=s[i]==s[j];
                }
                else
                {
                    dp[i][j]=s[i]==s[j] && dp[i+1][j-1];
                }
                if(dp[i][j])
                {
                    mx_len=max(mx_len,j-i+1);
                    if(j-i+1==mx_len)
                    ans=s.substr(i,j-i+1);
                }
                
            }
        }
        return ans;
        
    }
};