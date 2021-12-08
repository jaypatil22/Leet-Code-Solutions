class Solution {
public:
    int minimumBuckets(string street) {
        int res = 0;
        for(int i=0;i<street.size();i++) {
            bool left = 0, right = 0;
            if(street[i]=='H') {
                if(i!=0) {
                    if(street[i-1]=='B') continue;
                    if(street[i-1] == '.') left = 1;
                }
                if(i != street.size()) {
                    if(street[i+1]=='.') right = 1;
                }
                if(right) {
                    street[i+1] = 'B';
                    res++;
                }else if(left) {
                    street[i-1] = 'B';
                    res++;
                } else return -1;
            }
        }
        return res;
    }
};