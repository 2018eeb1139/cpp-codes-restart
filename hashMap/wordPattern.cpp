bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> m1;
    unordered_map<string, char> m2;
    int n = pattern.size();
    stringstream ss(s);
    vector<string> words;
    string word;
    while (ss >> word)
    {
        words.push_back(word);
    }
    if (pattern.size() != words.size())
        return false;
    for (int i = 0; i < n; i++)
    {
        char c = pattern[i];
        string w = words[i];

        if (m1.count(c) && m1[c] != w)
            return false;
        if (m2.count(w) && m2[w] != c)
            return false;

        m1[c] = w;
        m2[w] = c;
    }
    return true;
}