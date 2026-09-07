#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;
void createMaxHeap(vector<int>& a, int size, int pos)
{
    int maxPos = pos;
    int leftChild = 2 * pos + 1;
    int rightChild = 2 * pos + 2;

    if (leftChild < size && a[leftChild] > a[maxPos])
        maxPos = leftChild;

    if (rightChild < size && a[rightChild] > a[maxPos])
        maxPos = rightChild;

    if (maxPos != pos)
    {
        swap(a[pos], a[maxPos]);
        createMaxHeap(a, size, maxPos);
    }
}

void heapSortMax(vector<int>& a)
{
    int size = a.size();

    // Create Max Heap
    for (int i = size / 2 - 1; i >= 0; --i)
        createMaxHeap(a, size, i);

    // Sort the elements
    for (int end = size - 1; end > 0; --end)
    {
        swap(a[0], a[end]);
        createMaxHeap(a, end, 0);
    }
}
void createMinHeap(vector<int>& a, int size, int pos)
{
    int minPos = pos;
    int leftChild = 2 * pos + 1;
    int rightChild = 2 * pos + 2;

    if (leftChild < size && a[leftChild] < a[minPos])
        minPos = leftChild;

    if (rightChild < size && a[rightChild] < a[minPos])
        minPos = rightChild;

    if (minPos != pos)
    {
        swap(a[pos], a[minPos]);
        createMinHeap(a, size, minPos);
    }
}

void heapSortMin(vector<int>& a)
{
    int size = a.size();

    // Create Min Heap
    for (int i = size / 2 - 1; i >= 0; --i)
        createMinHeap(a, size, i);

    // Sort the elements
    for (int end = size - 1; end > 0; --end)
    {
        swap(a[0], a[end]);
        createMinHeap(a, end, 0);
    }

    // Convert descending result into ascending order
    reverse(a.begin(), a.end());
}
int main()
{
    int total;

    cout << "Enter number of elements: ";
    cin >> total;

    vector<int> data(total);

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < total; ++i)
    {
        data[i] = rand() % 100000;
    }

    vector<int> maxData = data;
    vector<int> minData = data;
    auto maxStart = high_resolution_clock::now();
    heapSortMax(maxData);
    auto maxEnd = high_resolution_clock::now();
    auto minStart = high_resolution_clock::now();
    heapSortMin(minData);
    auto minEnd = high_resolution_clock::now();

    // Calculate execution time
    auto maxNano = duration_cast<nanoseconds>(maxEnd - maxStart);
    auto maxMicro = duration_cast<microseconds>(maxEnd - maxStart);
    auto maxMilli = duration_cast<milliseconds>(maxEnd - maxStart);

    auto minNano = duration_cast<nanoseconds>(minEnd - minStart);
    auto minMicro = duration_cast<microseconds>(minEnd - minStart);
    auto minMilli = duration_cast<milliseconds>(minEnd - minStart);

    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << maxNano.count() << " ns\n";
    cout << "Microseconds : " << maxMicro.count() << " us\n";
    cout << "Milliseconds : " << maxMilli.count() << " ms\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << minNano.count() << " ns\n";
    cout << "Microseconds : " << minMicro.count() << " us\n";
    cout << "Milliseconds : " << minMilli.count() << " ms\n";

    return 0;
}
