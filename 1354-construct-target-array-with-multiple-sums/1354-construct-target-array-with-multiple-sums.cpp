class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        long sum=0;
        for (auto i:target)sum+=i;
        priority_queue<int>q(target.begin(),target.end());
        
        while(q.size())
        {
            int num=q.top();
            q.pop();
            sum-=num;
            if(sum==1 || num==1)
            {
                return true;
            }
            if(num<sum || sum==0 || num%sum==0)return false;
            num=num%sum;
            sum+=num;
            q.push(num);
        }
        return false;
        
    }
};