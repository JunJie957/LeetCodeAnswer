#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <istream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream in(s);
        std::string res;
        while (in >> res);
        return res.size();
    }
};
