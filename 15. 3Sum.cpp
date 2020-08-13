

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
       
        vector<vector<int>> res;
        int left, right, sum, size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) {
                return res; // ��ʣ�������������Ԫ��Ϊ����ʱ�������ܴ�������Ԫ�صĺ�Ϊ������
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // ȥ���ظ�Ԫ��
            }

            left = i + 1;       // ��߽�
            right = size - 1;   // �ұ߽�
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    --right; // ����֮�ʹ���0����ָ������
                }
                else if (sum < 0) {
                    ++left; // ����֮��С��0����ָ������
                }
                else {
                    res.push_back({ nums[i],nums[left],nums[right] });

                    // ����һ������ѡ�к󣬾���Ҫ����ȥ�������ظ�Ԫ�صĲ����ˣ������ظ�����
                    while (right > left && nums[left] == nums[left + 1]) ++left;
                    while (right > left && nums[right] == nums[right - 1]) --right;

                    // ����ָ���ս���������һ�������ж�
                    ++left;
                    --right;
                }
            }
        }
        return res;
    }
};

