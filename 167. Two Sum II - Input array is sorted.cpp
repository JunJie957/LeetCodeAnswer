class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int head = 0;
        int tail = numbers.size() - 1;
        int sum = 0;
        while (head < tail)
        {
            sum = numbers[head] + numbers[tail];
            if (sum == target)
                return { head + 1, tail + 1};
            else if (sum > target)
                --tail;
            else
                ++head;
        }
        return { -1,-1 };
    }
};