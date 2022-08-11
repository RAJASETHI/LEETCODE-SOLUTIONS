class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int m=matrix.size(),n=matrix[0].size();
        int r1=0,r2=m-1,c1=0,c2=n-1;
        int cnt=m*n;
        while(cnt>0)
        {
            for(int i=c1;i<=c2 && (cnt-->0);i++)res.push_back(matrix[r1][i]);
            r1++;
            for(int i=r1;i<=r2 && (cnt-->0);i++)res.push_back(matrix[i][c2]);
            c2--;
            for(int i=c2;i>=c1 && (cnt-->0);i--)res.push_back(matrix[r2][i]);
            r2--;
            for(int i=r2;i>=r1 && (cnt-->0);i--)res.push_back(matrix[i][c1]);
            c1++;
        }
        return res;
    }
};