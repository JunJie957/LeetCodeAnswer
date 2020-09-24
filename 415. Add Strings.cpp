class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num2.size() > num1.size()) swap(num1, num2);

        int i = num1.size() - 1, j = num2.size() - 1, add = 0, sum;
        while (i >= 0 && j >= 0) {
            sum = num1[i] + num2[j--] + add - '0' - '0';
            if (sum >= 10) add = 1;
            else  add = 0;
            num1[i--] = sum % 10 + '0';
        }

        while (add == 1 && i >= 0) {
            sum = num1[i] + add - '0';
            if (sum >= 10) add = 1;
            else  add = 0;
            num1[i--] = sum % 10 + '0';
        }
        if (add == 1)  num1.insert(num1.begin(), '1');
        return num1;
    }
};
