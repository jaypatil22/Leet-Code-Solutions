class Solution
{
public:
    double dist(vector<int> &a, vector<int> &b)
    {
        return sqrt(abs(a[0] - b[0]) * abs(a[0] - b[0]) + abs(a[1] - b[1]) * abs(a[1] - b[1]));
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> a;
        a.push_back(p1);
        a.push_back(p2);
        a.push_back(p3);
        a.push_back(p4);
        sort(a.begin(), a.end());

        return (dist(a[0], a[1]) != 0 && dist(a[1], a[3]) == dist(a[0], a[1]) && dist(a[1], a[3]) == dist(a[3], a[2]) && dist(a[0], a[1]) == dist(a[0], a[2]) && dist(a[0], a[3]) == dist(a[1], a[2]));
    }
};