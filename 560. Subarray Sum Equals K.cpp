/*
	����1��ö�ٷ�

		(1) ö�ٵ�ǰ�������������Ƿ���ں�Ϊk������������
		(2) ���ϱ�������³��ȵ����飬������������Ѱ�ҷ�������������������
		(3) ʱ�临�Ӷ�O(n*n),��Ϊ��������forѭ��
		(4) �ռ临�Ӷ�O(1)��ֻ��Ҫ�����洢 ����� �Լ� ͳ�ƴ���
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int count = 0;
		for (int start = 0; start < nums.size(); ++start) {
			int sum = 0;
			for (int end = start; end >= 0; --end) {
				sum += nums[end];
				if (sum == k) {
					++count;
				}
			}
		}
		return count;
    }
};

/*
	����2��ǰ׺�� + ��ϣ���Ż� 
*/ 
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		mp[0] = 1;
		int count = 0, pre = 0;
		for (auto& x : nums) {
			pre += x;
			if (mp.find(pre - k) != mp.end()) 
				count += mp[pre - k];
			mp[pre]++;
		}
		return count;
	}
};
