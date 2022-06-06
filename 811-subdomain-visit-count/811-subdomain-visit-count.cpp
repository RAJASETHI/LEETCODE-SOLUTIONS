class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>freq;
        
        for(auto &x:cpdomains)
        {
            string rep;
            for(int i=0;i<x.size();i++)
            {
                if(x[i]>=48 && x[i]<=57)rep+=x[i];
                else
                {
                    x=x.substr(i+1);
                    break;
                }
            }
            vector<int>idx;
            idx.push_back(0);
            for(int i=0;i<x.size();i++)
            {
                if(x[i]=='.')idx.push_back(i+1);
            }
            for(auto i:idx)
            {
                string tmp=x.substr(i);
                if(freq.find(tmp)==freq.end())
                    freq[tmp]=stoi(rep);
                else
                    freq[tmp]+=stoi(rep);
            }
        }
        vector<string>res;
        for(auto i:freq)
        {
            res.push_back(to_string(i.second)+" "+i.first);
        }
        return res;
    }
};