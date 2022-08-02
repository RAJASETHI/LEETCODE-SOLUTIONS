class Solution {
public:
    #define pa pair<int,int>
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // if(k<=n)return matrix[k-1][0];
        int n=matrix.size();
        priority_queue<pa,vector<pa>,greater<pa>>pq;
        vector<int>idx(matrix.size(),0);
        for(int i=0;i<n;i++)pq.push({matrix[i][0],i});
        int ans;
        while(k--)
        {
            ans=pq.top().first;
            int i=pq.top().second;
            pq.pop();
            if(idx[i]!=matrix[0].size()-1)
            {
                pq.push({matrix[i][++idx[i]],i});
            }
        }
        return ans;
    }
};