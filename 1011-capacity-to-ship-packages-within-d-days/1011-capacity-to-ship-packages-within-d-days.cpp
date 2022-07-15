class Solution {
public:
    bool isPossible(int weight,vector<int>&weights,int days)
    {
        int cnt=0,sm=0,n=weights.size();
        
        for(int i=0;i<=n;i++)
        {
            if(i==n || sm+weights[i]>weight)
            {
                if(sm)
                    cnt++;
                if(i!=n)
                sm=weights[i];
            }
            else
            {
                sm+=weights[i];
            }
        }
        return (cnt<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int r=accumulate(weights.begin(),weights.end(),0);
        int l=*max_element(weights.begin(),weights.end());
        int res=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isPossible(mid,weights,days))
            {
                res=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
    }
};