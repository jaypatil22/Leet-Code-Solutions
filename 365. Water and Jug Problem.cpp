class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x == z || y == z || x + y == z)
            return true;
        if (x + y < z)
            return false;
        return (z % __gcd(x, y)) == 0;
    }
};