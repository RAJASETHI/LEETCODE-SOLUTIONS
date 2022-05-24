class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int mx=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')st.push(i);
            else if(st.size())
            {
                st.pop();
                if(st.size())
                    mx=max(mx,i-st.top());
            }
            if(!st.size())st.push(i);
        }
        return mx;
    }
};