class Solution {
public:
    int minPartitions(string n) {
        int res = 1;
        for(int i=0;i<n.size();i++) {
            if(n[i]-'0'>res) res = n[i]-'0';
        }
        return res;
    }
};