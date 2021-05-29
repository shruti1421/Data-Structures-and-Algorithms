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

void build_max_heap(vector<int> &heap) {

        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
                max_heapify(heap, i);
        }
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


        build_max_heap(heap);

        for (auto& x : heap)
                cout << x << " ";

        return 0;
}
