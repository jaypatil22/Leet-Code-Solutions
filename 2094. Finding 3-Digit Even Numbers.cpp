class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> m;
        for(int i : digits) {
            m[i]++;
        }
        vector<int> res;
        for(int i=100;i<1000;i+=2) {
            string temp = to_string(i);
            int flag = 1;
            unordered_map<int,int> m1;
            for(int i=0;i<3;i++) {
                m1[temp[i]-'0']++;
            } 
            for(auto a : m1) {
                if(m[a.first] < a.second) {
                    flag = 0;
                    break;
                }
            }
            if(flag) res.push_back(i);
        }
        return res;
    }
};