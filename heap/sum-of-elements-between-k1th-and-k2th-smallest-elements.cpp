#include <vector>
#include <queue>
using namespace std;

long long kthSmallest(long long K, long long A[], long long N)
{
    priority_queue<long long> pq;
    for (int i = 0; i < N; i++)
    {
        pq.push(A[i]);
        if (pq.size() > K)
        {
            pq.pop();
        }
    }
    return pq.top();
}
long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
{
    // Your code goes here
    long long K3 = kthSmallest(K1, A, N);
    long long K4 = kthSmallest(K2, A, N);
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > K3 && A[i] < K4)
        {
            sum += A[i];
        }
    }
    return sum;
}