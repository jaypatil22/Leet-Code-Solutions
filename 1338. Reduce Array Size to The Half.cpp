class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++) {
            m[arr[i]]++;
        }
        vector<int> occur;
        for(auto a : m) {
            occur.push_back(a.second);
            // cout << a.second << endl;
        }
        sort(occur.rbegin(),occur.rend());
        int n = arr.size()/2,cnt=0,i=0;
        for(i=0;(cnt < n) && i<occur.size();i++) {
            cnt += occur[i];
        }
        return i;
    }
};