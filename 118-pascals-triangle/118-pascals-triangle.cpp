class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        res.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int>rw(i+1);
            for(int j=0;j<rw.size();j++)
            {
                if(j==0 || j==rw.size()-1)
                {
                    rw[j]=1;
                }
                else
                {
                    rw[j]=res[res.size()-1][j]+res[res.size()-1][j-1];
                }
            }
            res.push_back(rw);
        }
        return res;
    }
};