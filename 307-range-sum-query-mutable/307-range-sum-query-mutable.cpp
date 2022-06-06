class NumArray {
public:
    vector<int>bit;
    NumArray(vector<int>& nums) {
        bit.resize(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            update(i,nums[i]);
        }
    }
    
    void update(int index, int val) {
        int old_val=sum(index+1)-sum(index);
        // cout<<old_val<<"\n";
        index++;
        val=val-old_val;
        for(int i=index;i<bit.size();i+=i&(-i))
        {
            bit[i]+=val;
        }
    }
    int sum(int i)
    {
        int sm=0;
        while(i>0)
        {
            sm+=bit[i];
            i-=i&(-i);
        }
        return sm;
    }
    int sumRange(int left, int right) {
        return (sum(right+1)-sum(left));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */