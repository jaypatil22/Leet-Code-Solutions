class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> map;
        for(int i=0;i<pieces.size();i++) {
            map[pieces[i][0]] = i;
        }
        vector<int> res;
        int i=0;
        while(i<arr.size()) {
            if(map.find(arr[i]) == map.end()) {
                return false;
            }
            vector<int> temp = pieces[map[arr[i]]];
            for(int j=0;j<temp.size();j++) {
                if(arr[i] != temp[j]) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};