class Solution {
public:
    void merge(vector<int>&nums,int l,int mid,int r,int &res) {
        for(int i=l,j=mid;i<mid;i++) {
            while(j<=r && nums[i] > ((long long)2*nums[j])) {
                j++;
            }
            res+= (j-mid);
        }
        vector<int> nn;
        int i= l, j =  mid;
        while(i<mid && j <= r) {
            if(nums[i] < nums[j]) {
                nn.push_back(nums[i++]);
            } else {
                nn.push_back(nums[j++]);
            }
        }
        while(i<mid) {
            nn.push_back(nums[i++]);
        }
        while(j<=r) {
            nn.push_back(nums[j++]);
        }
        for(int k = l,m=0;k<=r;k++,m++) {
            nums[k] = nn[m];
        }
    }
    void mergesort(vector<int> &nums,int l,int r,int &res) {
        if(l >= r) return;
        int mid = (l +r)/2;
        mergesort(nums,l,mid,res);
        mergesort(nums,mid+1,r,res);
        merge(nums,l,mid+1,r,res);
    }
    int reversePairs(vector<int>& nums) {
        int res = 0;
        mergesort(nums,0,nums.size()-1,res);
        return res;
    }
};