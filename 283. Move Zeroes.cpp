// 方法 1 ： 借助辅助空间 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        
        /* 辅助空间, 记录所有非零项 */ 
        vector<int> v;  
        for (int i = 0; i < size; ++i) 
            if (nums[i] != 0) v.push_back(nums[i]);

        /* 将非零项赋值给数组 */
        size = v.size();
        for (int i = 0; i < size; ++i) 
            nums[i] = v[i];

        /* 将零项赋值给数组 */
        for (int i = size; i < nums.size(); ++i) 
            nums[i] = 0;
    }
};

/*
    2、指针法

        (1) 定义一个非零指针，用来表示所有非零值的下标
        (2) 遍历整个数组，遇到非零值后进行判断，如果当前遍历的下标值大于非零指针，说明中间遇到了零值
        (3) 则将当前值赋值给非零指针(非零指针的位置已经移动到了零的位置)，然后将当前值置为零(因为当前值已经移动到了前面)
        (4) 每次遇到非零值，无论是否发生值的替换，都需要将非零指针移动到下一位，继续找下一个需要替换的位置
        (5) 本题和 [ 26. 删除排序数组中的重复项 ] 一题类似，都是采用指针法处理
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
