class Solution {

public:
    vector<string>res;
    void f(int idx,string ans,string s,unordered_set<string>&dict)
    {
        if(idx==s.size())
        {
            ans.pop_back();
            
            res.push_back(ans);
            return;
        }
        string tmp="";
        for(int i=idx;i<s.size();i++)
        {
            tmp+=s[i];
            if(dict.count(tmp))
            {
                f(i+1,ans+tmp+" ",s,dict);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        res.clear();
        f(0,"",s,dict);
        return res;
    }
};