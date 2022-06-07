class Solution {
public:
    bool isNum(char c)
    {
        return (c>=48 && c<=57);
    }
    int calculate(string s) {
        int res=0,sign=1,curr=0;
        stack<int>st,sgn;
        for(auto i:s)
        {
            if(isNum(i))
            {
                curr=curr*10+(i-'0');
            }
            else if(i=='+' || i=='-')
            {
                res+=curr*sign;
                curr=0;
                sign=(i=='-'?-1:1);
            }
            if(i=='(')
            {
                st.push(res);
                sgn.push(sign);
                res=0;
                curr=0;
                sign=1;
            }
            else if(i==')')
            {
                res+=curr*sign;
                res*=sgn.top();
                res+=st.top();
                st.pop();sgn.pop();
                curr=0;
            }
            // cout<<res<<" ";
        }
        if(s[s.size()-1]!=')')res+=curr*sign;
        cout<<sgn.size();
        // if(s[0]==)
        return res;
    }
};