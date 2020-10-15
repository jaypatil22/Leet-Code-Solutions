class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int half = candies.size()/2;
        bitset<200001> s;
        int distinct = 0;
        for(auto i : candies) {
            if(!s.test(100000+i))
                distinct++;
            s.set(i+100000);
        }

        return half < distinct ? half : distinct;
    }
};
