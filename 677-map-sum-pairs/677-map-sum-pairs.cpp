class MapSum {
public:
    unordered_map<string,int>mp;
    unordered_map<string,int>mp_val;
    MapSum() {
        mp.clear();
    }
    
    void insert(string key, int val) {
        string tmp;
        if(mp_val.find(key)!=mp_val.end())
        {
                int c=val-mp_val[key];
                mp_val[key]=val;
                val=c;
        }
        else mp_val[key]=val;
        for(int i=0;i<key.size();i++)
        {
            
            tmp+=key[i];
            mp[tmp]+=val;
        }
    }
    
    int sum(string prefix) {
        return mp[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */