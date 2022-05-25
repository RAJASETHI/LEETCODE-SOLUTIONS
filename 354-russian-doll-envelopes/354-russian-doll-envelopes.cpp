class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];    
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>c;
        for(auto &p:envelopes)
        {
            auto itr=lower_bound(c.begin(),c.end(),p[1]);
            if(itr==c.end())c.push_back(p[1]);
            else if(*itr>p[1])*itr=p[1];
        }
        return c.size();
    }
};