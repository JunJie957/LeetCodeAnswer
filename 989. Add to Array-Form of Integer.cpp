class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
       reverse(A.begin(), A.end());
		int index = 0;
		while (K > 0)
		{
			if (index < A.size())
			{
				K += A[index];
				A[index] = K % 10; // 未越界, 直接赋值
			}
			else
			{
				A.push_back(K % 10); // 越界了, push
			}
			
			K /= 10;
			++index;
		}
		reverse(A.begin(), A.end());
		return A;
    }
};