class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        int level=0;
        while(pow(2,level)<=label)level++;
        vector<int>res(level);
        for(;label>0;label=label/2,--level)
        {
            res[level-1]=label;
            label=(1<<level)-1-label+(1<<(level-1));
        }
        return res;
    }
};