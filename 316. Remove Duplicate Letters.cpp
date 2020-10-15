class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(256,0);
        vector<bool> visited(256,false);
        for(auto a : s) count[a]++;
        string res="0";
        for(auto c : s) {
            count[c]--;
            if(visited[c]) continue;
            while(c < res.back() && count[res.back()]) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res.substr(1);
    }
};
