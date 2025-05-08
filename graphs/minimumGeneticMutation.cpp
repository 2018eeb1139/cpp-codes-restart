#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int minMutation(string startGene, string endGene, vector<string> &bank)
{
    queue<string> q;
    unordered_set<string> vis;
    unordered_set<string> s(bank.begin(), bank.end());
    q.push(startGene);
    vis.insert(startGene);
    int level = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            string curr = q.front();
            q.pop();
            if (curr == endGene)
                return level;
            for (auto &c : "ACGT")
            {
                for (int i = 0; i < curr.size(); i++)
                {
                    string child = curr;
                    child[i] = c;
                    if (vis.find(child) == vis.end() && s.find(child) != s.end())
                    {
                        q.push(child);
                        vis.insert(child);
                    }
                }
            }
        }
        level += 1;
    }
    return -1;
}