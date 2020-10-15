class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0,h = matrix.size()-1;
        int i;
        while(l < h) {
            for(i =0;i<(h-l);i++) {
                swap(matrix[l][i+l],matrix[l+i][h]);
                swap(matrix[l][i+l],matrix[h][h-i]);
                swap(matrix[l][l+i],matrix[h-i][l]);
            }
            l++;h--;
        }



    }
};
