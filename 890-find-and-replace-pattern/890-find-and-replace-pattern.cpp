class Solution {
public:
    char toChar(int x)
    {
        return ('a'+x);
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<string>res;
       string epattern;
        int k=0;
        unordered_map<char,int>mp;
        for(auto i:pattern)
        {
            if(mp.find(i)==mp.end())
            {
                mp[i]=toChar(k++);
            }
            epattern+=mp[i];
        }
        // cout<<epattern<<"\n";
        for(auto w:words)
        {
            
            unordered_map<char,int>ump;
            string s;
            int k=0;
            for(auto i:w)
            {
                if(ump.find(i)==ump.end())
                {
                    ump[i]=toChar(k++);
                }
                s+=ump[i];
            }
            if(s==epattern)res.push_back(w);
        }
        return res;
    }
};