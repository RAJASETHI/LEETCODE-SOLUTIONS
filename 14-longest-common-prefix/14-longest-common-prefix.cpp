class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string res;
        for(int i=0;i<strs[0].size();i++)
        {
            if(strs[0][i]==strs[n-1][i])res+=strs[0][i];
            else break;
        }
        return res;
    }
};