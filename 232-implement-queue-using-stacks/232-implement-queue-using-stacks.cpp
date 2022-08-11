class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!st.size()){st.push(x);return;}
        int data=st.top();
        st.pop();
        push(x);
        st.push(data);
    }
    
    int pop() {
        int data=st.top();
        st.pop();
        return data;
    }
    
    int peek() {
        int data=st.top();
        return data;
    }
    
    bool empty() {
        return (st.size()==0);
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