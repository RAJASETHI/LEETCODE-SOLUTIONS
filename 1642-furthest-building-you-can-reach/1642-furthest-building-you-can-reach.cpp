class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>res;
        int n=h.size();
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(h[i]>h[i-1])res.push(h[i]-h[i-1]);
            if(res.size()>ladders)
            {
                int num=res.top();
                res.pop();
                if(num<=bricks)bricks-=num;
                else break;
            }
            cnt++;
        }
        // cnt+=res.size();
        return cnt;
    }
};