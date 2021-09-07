class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int ma = releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++) {
            if(releaseTimes[i]-releaseTimes[i-1] == ma) {
                ma = releaseTimes[i]-releaseTimes[i-1];
                res = res >= keysPressed[i] ? res : keysPressed[i];
            } else if(releaseTimes[i]-releaseTimes[i-1] > ma) {
                ma = releaseTimes[i]-releaseTimes[i-1];
                res = keysPressed[i];
            }
        }
        return res;
    }
};