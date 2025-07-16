int main()
{
    vector<int> arr = {1, 10, 2, 9};
    sort(arr.begin(), arr.end());
    int median = arr[arr.size() / 2];
    int ct = 0;
    for (int &x : arr)
    {
        ct += abs(x - median);
    }
    cout << ct;
}