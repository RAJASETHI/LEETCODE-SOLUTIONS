class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string,int>frq;
        string res="";
        for(auto i:strs)
        {
            string s;
            for(auto x:i)
            {
                s+=x;
                frq[s]++;
                if(frq[s]==strs.size())res=s;
            }
        }
        return res;
    }
};