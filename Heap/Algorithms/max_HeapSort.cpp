#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &heap, int n, int i) {

        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && heap[l] > heap[i])
                largest = l;
        if (r < n && heap[r] > heap[largest])
                largest = r;

        if (largest != i) {
                swap(heap[i], heap[largest]);
                maxHeapify(heap, n, largest);
        }
}

void max_heapSort(vector<int> &heap) {

        //Build Max Heap
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
                maxHeapify(heap, heap.size(), i);
        }
        
        //Heap Sort
        for (int i = heap.size() - 1; i >= 0; --i) {
                swap(heap[0], heap[i]);
                

                maxHeapify(heap, i, 0);
        }

}

int main() {

        int n;
        cin >> n;

        vector<int> heap;

        for (int i = 0; i < n; i++)
        {
                int x;
                cin >> x;
                heap.push_back(x);
        }

        max_heapSort(heap);

        for (auto& x : heap)
                cout << x << " ";
}
