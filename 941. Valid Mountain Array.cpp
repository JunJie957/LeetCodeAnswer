class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		int i = 0, len = A.size();
		while (i + 1 < len && A[i] < A[i + 1]) ++i; // 上山
		if (i == 0 || i == len - 1) return false;
		while (i + 1 < len && A[i] > A[i + 1]) ++i; // 下山
		return i == len - 1;
	}
};
