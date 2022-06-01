class MyQueue {
public:
    stack<int>st1,st2;
    MyQueue() {
        while(st1.size())st1.pop();
        while(st2.size())st2.pop();
    
    }
    
    void push(int x) {
        if(!st1.size())
        {
            while(st2.size())
            {
                st1.push(st2.top());
                st2.pop();
            }
            
            st1.push(x);
            while(st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else
        {
            
            while(st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
            
            st2.push(x);
            while(st2.size())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    
    int pop() {
        int val=-1;
        if(st1.size())
        {
            val=st1.top();
            st1.pop();
        }
        else if(st2.size())
        {
            val=st2.top();
            st2.pop();
        }
        return val;
    }
    
    int peek() {
        
        int val=-1;
        if(st1.size())
        {
            val=st1.top();
            // st1.pop();
        }
        else if(st2.size())
        {
            val=st2.top();
            // st2.pop();
        }
        return val;
    }
    
    bool empty() {
        return (!st1.size() && !st2.size());
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