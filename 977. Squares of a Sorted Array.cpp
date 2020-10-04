class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int i = 0,j = A.size()-1,pos = A.size()-1;
        while(i != j) {
            if(A[i]*A[i] > A[j]*A[j]) {
                res[pos--] = A[i]*A[i];
                i++;
            } else {
                res[pos--] = A[j]*A[j];
                j--;
            }
        }
        res[pos] = A[i]*A[i];
        return res;

    }
};
