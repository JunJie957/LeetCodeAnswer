#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
	    int n = nums.size(), right = 0;
	    for (int i = 0; i < n; ++i) {
	        // 是否可以前进
	        if (right >= i) {
	            right = max(right, i + nums[i]); // 前进最大的步数
	            if (right >= n - 1) {
	                return true;
	            }
	        } else {
	            return false; // 不能再往前跳了
	        }
	    }
	    return false;
	}
};
