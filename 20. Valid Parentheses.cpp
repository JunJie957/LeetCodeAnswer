
class Solution {
public:
    bool isValid(string s)
    {
        int size = s.size();
        if (size == 0) {
            return true;
        }
        else if (size % 2 == 1) {
            return false;
        }
           
        stack<char> st;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else if (!st.empty() 
                && ((st.top() == '(' && s[i] == ')')
                ||  (st.top() == '{' && s[i] == '}') 
                ||  (st.top() == '[' && s[i] == ']'))){
                st.pop();
                continue;
            }
            else {
                return false;
            }
        }

        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
