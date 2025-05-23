#include <iostream>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    if (target >= letters[n - 1])
        return letters[0];
    int start = 0;
    int end = n - 1;
    char res = '#';
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (letters[mid] == target)
        {
            start = mid + 1;
        }
        else if (letters[mid] > target)
        {
            res = letters[mid];
            end = mid - 1;
        }
        else if (letters[mid] < target)
        {
            start = mid + 1;
        }
    }
    return res;
}