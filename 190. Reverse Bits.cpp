class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
  
        // 求n的二进制形式(倒排后)
        string s("");
        while (n != 0)
        {
            s += to_string(n % 2);
            n /= 2;
        }
        s.insert(s.end(), 32 - s.size(), '0'); // 位数不足32位，则在低位补零

        // 求二进制的值
        uint32_t res = 0;
        for(int i = s.size() - 1, count = 0; i >= 0; --i, ++count)
            res += (s[i] - '0') * pow(2, count);

        return res;
    }
};