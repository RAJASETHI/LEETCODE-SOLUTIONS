class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,vector<int>>idx;
        int n=s.size();
        int l=0,r=0;
        int mx=0;
        
        while(r<n)
        {
             if(!idx[s[r]].size())
             {
                 idx[s[r]].push_back(r++);
             }
             else
             {
                 int prevIdx=idx[s[r]].back();
                 while(l<=prevIdx)
                 {
                     idx[s[l]].pop_back();
                     l++;
                 }
                 idx[s[r]].push_back(r++);
             }
             mx=max(mx,r-l);
            // cout<<l<<" "<<r<<" "<<mx<<"\n";
        }
        return mx;
    }
};