#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define tata return 0
#define all(v) v.begin(), v.end()
#define endl '\n'
#define gap ' '

const int M = 1e9 + 7;

struct MinHeap
{

    vector<int> heap;
    int n;
    MinHeap(int _n, int _a[])
    {
        n = _n;
        heap.assign(_a, _a + n);
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(i, n);
        }
    }

    void heapify(int i, int N)
    {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < N && heap[left] < heap[smallest])
            smallest = left;

        if (right < N && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify(smallest, N);
        }
    }

    void insert(int key)
    {
        heap.push_back(key);
        n++;
        int i = n - 1;

        while (i != 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int idx)
    {
        if (idx >= n)
            return;

        heap[idx] = heap[n - 1];
        n--;

        int i = idx;
        while (i > 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }

        heapify(idx, n);
    }
    void print()
    {
        cout << "[";
        for (int i = 0; i < n; i++)
        {
            cout << heap[i];
            if (i != n - 1)
                cout << ",";
        }

        cout << "]" << endl;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }
    int front()
    {
        return heap[0];
    }
};

void kire()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto &it : a)
        cin >> it;
    MinHeap mh(n, a);
    int ans = 0;
    while (true)
    {
        if (mh.front() >= k)
            break;
        if (mh.n == 1 && mh.front() < k)
        {
            ans = -1;
            break;
        }
        int a = mh.front();
        mh.deleteKey(0);
        int b = mh.front();
        mh.deleteKey(0);
        mh.insert(a + 2 * b);
        ans++;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        kire();
    }

    tata;
}
