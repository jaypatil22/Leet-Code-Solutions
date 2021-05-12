class SeatManager
{
public:
    vector<int> seats;
    priority_queue<int> q;
    SeatManager(int n)
    {
        seats = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            q.push(-i);
        }
    }

    int reserve()
    {
        int a = -(q.top());
        q.pop();
        seats[a] = 1;
        return a;
    }

    void unreserve(int seatNumber)
    {
        seats[seatNumber] = 0;
        q.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */