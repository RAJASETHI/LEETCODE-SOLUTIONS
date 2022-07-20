class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>idx(26);
        for(int i=0;i<s.size();i++)
        {
            idx[s[i]-'a'].push_back(i);
        }
        int ans=0;
        for(auto w:words)
        {
            int x=-1,flag=1;
            for(auto i:w)
            {
                auto itr=upper_bound(idx[i-'a'].begin(),idx[i-'a'].end(),x);
                if(itr==idx[i-'a'].end())
                {
                    flag=0;
                    break;
                }
                else
                {
                    x=*itr;
                }
            }
            ans+=flag;
        }
        return ans;
    }
};