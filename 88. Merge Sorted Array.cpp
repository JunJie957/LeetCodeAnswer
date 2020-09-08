// 方法1：合并后，使用sort() 进行排序
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; ++i) 
			nums1[i + m] = nums2[i];
		sort(nums1.begin(), nums1.end());
	}
};

// 方法2：使用额外辅助空间，然后从前往后比较
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

// 方法3：从后往前找，不使用辅助空间
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int loc = m + n - 1; // 数组nums1的最后位置，从最后位置开始插入
		int i = m - 1, j = n - 1;	// 数组nums1和nums2的尾部元素
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

// 方法3： 简便写法 
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, loc = m + n - 1;
		while (j >= 0) {
			nums1[loc--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
		}
	}
};
