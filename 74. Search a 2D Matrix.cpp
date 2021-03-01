class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        if(matrix.size() == 0||(matrix.size()==1&&matrix[0].size()==0))
            return false;
        if(target < matrix[0][0])
            return false;
        while(row < matrix.size() && matrix[row][0] < target) {
            if(target == matrix[row][0])
                return true;
            row++;
        }
        if(row == matrix.size())
            row--;
        if(matrix[row][0] > target)
            row--;
        for(auto a : matrix[row]) {
            if(a == target)
                return true;
        }
        return false;
    }
};
