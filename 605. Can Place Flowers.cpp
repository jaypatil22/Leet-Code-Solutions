class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.size()<=1) {
            if(n>1) return false;
            return flowerbed[0]==0;
        }
        int cnt = 0;
        for(int i=0;i<flowerbed.size();i++) {
            if(flowerbed[i]==0) {
                
                if(i==0) {
                    if(flowerbed[i+1]==0) {
                        cnt++;
                        flowerbed[i] = 1;
                    }
                } else if(i==flowerbed.size()-1) {
                    if(flowerbed[i-1]==0) {
                        cnt++;
                        flowerbed[i] = 1;
                    }
                } else if(flowerbed[i-1]==0 && flowerbed[i+1]==0) {
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
            if(cnt==n) return true;
        }
        return false;
    }
};