class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        unordered_set<string>w(wordList.begin(),wordList.end());
        q.push(beginWord);q.push("");
        int res=0;
        unordered_map<string,int>vis;
        vis[beginWord]=1;
        if(w.find(endWord)==w.end())return 0;
        while(q.size())
        {
            string tmp=q.front();q.pop();
            if(tmp.size())
            {
                if(tmp==endWord)return res+1;
                for(int i=0;i<tmp.size();i++)
                {
                    for(int x=0;x<26;x++)
                    {
                        
                        string tmp2=tmp;
                        tmp2[i]='a'+x;
                        if(w.find(tmp2)!=w.end() && !vis[tmp2])
                        {
                            vis[tmp2]=1;
                            q.push(tmp2);
                        }
                    }
                }
            }
            else if(q.size())
            {
                res++;
                q.push("");
            }
        }
        return 0;
    }
};