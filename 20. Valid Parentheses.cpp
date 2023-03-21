#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int size = s.length();
        if (size % 2 == 1) {
            return false;
        }

        stack<char> st;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.emplace(s[i]);
            } else if (!st.empty() && ((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']'))) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};