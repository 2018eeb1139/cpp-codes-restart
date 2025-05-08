class MedianFinder
{
public:
    vector<double> v;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        v.insert(lower_bound(v.begin(), v.end(), num), num);
    }

    double findMedian()
    {
        int n = v.size();
        double ans = 0;
        int mid = n / 2;
        if (n == 1)
        {
            ans = v[0];
        }
        if (n & 1)
        {
            ans = v[mid];
        }
        else
        {
            ans = (v[mid - 1] + v[mid]) / 2.0;
        }
        return ans;
    }
};