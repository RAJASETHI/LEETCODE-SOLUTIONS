class Solution {
public:
    vector<vector<string>>res;
    void f(int x,vector<int>col,vector<int>d1,vector<int>d2,vector<string>ans,int n)
    {
        if(x==n)
        {
            res.push_back(ans);
            return ;
        }
        string s;
        for(int i=0;i<n;i++)s+='.';
        for(int i=0;i<n;i++)
        {
            if(!col[i] && !d1[x+i] && !d2[n+x-i])
            {
                col[i]=1;
                d1[x+i]=1;
                d2[n+x-i]=1;
                s[i]='Q';
                ans.push_back(s);
                f(x+1,col,d1,d2,ans,n);
                ans.erase(ans.begin()+ans.size()-1);
                s[i]='.';
                col[i]=0;
                d1[x+i]=0;
                d2[n+x-i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<int>col(n,0);
        vector<int>d1(2*n+1,0);
        vector<int>d2(2*n+1,0);
        f(0,col,d1,d2,{},n);
        return res;
    }
};