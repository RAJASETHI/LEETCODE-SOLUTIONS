class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        int wsize=words[0].size();
        int wcnt=words.size();
        int n=s.size();
        if(s.size()<wcnt*wsize || (!s.size()) || !wsize)return res;
        unordered_map<string,int>mp;
        for(auto i:words)mp[i]++;
        for(int i=0;i<=n-wsize*wcnt;i++)
        {
            int flag=1;
            unordered_map<string,int>tmp;
            for(int j=0;j<wcnt*wsize;j+=wsize)
            {
                if(mp[s.substr(i+j,wsize)]!=0)
                {
                    tmp[s.substr(i+j,wsize)]++;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(!flag)continue;
            for(auto i:mp)
            {
                if(tmp[i.first]!=i.second)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};