class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> res(num_people, 0);
        int sum = 0, i = 0, c = 1;
        while (candies > 0)
        {
            if (c > candies)
            {
                res[i] += candies;
            }
            else
            {
                res[i] += c;
            }
            candies -= c;
            i++;
            c++;
            i %= num_people;
        }
        return res;
    }
};