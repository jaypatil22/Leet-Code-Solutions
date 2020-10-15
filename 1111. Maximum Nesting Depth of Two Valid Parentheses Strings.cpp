class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size());
        int d1=0,d2=0;
        for(int i=0 ;i< seq.size();i++) {
            if(seq[i] == '(') {
                if(d1 > d2) {
                    res[i] = 1;
                    d2++;
                } else {
                    res[i] = 0;
                    d1++;
                }
            } else {
                if(d2 > d1) {
                    d2--;
                    res[i] = 1;
                } else {
                    d1--;
                    res[i] = 0;
                }
            }
        }
        return res;
    }
};
