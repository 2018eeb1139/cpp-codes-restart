#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s)
{
    unordered_map<char, int> m;
    m.insert({'(', -1});
    m.insert({'{', -2});
    m.insert({'[', -3});
    m.insert({')', 1});
    m.insert({'}', 2});
    m.insert({']', 3});
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] < 0)
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;
            char c = st.top();
            st.pop();
            if (m[c] + m[s[i]] != 0)
            {
                return false;
            }
        }
    }
    // if(st.size()==0) return true;
    // else return false;
    return st.empty();
}