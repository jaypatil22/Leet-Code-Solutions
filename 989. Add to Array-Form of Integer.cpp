class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = 0;
        vector<int> res;
        for(int i = A.size()-1;i>=0;i--) {
            int temp = A[i] + carry + K%10;
            res.emplace_back(temp%10);
            carry = temp/10;
            K /= 10;
        }
        while(K != 0) {
            int temp = K%10+carry;
            K /= 10;
            carry = temp/10;
            res.emplace_back(temp%10);
        }
        while(carry != 0 ) {
            res.emplace_back(carry%10);
            carry /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
