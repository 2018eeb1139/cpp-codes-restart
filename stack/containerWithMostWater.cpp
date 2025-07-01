int Solution::maxArea(vector<int> &heights)
{
    int n = heights.size();

    int mxArea = 0;
    int i = 0, j = n - 1;

    while (i < j)
    {
        int w = j - i;
        int h = min(heights[i], heights[j]);
        int area = w * h;
        mxArea = max(mxArea, area);

        if (heights[i] > heights[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return mxArea;
}
