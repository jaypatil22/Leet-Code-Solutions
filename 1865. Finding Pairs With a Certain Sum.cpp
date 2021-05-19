class FindSumPairs
{
    unordered_map<int, int> m2;
    vector<int> n1, n2;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        n1 = nums1;
        n2 = nums2;
        for (int i = 0; i < nums2.size(); i++)
        {
            ++m2[nums2[i]];
        }
    }

    void add(int index, int val)
    {
        --m2[n2[index]];
        n2[index] += val;
        ++m2[n2[index]];
    }

    int count(int tot)
    {
        int res = 0;
        for (int i = 0; i < n1.size(); i++)
        {
            int f = tot - n1[i];
            if (m2.find(f) != m2.end())
            {
                res += m2[f];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */