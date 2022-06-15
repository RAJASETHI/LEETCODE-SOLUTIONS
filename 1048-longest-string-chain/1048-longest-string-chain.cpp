class Solution {
public:
    static bool cmp(string &a,string &b)
    {
        return (a.size()<b.size() || (a.size()==b.size() && a<b));
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        
        unordered_map<string,int>dp;
        int mx=0;
        for(auto w:words)
        {
            for(int i=0;i<w.size();i++)
            {
                string pre=w.substr(0,i)+w.substr(i+1);
                dp[w]=max(dp[w],(dp.find(pre)==dp.end()?1:dp[pre]+1));
            }
            mx=max(mx,dp[w]);
        }
        return mx;
    }
};