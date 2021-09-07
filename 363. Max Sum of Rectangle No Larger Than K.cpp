class Solution {
public:
    int res = INT_MIN;
    void find(vector<int> &rowSum, int k) {
        int sum = 0;
        set<int> s;
        set<int>::iterator it;
        s.insert(0);
        for(int &a : rowSum) {
            sum += a;
            it = s.lower_bound(sum-k);
            if(it != s.end()) {
                res = max(res,sum-*it);
            }
            s.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix[0].size() > matrix.size()) {
            vector<int> rowSum(matrix[0].size());

            for(int i=0;i<matrix.size();i++) {
                fill(rowSum.begin(),rowSum.end(),0);
                for(int row=i;row<matrix.size();row++) {
                    for(int j=0;j<rowSum.size();j++) {
                        rowSum[j] += matrix[row][j];
                    }
                    find(rowSum,k);
                    if(res == k) return res;
                }
            }
        } else {
            vector<int> colSum(matrix.size());
            
            for(int i=0;i<matrix[0].size();i++) {
                fill(colSum.begin(),colSum.end(),0);
                for(int col = i;col<matrix[0].size();col++) {
                    for(int row= 0;row<matrix.size();row++) {
                        colSum[row] += matrix[row][col];
                    }
                    find(colSum,k);
                    if(res==k) return res;
                }
            }
        }
        return res;
    }
};