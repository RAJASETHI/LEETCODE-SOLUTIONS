class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        unordered_map<string,int>mp;
        for(auto i:dict)mp[i]++;
        stringstream ss(s);
        string token;
        string res;
        while(getline(ss,token,' '))
        {
            string tmp;
            for(auto i:token)
            {
                tmp+=i;
                if(mp[tmp])
                {
                    res+=tmp+" ";
                    break;
                }
                else if(tmp==token)res+=token+" ";
            }
        }
        res.pop_back();
        return res;
    }
};