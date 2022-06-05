class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>player(n,1);
        int idx(0);
        for(int i=0;i<n;i++)
        {
            player[i]=i+1;
        }
        while(player.size()>1)
        {
            idx=(idx+k-1)%player.size();
            player.erase(player.begin()+idx);
        }
        return player[0];
    }
};