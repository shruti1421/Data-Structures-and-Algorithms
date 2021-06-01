#include<bits/stdc++.h>
using namespace std;

void minHeapify(vector<int> &heap, int n, int i) {

        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && heap[l] < heap[i])
                smallest = l;
        if (r < n && heap[r] < heap[smallest])
                smallest = r;

        if (smallest != i) {
                swap(heap[i], heap[smallest]);
                minHeapify(heap, n, smallest);
        }
}

void min_heapSort(vector<int> &heap) {

        //Build Max Heap
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
                minHeapify(heap, heap.size(), i);
        }

        //Heap Sort
        for (int i = heap.size() - 1; i >= 0; --i) {
                swap(heap[0], heap[i]);


                minHeapify(heap, i, 0);
        }

}

int main() {

        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
        //for getting input from input.txt
        freopen("input.txt", "r", stdin);
        //for writing output to output.txt
        freopen("output.txt", "w", stdout);
#endif

        int n;
        cin >> n;

        vector<int> heap;

        for (int i = 0; i < n; i++)
        {
                int x;
                cin >> x;
                heap.push_back(x);
        }

        min_heapSort(heap);

        for (auto& x : heap)
                cout << x << " ";
}
