class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(256);
        for(auto a:magazine){
            count[a]++;
        }
        for(auto b : ransomNote) {
            if(count[b] == 0)
                return false;
            else {
                count[b]--;
            }
        }
        return true;
    }
};
