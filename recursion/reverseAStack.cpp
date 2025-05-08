#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.size() == 0)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void reverseStack(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insert(s, temp);
}