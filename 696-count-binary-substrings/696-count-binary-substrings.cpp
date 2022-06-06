class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>idx;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                idx.push_back(i);
            }
        }
        // cout<<idx.size()<<" ";
        int cnt=0;
        for(auto x:idx)
        {
            int i=x,j=x+1;
            
            while(i>=0 && j<n && s[i]!=s[j] && s[i]==s[x])
            {
                cnt++;
                i--;j++;
            }
        }
        return cnt;
    }
};