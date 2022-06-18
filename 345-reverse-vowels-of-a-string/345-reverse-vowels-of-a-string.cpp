class Solution {
public:
    bool isVowel(char c)
    {
        if(c<97)c+=32;
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string reverseVowels(string s) {
        vector<int>idx;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                idx.push_back(i);
            }
        }
        int l=0,r=idx.size()-1;
        while(l<r)
        {
            swap(s[idx[l]],s[idx[r]]);
            l++,r--;
        }
        return s;
    }
};