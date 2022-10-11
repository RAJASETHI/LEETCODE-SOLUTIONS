class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        if(n==1)return "";
        if(n&1)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]!='a' && i!=n/2)
                {
                    s[i]='a';
                    return s;
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]!='a')
                {
                    s[i]='a';
                    return s;
                }
            }
            
        }
        s[n-1]='b';
        return s;
    }
};