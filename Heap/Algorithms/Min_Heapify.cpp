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

int main() {

        int n;
        cin >> n;

        vector<int> heap;

        for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                heap.push_back(x);
        }


        min_heapify(heap, 0);

        for (auto& x : heap)
                cout << x << " ";

        return 0;
}
