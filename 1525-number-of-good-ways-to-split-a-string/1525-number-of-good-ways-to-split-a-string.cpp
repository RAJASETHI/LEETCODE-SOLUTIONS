class Solution {
public:
    int numSplits(string s) {
        set<int>st;
        int n=s.size();
        vector<int>pre;
        vector<int>suff(n,0);
        for(auto i:s)
        {
            st.insert(i);
            pre.push_back(st.size());
        }
        // int sz=st.size();
        st.clear();
        for(int i=n-1;i>=0;i--)
        {
            st.insert(s[i]);
            suff[i]=st.size();
            // cout<<suff[i]<<" ";
        }
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(pre[i]==suff[i+1] )cnt++;
        }
        return cnt;
    }
};