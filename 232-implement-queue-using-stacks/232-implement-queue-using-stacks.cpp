class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        while(st.size())st.pop();
    }
    
    void push(int x) {
        if(!st.size())
        {
            st.push(x);
            return;
        }
        int data=st.top();
        st.pop();
        push(x);
        st.push(data);
    }
    
    int pop() {
        int val=st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        
        int val=st.top();
        // st.pop();
        return val;
    }
    
    bool empty() {
        return (!st.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */