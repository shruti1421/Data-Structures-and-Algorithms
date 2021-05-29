#include<bits/stdc++.h>
using namespace std;

void min_heapify(vector<int> &heap, int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l >= heap.size() && r >= heap.size())
                return;

        if (l < heap.size() && heap[l] < heap[i])
                smallest = l;

        if (r < heap.size() && heap[r] < heap[smallest])
                smallest = r;

        if (smallest != i)
        {
                swap(heap[smallest], heap[i]);
                min_heapify(heap, smallest);
        }
}

int extract_min(vector<int> &heap) {
        if (heap.size() < 1)
        {
                cout << "Heap Underflow\n";
                return -1;
        }

        int min = heap[0];

        heap[0] = heap[heap.size() - 1];

        heap.pop_back();

        min_heapify(heap, 0);

        return min;
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


        for (auto& x : heap)
        {
                cout << extract_min(heap) << " ";
        }

        return 0;
}
