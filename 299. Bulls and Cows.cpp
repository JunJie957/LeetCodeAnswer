class Solution {
public:
    string getHint(string secret, string guess) {
        int cow = 0, bull = 0, size = secret.size();
        unordered_map<char,int> m1, m2;
        for (int i = 0; i < size; ++i) {
            if (secret[i] == guess[i]) {
                ++cow;
            }
            else {
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }

        for (const auto& iter : m2) {
            bull += iter.second > m1[iter.first] ? m1[iter.first] : iter.second;
        }
        return to_string(cow) + "A" + to_string(bull) + "B";
    }
};
