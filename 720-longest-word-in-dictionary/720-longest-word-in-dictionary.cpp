class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map<string,int>mp;
        queue<string>q;
        
        string mn;
        for(auto x:words)
        {
            mp[x]++;
            if(x.size()==1)
            {
                q.push(x);
                if(x.size()>mn.size())mn=x;
            
                mn=min(mn,x);
            }
        }
        while(q.size())
        {
            string tmp=q.front();
            q.pop();
            for(int i=0;i<26;i++)
            {
                char c='a'+i;
                if(mp.find(tmp+c)!=mp.end())
                {
                    q.push(tmp+c);
                    if(tmp.size()+1>mn.size())
                    {
                        mn=tmp+c;
                    }
                    else if(tmp.size()+1==mn.size())
                    {
                        mn=min(mn,tmp+c);
                    }
                }
            }
        }
        return mn;
    }
};