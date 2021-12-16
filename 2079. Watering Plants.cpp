class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int res = 0,c=capacity;
        for(int i=0;i<plants.size();i++) {
            res++;
            if(c < plants[i]) {
                res += (i)*2;
                c = capacity;   
            }
            c -= plants[i];
        }
        return res;
    }
};