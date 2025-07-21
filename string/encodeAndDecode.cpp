#include <bits/stdc++.h>
using namespace std;

string encode(vector<string> &strs)
{
    int n = strs.size();
    char c = '#';
    string encodedString = "";
    for (int i = 0; i < n; i++)
    {
        string s = strs[i];
        encodedString += s;
        if (i != n - 1)
            encodedString += c;
    }
    return encodedString;
}

vector<string> decode(string s)
{
    vector<string> ans;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '#')
        {
            temp += s[i];
        }
        else
        {
            ans.push_back(temp);
            temp = "";
        }
    }
    ans.push_back(temp);
    return ans;
}

int main()
{
    vector<string> strs = {"ab", "b", "c", "abc"};
    string encodedString = encode(strs);

    cout << encodedString << endl;

    vector<string> decodedStrings = decode(encodedString);

    for (auto &s : decodedStrings)
    {
        cout << s << " ";
    }
    cout << endl;
}

string encode(vector<string> &strs)
{
    string encoded = "";
    for (const string &s : strs)
    {
        encoded += to_string(s.size()) + '#' + s;
    }
    return encoded;
}

vector<string> decode(const string &s)
{
    vector<string> result;
    int i = 0;
    while (i < s.size())
    {
        int j = i;
        // Parse length prefix
        while (s[j] != '#')
            j++;
        int len = stoi(s.substr(i, j - i));
        result.push_back(s.substr(j + 1, len));
        i = j + 1 + len;
    }
    return result;
}
