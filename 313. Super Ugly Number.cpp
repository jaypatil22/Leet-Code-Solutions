class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int prev = 1;
        set<int> s;
        vector<int> v;
        v.emplace_back(1);
        s.insert(prev);
        vector<int> pos(primes.size(),0);
        while(s.size()!=n) {
            int min = INT_MAX;
            vector<int> inc;
            for(int i =0;i<primes.size();i++) {
                if(primes[i]*v[pos[i]] < min) {
                    min = primes[i]*v[pos[i]];
                    inc.clear();
                    inc.emplace_back(i);
                } else if(min == primes[i]*v[pos[i]]) {
                    inc.emplace_back(i);
                }
            }
            s.insert(min);
            v.emplace_back(min);
            for(int a : inc) {
                pos[a]++;
            }
        }
        return v[n-1];
    }
};
