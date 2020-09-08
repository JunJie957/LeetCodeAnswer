// ����1 �� ʹ�ñ������� 
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		vector<int> reverse(size, 0);
		for (int i = 0; i < size; ++i)
			reverse[(i + k) % size] = nums[i];
		nums = reverse;
	}
};

// ����2�� ������ת + �ֲ���ת
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

// ����3�� ��״�滻
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start, prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                swap(nums[next], prev);
                current = next;
                ++count;
		    } while (start != current);
	    }
    }
};
