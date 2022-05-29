class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size(),res=0;
        vector<vector<int>>f;
        for(auto s:words)
        {
            vector<int>freq(26,0);
            for(auto i:s)freq[i-'a']++;
            f.push_back(freq);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int flag=1;
                for(int k=0;k<26;k++)
                {
                    if(f[i][k] && f[j][k])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    res=max(res,(int)(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};