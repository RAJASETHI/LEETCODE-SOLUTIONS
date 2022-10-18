class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        while(--n)
        {
            string tmp;
            int cnt=1;
            char ch=ans[0];
            for(int i=1;i<ans.size();i++)
            {
                if(ch==ans[i])cnt++;
                else
                {
                    tmp+=to_string(cnt);
                    tmp+=ch;
                    ch=ans[i];
                    cnt=1;
                }
            }
            tmp+=to_string(cnt);
            tmp+=ch;
            ans=tmp;
        }
        return ans;
    }
};