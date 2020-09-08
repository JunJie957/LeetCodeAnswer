// ���� 1 �� ���������ռ� 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        
        /* �����ռ�, ��¼���з����� */ 
        vector<int> v;  
        for (int i = 0; i < size; ++i) 
            if (nums[i] != 0) v.push_back(nums[i]);

        /* �������ֵ������ */
        size = v.size();
        for (int i = 0; i < size; ++i) 
            nums[i] = v[i];

        /* �����ֵ������ */
        for (int i = size; i < nums.size(); ++i) 
            nums[i] = 0;
    }
};

/*
    2��ָ�뷨

        (1) ����һ������ָ�룬������ʾ���з���ֵ���±�
        (2) �����������飬��������ֵ������жϣ������ǰ�������±�ֵ���ڷ���ָ�룬˵���м���������ֵ
        (3) �򽫵�ǰֵ��ֵ������ָ��(����ָ���λ���Ѿ��ƶ��������λ��)��Ȼ�󽫵�ǰֵ��Ϊ��(��Ϊ��ǰֵ�Ѿ��ƶ�����ǰ��)
        (4) ÿ����������ֵ�������Ƿ���ֵ���滻������Ҫ������ָ���ƶ�����һλ����������һ����Ҫ�滻��λ��
        (5) ����� [ 26. ɾ�����������е��ظ��� ] һ�����ƣ����ǲ���ָ�뷨����
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int not_zero_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i > not_zero_index) {
                    nums[not_zero_index] = nums[i];
                    nums[i] = 0;
                }
                ++not_zero_index;
            }
        }
    }
};
