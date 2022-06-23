class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses),end(courses),cmp);
        int cnt=0;
        int l=0;
        priority_queue<int>q;
        for(auto x:courses)
        {
            if(l+x[0]<=x[1])
            {
                l+=x[0];
                q.push(x[0]);
            }
            else
            {
                if(q.size() && q.top()>x[0])
                {
                    l-=q.top();
                    q.pop();
                    l+=x[0];
                    q.push(x[0]);
                }
            }
        }
        return q.size();
    }
};