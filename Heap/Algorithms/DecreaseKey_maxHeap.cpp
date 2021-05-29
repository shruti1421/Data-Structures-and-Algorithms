#include<bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &heap, int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l >= heap.size() && r >= heap.size())
                return;

        if (l < heap.size() && heap[l] > heap[i])
                largest = l;

        if (r < heap.size() && heap[r] > heap[largest])
                largest = r;

        if (largest != i)
        {
                swap(heap[largest], heap[i]);
                max_heapify(heap, largest);
        }
}

void decreaseKey_maxHeap(vector<int> &heap, int key, int i) {
        if (key > heap[i])
        {
                cout << "Wrong Operation\n";
                return;
        }

        heap[i] = key;

        max_heapify(heap, i);
}

int main() {
        int n;
        cin >> n;

        vector<int> heap;

        for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                heap.push_back(x);
        }

        int i, key;
        cin >> i >> key;

        decreaseKey_maxHeap(heap, key, i);

        for (auto& x : heap)
        {
                cout << x << " ";
        }

        return 0;
}
