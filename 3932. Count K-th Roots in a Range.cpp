class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return (r-l)+1;
        double one_by_k = double(1.0/k);
        double start = pow(double(l), one_by_k);
        double end = pow((double)r, one_by_k);
        // cout << start <<  " " << end << endl;
        // cout << int(end+ 1e-9);
        return int(int(end+ 1e-9)- ceil(start))+1;
    }
};