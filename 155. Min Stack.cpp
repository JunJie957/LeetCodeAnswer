class MinStack {
    public:
        /** initialize your data structure here. */
        stack<int> min_stack; // min_stack 储存当前值对应的栈中的最小值
        stack<int> sstack; 
        MinStack() {
            this->min_stack.push(INT_MAX);
        }

        void push(int x) {
            this->min_stack.push(min(this->min_stack.top(), x));
            this->sstack.push(x);
        }

        void pop() {
            this->sstack.pop();
            this->min_stack.pop();
        }

        int top() {
            return this->sstack.top();
        }

        int getMin() {
            return this->min_stack.top();
        }
    };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */