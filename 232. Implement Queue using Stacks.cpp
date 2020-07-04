class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    stack<int> help;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        stack<int> tmp;
        while (s.size() > 1)
        {
            tmp.push(s.top());
            s.pop();
        }
        int res = s.top();
        s.pop();

        // s is empty.
        while (!tmp.empty())
        {
            s.push(tmp.top());
            tmp.pop();
        }

        return res;
    }

    /** Get the front element. */
    int peek() {
        help = s;
        while (help.size() > 1) help.pop();
        return help.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
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