// minstack: the top element must be min of all
class MinStack {
public:
    stack<int>s,ms;
    MinStack() {
    }

    void push(int val) {
        s.push(val);
        if(ms.empty() || val<=ms.top()){  ///check if min stack top have greater value that the incoming ele
            ms.push(val);     ///if yes, push the smaller incoming ele in min stack
        }

    }

    void pop() {
        if(s.top()==ms.top()){  ///pop elements from both stacks if both are equal
            ms.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
