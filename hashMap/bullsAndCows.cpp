string Solution::solve(string secret, string guess)
{
    unordered_map<char, int> m;
    int bulls = 0;
    int cows = 0;
    string ans = "";
    for (char &c : secret)
    {
        m[c] += 1;
    }
    for (int i = 0; i < secret.size(); i++)
    {
        if (secret[i] == guess[i])
        {
            bulls++;
            m[secret[i]] -= 1;
        }
    }
    for (int i = 0; i < secret.size(); i++)
    {
        if (secret[i] != guess[i] && m[guess[i]])
        {
            cows++;
            m[guess[i]] -= 1;
        }
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
}
