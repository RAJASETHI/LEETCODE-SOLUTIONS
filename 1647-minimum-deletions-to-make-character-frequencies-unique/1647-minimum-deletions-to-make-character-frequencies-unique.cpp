class Solution {
public:
    int minDeletions(string s) {
        vector<int>f(26,0);
        for(auto x:s)f[x-'a']++;
        sort(f.begin(),f.end());
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<26;i++)
        {
            while(mp[f[i]] && f[i]!=0)
            {
                cnt++;
                f[i]--;
            }
            mp[f[i]]++;
        }
        return cnt;
    }
};