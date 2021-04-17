class MyCircularQueue
{
public:
    int front = -1, rear = -1, size = -1;
    vector<int> q;
    MyCircularQueue(int k)
    {
        q.resize(k, -1);
        size = 0;
    }

    bool enQueue(int value)
    {
        if (size == 0)
        {
            q[0] = value;
            front = 0;
            rear = 1;
            size++;
            return true;
        }
        else if (size == q.size())
        {
            return false;
        }
        else
        {
            q[rear] = value;
            rear = (rear + 1) % q.size();
            size++;
            return true;
        }
    }

    bool deQueue()
    {
        if (size == 0)
        {
            return false;
        }
        else if (size == 1)
        {
            front = -1;
            rear = -1;
            size--;
            return true;
        }
        else
        {
            front = (front + 1 + q.size()) % q.size();
            size--;
            return true;
        }
    }

    int Front()
    {
        return isEmpty() ? -1 : q[front];
    }

    int Rear()
    {
        return isEmpty() ? -1 : q[(rear - 1 + q.size()) % q.size()];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == q.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */