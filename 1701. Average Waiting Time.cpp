class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double res = 0.00000;
        long long sum = 0, start = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i][0] >= start)
            {
                start = customers[i][0] + customers[i][1];
            }
            else
            {
                sum += (start - customers[i][0]);
                start += customers[i][1];
            }
            sum += customers[i][1];
        }
        res = (double)sum / customers.size();
        return res;
    }
};