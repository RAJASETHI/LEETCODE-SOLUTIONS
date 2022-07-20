class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        deque<deque<string>>dq(26);
        for(auto w:words)
        {
            dq[w[0]-'a'].push_back(w);
        }
        int ans=0;
        for(auto c:s)
        {
            int n=dq[c-'a'].size();
            for(int i=0;i<n;i++)
            {
                string t=dq[c-'a'].front();
                dq[c-'a'].pop_front();
                if(t.size()>1)
                {
                    
                    t=t.substr(1);
                    dq[t[0]-'a'].push_back(t);
                }
                else
                {
                  ans++;  
                }
            }
        }
        return ans;
    }
};