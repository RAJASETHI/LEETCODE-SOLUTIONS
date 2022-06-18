class Solution {
public:
    unordered_map<int,int>mp;
    bool f(int n)
    {
        if(n==1)return true;
        if(mp[n]==1)return false;
        mp[n]=1;
        string s=to_string(n);
        int sm=0;
        for(auto i:s)
        {
            sm+=(i-'0')*(i-'0');
        }
        return f(sm);
    }
    bool isHappy(int n) {
        mp.clear();
        return f(n);
    }
};