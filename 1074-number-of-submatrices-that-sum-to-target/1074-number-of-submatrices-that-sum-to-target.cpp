class Solution {
private:
    //Matrix:m*n
    int m,n;
    vector<vector<int>>prefix;
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        m=matrix.size(),n=matrix[0].size();
        prefix.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                prefix[i][j]=matrix[i][j];
                int v1=0,v2=0,v3=0;
                if(i-1>=0)v1=prefix[i-1][j];
                if(j-1>=0)v2=prefix[i][j-1];
                if(i-1>=0 && j-1>=0)v3=prefix[i-1][j-1];
                prefix[i][j]+=v1+v2-v3;
            }
        }
        int cnt=0;
        for(int r1=0;r1<m;r1++)
        {
            
            for(int r2=r1;r2<m;r2++)
            {
                unordered_map<int,int>mp;
                mp[0]++;
                int sm=0;
                for(int i=0;i<n;i++)
                {
                    int v1=0,v2=0,v3=0,v4=0;
                    v1=prefix[r2][i];
                    if(r1-1>=0)v2=prefix[r1-1][i];
                    v1-=v2;
                    if(mp[v1-target])cnt+=mp[v1-target];
                    mp[v1]++;
                }
            }
        }
        return cnt;
    }
};