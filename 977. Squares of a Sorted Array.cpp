class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		int left = 0, right = A.size() - 1, count = A.size() - 1, r1, r2;;
		vector<int> res(A.size(), 0);
		while (left <= right) {
			r1 = A[left] * A[left];
			r2 = A[right] * A[right];
			if (r1 >= r2) {
				res[count] = r1;
				++left;
			} else {
				res[count] = r2;
				--right;
			}
			--count;
		}
		return res;
	}
};
