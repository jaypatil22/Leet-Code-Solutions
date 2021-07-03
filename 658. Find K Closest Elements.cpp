class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,h=arr.size()-1;
        while(l<h) {
            int mid = l + (h-l)/2;
            if(arr[mid]==x) {
                l = mid;
                break;
            } else if(arr[mid] < x) {
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        // cout << l << endl;
        int i,j;
        if(l==0) {
            i=l;
            j=l+1;
        } else if(l==arr.size()-1) {
            i=l-1;
            j=l;
        } else {
            i=l-1;
            j=l;
        }
        multiset<int> s;
        while(s.size()<k) {
            int lm = INT_MAX,hm=INT_MAX;
            if(i>=0) {
                lm = abs(x-arr[i]);
            }
            if(j<arr.size()) {
                hm = abs(x-arr[j]);
            }
            if(hm<lm) {
                s.insert(arr[j]);
                // cout << arr[j] << endl;
                j++;
            } else {
                s.insert(arr[i]);
                // cout << arr[i] << endl;
                i--;
            }
        }
        // cout << endl;
        vector<int> res(s.begin(),s.end());
        return res;
    }
};