class Solution {
public:
    bool isValid(string s) 
    {
        if(s.empty())
            return true;

        if(s.size() % 2 != 0)
            return false;
            
        stack<char> st;
        int i = 0;
        while(i < s.length())    
        {
            if(!st.empty())
            {
                if((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
                {
                    st.pop();
                    ++i;
                    continue;
                }
            }

            st.push(s[i]);
            ++i;
        }

        if(st.empty())
            return true;
        return false;
    }
};