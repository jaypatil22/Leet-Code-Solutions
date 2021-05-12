class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        long long total = 0;
        priority_queue<int> q(target.begin(), target.end());
        for (int a : target)
        {
            total += a;
        }
        while (true)
        {
            int a = q.top();
            q.pop();
            cout << a << " ";
            total -= a;
            if (a == 1 || total == 1)
                return true;
            if (a < total || total == 0 || a % total == 0)
                return false;
            a %= total;
            total += a;
            q.push(a);
        }
    }
};