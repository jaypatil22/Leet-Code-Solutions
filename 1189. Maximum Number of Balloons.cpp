class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(256);
        string ban = "ban";
        string lo= "lo";

        for(char a : text) {
            count[a]++;
        }
        int min = 1000000;
        for(char c : ban) {
            if(count[c] < min) {
                min = count[c];
            }
        }
        for(char c : lo) {
            if(count[c]/2 <= min) {
                min = count[c]/2;
            }
        }

        return min;
    }
};
