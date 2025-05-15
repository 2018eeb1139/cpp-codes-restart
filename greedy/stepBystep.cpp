int Solution::solve(int A)
{
    if (A == 0)
        return 0;
    int target = abs(A);
    int sum = 0;
    int move = 0;
    while (1)
    {
        move += 1;
        sum += move;
        if (sum >= target && (sum - target) % 2 == 0)
        {
            break;
        }
    }
    return move;
}
