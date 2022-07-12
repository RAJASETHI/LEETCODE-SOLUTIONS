class Solution {
public:
    bool f(int idx,vector<int>sum,int target,vector<int>& mat)
    {
        if(idx==mat.size()){
            for(int i=1;i<4;i++)
            {
                if(sum[i]!=sum[i-1])return false;
            }
            return true;
        }
        bool ans=0;
        for(int i=0;i<4;i++)
        {
            if(sum[i]>target)return false;
            int j=i;
            while(--j>=0)
            {
                if(sum[i]==sum[j])break;
            }
            if(j!=-1)continue;
            sum[i]+=mat[idx];
            ans=ans || f(idx+1,sum,target,mat);
            if(ans)return true;
            sum[i]-=mat[idx];
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        vector<int>sum(4,0);
        int target=0;
        for(auto i:matchsticks)target+=i;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        if(target%4!=0)return false;
        target/=4;
        return f(0,sum,target,matchsticks);
        
    }
};