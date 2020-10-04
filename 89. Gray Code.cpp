class Solution {
public:

    void gray(vector<int> &res, int n,int &num) {
        if(n ==0) {
            res.push_back(num);
            return;
        }
        gray(res,n-1,num);
        num = num ^ (1 << (n-1));
        gray(res,n-1,num);
    }

    vector<int> grayCode(int n) {
        vector<int> res;
        int num = 0;
        gray(res,n,num);
        return res;
    }
};
