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

int extract_max(vector<int> &heap) {
        if (heap.size() < 1)
        {
                cout << "Heap Underflow\n";
                return -1;
        }

        int max = heap[0];

        heap[0] = heap[heap.size() - 1];

        heap.pop_back();

        max_heapify(heap, 0);

        return max;
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
                cout << extract_max(heap) << " ";
        }

        return 0;
}
