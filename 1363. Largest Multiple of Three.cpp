class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        string res = "";
        int m1[] = {1, 4, 7, 2, 5, 8}, m2[] = {2, 5, 8, 1, 4, 7};
        int sum = 0;
        vector<int> count(10);
        for(int i =0;i<digits.size();i++) {
            sum += digits[i];
            count[digits[i]]++;
        }
        if(sum == 0)
            return "0";
        while(sum%3) {
            for (auto i : sum % 3 == 1 ? m1 : m2) {
      if (count[i]) {
        --count[i];
        sum -= i;
        break;
      }
    }
        }
        for (int i = 9; i >= 0; --i)
            res += string(count[i], '0' + i);

        return res.size() && res[0] == '0' ? "0" : res;
    }
};
