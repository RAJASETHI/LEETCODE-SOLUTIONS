class Solution {
public:
    int BinaryToInt(string s)
    {
        int res=0;
        int pow=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            res+=(s[i]-'0')*pow;
            pow*=2;
        }
        return res;
    }
    bool hasAllCodes(string s, int k) {
        unordered_map<int,int>mp;
        if(s.size()<=k)return false;
        for(int i=0;i<=s.size()-k;i++)
        {
            mp[BinaryToInt(s.substr(i,k))]++;
        }
        for(int i=0;i<pow(2,k);i++)
        {
            // cout<<i<<" "<<mp[i]<<"\n";
            if(!mp[i])return false;
        }
        return true;
    }
};