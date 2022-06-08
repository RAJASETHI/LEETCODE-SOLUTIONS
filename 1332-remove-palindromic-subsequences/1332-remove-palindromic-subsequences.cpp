class Solution {
public:
    int removePalindromeSub(string s) {
        int l=0,n=s.size(),r=n-1,flag=1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                flag=0;
                break;
            }
            else
            {
                l++,r--;
            }
        }
        if(flag)return 1;
        return 2;
    }
};