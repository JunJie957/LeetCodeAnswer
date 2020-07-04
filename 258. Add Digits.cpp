class Solution {
public:
    int addDigits(int num) {
        string s = std::to_string(num);
        int sum = 0;

        while (num >= 10)
        {
            sum = 0;
            for (int i = 0; i < s.size(); ++i)
                sum += (s[i] - 48);
            
            num = sum;
            s = std::to_string(num);
        }
        //cout << num << endl;
        return num;
    }
};