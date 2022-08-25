class Solution {
public:
    string convert(string s, int numRows) {
       if(s.size()==1 || numRows==1)return s;
        vector<string>vt(min(numRows,int(s.size())));
        int currRow=0;
        bool dir=false;
        for(char i:s)
        {
            // cout<<i<<" ";
            vt[currRow]+=i;
            if(currRow==0 || currRow==numRows-1)dir=!dir;
            currRow+=dir?1:-1;
        }
        string ans;
        for(auto k:vt)
        {
            cout<<k<<endl;
            ans+=k;
        }
        return ans;
    }
};