class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        hc.push_back(h);
        vc.push_back(w);
        hc.push_back(0);
        vc.push_back(0);
        sort(begin(hc),end(hc));
        sort(begin(vc),end(vc));
        long int mx_h=0;
        for(int i=0;i<hc.size()-1;i++)
        {
            mx_h=max(mx_h,(long)hc[i+1]-hc[i]);
        }
        long int mx_w=0;
        for(int i=0;i<vc.size()-1;i++)
        {
            mx_w=max(mx_w,(long)vc[i+1]-vc[i]);
        }
        return (mx_h*mx_w)%((int)pow(10,9)+7);
    }
};