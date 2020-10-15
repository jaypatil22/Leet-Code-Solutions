class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() <= 1)
            return true;
        int id = A[0] > A[A.size()-1] ? 2 : 1;
        int i =1;
        while(id == 1 && A[i] >= A[i-1]) {
            i++;
            if(i == A.size())
                return true;
        }
        while(id == 2 && A[i] <= A[i-1]) {
            i++;
            if(i == A.size())
                return true;
        }
        return false;
    }
};
