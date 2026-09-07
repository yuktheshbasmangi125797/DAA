#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int linearSearch(const vector<int>& arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n = 100000;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int key;
    cout << "Enter the element: ";
    cin >> key;

    auto start = high_resolution_clock::now();
    int index = linearSearch(arr, key);
    auto stop = high_resolution_clock::now();

    cout << "\nLinear Search Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    index = binarySearch(arr, key);
    stop = high_resolution_clock::now();

    cout << "Binary Search Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds" << endl;

    return 0;
}
