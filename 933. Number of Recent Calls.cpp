class RecentCounter {
public:
    vector<int> req;
    int current;
    RecentCounter() {
        current = 0;
    }

    int ping(int t) {
        req.push_back(t);
        while(current < req.size() && req[current] < t-3000) {
            current++;
        }
        return req.size()-current;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
