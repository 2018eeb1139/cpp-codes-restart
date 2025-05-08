#include <iostream>
#include <vector>
using namespace std;

class RandomizedSet
{
    vector<int> v;
    unordered_map<int, int> m;

public:
    RandomizedSet()
    {
    }
    bool search(int val)
    {
        if (m.find(val) != m.end())
        {
            return true;
        }
        return false;
    }

    bool insert(int val)
    {
        if (search(val) == true)
        {
            return false;
        }
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (search(val) == false)
        {
            return false;
        }
        int idx = m[val];
        int last = v.back();
        v[idx] = last;
        m[last] = idx;
        v.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom()
    {
        int idx = rand() % v.size();
        return v[idx];
    }
};