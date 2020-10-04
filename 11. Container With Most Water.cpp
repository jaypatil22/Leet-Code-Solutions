class Solution {
public:
    int maxArea(vector<int>& height) {
       int left=0,right=height.size()-1;
        long long int res =0,mx=0;
        while(left < right) {
            int temp = height[left] < height[right] ? height[left] : height[right];
            res = temp * (right - left);
            if(res > mx)
                mx = res;
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return mx;
    }
};
