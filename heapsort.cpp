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

struct MaxHeap
{

    vector<int> heap;
    int n;
    MaxHeap(int _n, int _a[])
    {
        n = _n;
        heap.assign(_a, _a + n);
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(i, n);
        }
        for (int i = n - 1; i > 0; i--)
        {
            deleteKey(i);
        }
        // reverse(all(heap));
    }

    void heapify(int i, int N)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < N && heap[left] > heap[largest])
            largest = left;

        if (right < N && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest, N);
        }
    }

    void insert(int key)
    {
        heap.push_back(key);
        // heap[n]=key;
        n++;
        int i = n - 1;

        while (i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int idx)
    {

        if (idx == n)
        {
            return;
        }
        swap(heap[idx], heap[0]);
        heapify(0, idx);
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
};

void kire()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &it : a)
        cin >> it;
    MaxHeap mh(n, a);
    // mh.insert(69);
    mh.print();
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
