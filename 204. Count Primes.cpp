class Solution {
public:
   int countPrimes(int n) {
        int count = 0;
        if (n > 2) ++count;
        vector<bool> isNotPrimes(n, false);   // 2, 3, 5
        for (int i = 3; i < n; i += 2)
        {
            if (isNotPrimes[i] == false)
            {
                for (int j = 3; j * i < n; j += 2)
                {        //将所有质数的奇数倍都置为true，表示其不是质数(因为偶数是不进行遍历的，所以不用设置偶数倍)
                    isNotPrimes[j * i] = true;  
                }
                ++count;
            }
        }
        return count;
    }
};