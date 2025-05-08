#include <stack>
using namespace std;

class MinStack
{
public:
    stack<long long> s;
    long long mn;
    MinStack()
    {
    }

    void push(int val)
    {
        if (s.size() == 0)
        {
            s.push(val);
            mn = val;
        }
        else
        {
            if (val >= mn)
            {
                s.push(val);
            }
            else if (val < mn)
            {
                s.push(2 * 1LL * val - mn);
                mn = val;
            }
        }
        return;
    }

    void pop()
    {
        if (s.size() == 0)
        {
            return;
        }
        else
        {
            if (s.top() >= mn)
            {
                s.pop();
            }
            else if (s.top() < mn)
            {
                mn = 2 * mn - s.top();
                s.pop();
            }
        }
        return;
    }

    int top()
    {
        if (s.size() == 0)
        {
            return -1;
        }
        else
        {
            if (s.top() >= mn)
            {
                return s.top();
            }
            else if (s.top() < mn)
            {
                return mn;
            }
        }
        return -1;
    }

    int getMin()
    {
        if (s.size() == 0)
        {
            return -1;
        }
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
