class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int masses[100001];
        memset(masses, 0, sizeof masses);
        for(int &x : asteroids) {
            masses[x]++;
        }
        long long sum = mass;
        for(int i=1;i<100001;i++) {
            if(masses[i]) {
                if(sum < i) return false;
                sum += 1LL * masses[i] * i;
            }
        }
        return true;
    }
};