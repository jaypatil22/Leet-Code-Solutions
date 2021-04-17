class Solution
{
public:
    //     int rec(int n,int k) {

    //     }

    int findTheWinner(int n, int k)
    {
        if (n == 1)
            return 1;
        else
        {
            int a = findTheWinner(n - 1, k) + k;
            if (a % n == 0)
                return n;
            else
                return a % n;
        }
    }
};