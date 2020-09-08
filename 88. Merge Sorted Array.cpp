// ����1���ϲ���ʹ��sort() ��������
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; ++i) 
			nums1[i + m] = nums2[i];
		sort(nums1.begin(), nums1.end());
	}
};

// ����2��ʹ�ö��⸨���ռ䣬Ȼ���ǰ����Ƚ�
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> help(m, 0);
		for (int i = 0; i < m; ++i) 
			help[i] = nums1[i];

		int i = 0, j = 0, loc = 0;
		while (i < m && j < n) {
			if (help[i] <= nums2[j]) {
				nums1[loc++] = help[i++];
			} else {
				nums1[loc++] = nums2[j++];
			}
		}

		while (i < m) nums1[loc++] = help[i++];
		while (j < n) nums1[loc++] = nums2[j++];
	}
};

// ����3���Ӻ���ǰ�ң���ʹ�ø����ռ�
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int loc = m + n - 1; // ����nums1�����λ�ã������λ�ÿ�ʼ����
		int i = m - 1, j = n - 1;	// ����nums1��nums2��β��Ԫ��
		while (i >= 0 && j >= 0) {
			if (nums1[i] >= nums2[j]) {
				nums1[loc--] = nums1[i--];
			} else {
				nums1[loc--] = nums2[j--];
			}
		}

		while (i >= 0) nums1[loc--] = nums1[i--];
		while (j >= 0) nums1[loc--] = nums2[j--];
	}
};

// ����3�� ���д�� 
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, loc = m + n - 1;
		while (j >= 0) {
			nums1[loc--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
		}
	}
};
