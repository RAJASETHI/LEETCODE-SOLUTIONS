class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()>s.size())return false;
        unordered_map<int,int>ump;
        for(auto i:s)ump[i]++;
        for(auto i:t)ump[i]--;
        for(auto i:ump)
        {
            if(i.second!=0)return false;
        }
        return true;
    }
};