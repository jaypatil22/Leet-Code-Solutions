class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> arr(26,false);
        for(char a : sentence) {
            arr[a-'a']=true;
        }
        for(bool b : arr) {
            if(!b) 
                return false;
        }
        return true;
    }
};