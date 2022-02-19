class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> prei(seats.size()),suffi(seats.size());
        int prev = -1;
        for(int i=0;i<seats.size();i++) {
            if(seats[i]==1) prev = i;
            prei[i] = prev;
        }
        prev = -1;
        for(int i=seats.size()-1;i>=0;i--) {
            if(seats[i]==1) prev = i;
            suffi[i] = prev;
        }
        int res = 0;
        for(int i=0;i<seats.size();i++) {
            int cur = INT_MAX;
            if(prei[i]!=-1) cur = min(cur,i-prei[i]);
            if(suffi[i]!=-1) cur = min(cur,suffi[i]-i);
            res = max(cur,res);
        }
        return res;
    }
};

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int k = 0;
        for(int i=0;i<seats.size();i++) {
            if(seats[i]==1) k =0;
            else {
                k++;
                res = max(res,(k+1)/2);
            }
        }
        for(int i=0;i<seats.size();i++) {
            if(seats[i]==1) {
                res = max(res,i);
                break;
            }
        }
        for(int i=seats.size()-1;i>=0;i--) {
            if(seats[i]==1) {
                res = max(res,(int)seats.size()-1-i);
                break;
            }
        }
        return res;
    }
};