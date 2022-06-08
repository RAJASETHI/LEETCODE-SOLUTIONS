class Solution {
public:
    bool isPalindrome(string s)
    {
        int l=0,n=s.size(),r=n-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            else
            {
                l++,r--;
            }
        }
        return true;
    }
    int removePalindromeSub(string s) {
        int flag=isPalindrome(s);
        if(flag)return 1;
        return 2;
    }
};