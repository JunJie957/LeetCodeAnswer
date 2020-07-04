
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        auto ritera = a.rbegin();
        auto riterb = b.rbegin();

        char carry = '0';
        while (ritera != a.rend() && riterb != b.rend())
        {
            if (*ritera == '1' && *riterb == '1')
            {
                if (carry == '0')
                {
                    res += '0';
                }
                else if (carry == '1')
                {
                    res += '1';
                }
                carry = '1';
            }
            else if ((*ritera == '1' && *riterb == '0')||(*ritera == '0' && *riterb == '1'))
            {
                if (carry == '0')
                {
                    res += '1';
                }
                else if (carry == '1')
                {
                    res += '0';
                    carry = '1';
                }
            }
            else if (*ritera == '0' && *riterb == '0')
            {
                if (carry == '0')
                {
                    res += '0';
                }
                else if (carry == '1')
                {
                    res += '1';
                }
                carry = '0';
            }

            ++ritera;
            ++riterb;
        }

      //  cout << "carry = " << carry << endl;
        while (ritera != a.rend())
        {
            if (*ritera == '1')
            {
                if (carry == '0')
                {
                    res += '1';
                }
                else if(carry == '1')
                {
                    res += '0';
                    carry = '1';
                }
            }
            else if(*ritera == '0')
            {
                if (carry == '0')
                {
                    res += '0';
                }
                else if (carry == '1')
                {
                    res += '1';
                    carry = '0';
                }
            }
            ++ritera;
        }


        while (riterb != b.rend())
        {
            if (*riterb == '1')
            {
                if (carry == '0')
                {
                    res += '1';
                }
                else if (carry == '1')
                {
                    res += '0';
                    carry = '1';
                }
            }
            else if (*riterb == '0')
            {
                if (carry == '0')
                {
                    res += '0';
                }
                else if (carry == '1')
                {
                    res += '1';
                    carry = '0';
                }
            }
            ++riterb;
        }

        if (carry == '1') res += '1';
        reverse(res.begin(), res.end());
       // cout << res << endl;
        return res;
    }
};