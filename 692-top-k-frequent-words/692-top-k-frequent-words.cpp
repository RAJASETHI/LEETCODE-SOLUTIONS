class Solution {
public:
    #define pa pair<int,string>
    struct cmp
    {
        bool operator()(pa p1,pa p2)
        {
            if(p1.first==p2.first)return p1.second<p2.second;
            return p1.first>p2.first;
        }   
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pa,vector<pa>,cmp>q;
        unordered_map<string,int>mp;
        for(auto i:words)
        {
            mp[i]++;
        }
        vector<string>res;
        for(auto i:mp)
        {
            q.push({i.second,i.first});
            if(q.size()>k)q.pop();
        }
        while(q.size())
        {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};