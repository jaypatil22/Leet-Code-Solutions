class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        vector<long long int> ugly;
        set<long long int> s;
        ugly.push_back(1);
        s.insert(1);
        int p1 = 0,p2 = 0, p3 = 0;
        while(ugly.size() < n) {

            long long int v1 = 2*ugly[p1],v2 = 3*ugly[p2],v3 = 5*ugly[p3];
            if(v1 <= v2 && v1 <= v3 && s.count(v1) == 0) {
                ugly.push_back(v1);
                s.insert(v1);
            } else if(v2 <= v1 && v2 <= v3 && s.count(v2) == 0) {
                ugly.push_back(v2);
                s.insert(v2);
            } else if(v3 <= v1 && v3 <= v2 && s.count(v3) == 0) {
                ugly.push_back(v3);
                s.insert(v3);
            }
            if(s.count(v1) != 0)
                p1++;
            if(s.count(v2) != 0)
                p2++;
            if(s.count(v3) != 0)
                p3++;

        }

        return ugly[n-1];
    }
};
