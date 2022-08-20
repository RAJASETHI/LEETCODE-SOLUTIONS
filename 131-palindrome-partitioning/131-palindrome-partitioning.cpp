class Solution {
public:
    vector<vector<string>>res;
    bool isPalindrome(string s)
    {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void f(int idx,string s,vector<string>&ans)
    {
        if(idx>=s.size())
        {
            res.push_back(ans);
            return;
        }
        string tmp;
        for(int i=idx;i<s.size();i++)
        {
            tmp+=s[i];
            if(isPalindrome(tmp))
            {
                ans.push_back(tmp);
                f(i+1,s,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string>ans;
        f(0,s,ans);
        return res;
    }
};