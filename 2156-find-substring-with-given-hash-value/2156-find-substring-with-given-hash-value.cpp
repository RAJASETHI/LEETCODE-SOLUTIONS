class Solution {
public:
    #define ll long long
    int val(char c)
    {
        return ((c-'a')+1);
    }
    string subStrHash(string s, int power, int m, int k, int hashValue) {
            ll n=s.size();
            ll sm=0;
            ll pk=1;
            ll res=n;
            for(int i=n-1;i>=0;i--)
            {
                sm=((sm*power)%m+val(s[i]))%m;
                if(i+k>=n)pk=(pk*power)%m;
                else
                {
                    sm=(m+sm-(val(s[i+k])*pk)%m)%m;
                }
                if(sm==hashValue)res=i;
            }
        return s.substr(res,k);
    }
};