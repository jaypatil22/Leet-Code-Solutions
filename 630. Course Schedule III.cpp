class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [](const auto &a, const auto &b) { return a[1] < b[1]; });
        long long start = 0;
        multiset<int> s;
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i][0] + start <= courses[i][1])
            {
                start += courses[i][0];
                s.insert(courses[i][0]);
            }
            else if (!s.empty() && *s.rbegin() > courses[i][0])
            {
                start -= *s.rbegin();
                s.erase(--s.end());
                start += courses[i][0];
                s.insert(courses[i][0]);
            }
        }
        return s.size();
    }
};