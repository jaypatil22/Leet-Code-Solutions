class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0, j= colors.size()-1;
        while(colors[i] == colors[j]) i++;
        while(colors[0] == colors[j]) j--;
        return max(j,(int)colors.size()-1-i);
    }
};