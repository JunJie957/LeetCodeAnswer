/*
	����1����ϣ�� 
	ʱ�临�Ӷȣ�O(n)
	�ռ临�Ӷȣ�O(1), ��ϣ��Ĵ�С��ȷ���ģ����ᳬ��26��Сд��ĸ�ĸ��� 
*/ 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        if (l1 != l2) return false;

        unordered_map<char, int> us1, us2;
        for (int i = 0; i < l1; ++i) {
            ++us1[s[i]];
            ++us2[t[i]];
        }

        for (auto& i : us1) {
            if (i.second != us2[i.first]) {
                return false;
            }
        }
        return true;
    }
};

/*
	����2���������бȽ�
	ʱ�临�Ӷȣ�O(nlogn), ����ɱ�O(nlogn)���Ƚϳɱ�O(n) 
	�ռ临�Ӷȣ�O(1), �ռ�ȡ��������ʵ��
*/ 
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s.compare(t) == 0;
    }
};

