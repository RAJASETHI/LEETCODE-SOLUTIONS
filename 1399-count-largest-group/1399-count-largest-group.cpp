class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int mx_size=0;
        int mx_cnt=0;
        for(int i=1;i<=n;i++)
        {
            string s=to_string(i);
            int sm=0;
            for(auto i:s)sm+=i-'0';
            mp[sm]++;
            if(mx_size<mp[sm])
            {
                mx_size=mp[sm];
                mx_cnt=1;
            }
            else if(mx_size==mp[sm])
            {
                mx_cnt++;
            }
        }
        return mx_cnt;
    }
};