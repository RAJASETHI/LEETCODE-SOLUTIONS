class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(k>n || n==0)return 0;
        if(k==0)return n;
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        int idx=0;
        while(idx<n && mp[s[idx]]>=k)idx++;
        if(idx==n)return n;
        return max(longestSubstring(s.substr(0,idx),k),longestSubstring(s.substr(idx+1),k));
    }
};