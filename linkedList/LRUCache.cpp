// optimal
class LRUCache
{
public:
    int n;
    list<int> dll;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            dll.erase(mp[key].second);
            dll.push_front(key);
            mp[key].second = dll.begin();
            return mp[key].first;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            dll.erase(mp[key].second);
            dll.push_front(key);
            mp[key] = {value, dll.begin()};
        }
        else
        {
            if (mp.size() == n)
            {
                mp.erase(dll.back());
                dll.pop_back();
            }
            dll.push_front(key);
            mp[key] = {value, dll.begin()};
        }
    }
}

// Brute force
class LRUCache
{
public:
    int n;
    vector<pair<int, int>> v;
    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == key)
            {
                auto temp = v[i];
                v.erase(v.begin() + i);
                v.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }

    void put(int key, int value)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == key)
            {
                v.erase(v.begin() + i);
                v.push_back({key, value});
                return;
            }
        }
        if (v.size() < n)
        {
            v.push_back({key, value});
        }
        else
        {
            v.erase(v.begin() + 0);
            v.push_back({key, value});
        }
    }
};