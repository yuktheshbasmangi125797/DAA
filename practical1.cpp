#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int>& a)
{
    int size = a.size();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& a)
{
    int size = a.size();

    for (int i = 0; i < size - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[smallest])
            {
                smallest = j;
            }
        }

        swap(a[i], a[smallest]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& a)
{
    int size = a.size();

    for (int i = 1; i < size; i++)
    {
        int value = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > value)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = value;
    }
}

// Merge two sorted parts
void mergeArrays(vector<int>& a, int left, int middle, int right)
{
    vector<int> leftPart;
    vector<int> rightPart;

    for (int i = left; i <= middle; i++)
    {
        leftPart.push_back(a[i]);
    }

    for (int i = middle + 1; i <= right; i++)
    {
        rightPart.push_back(a[i]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftPart.size() && j < rightPart.size())
    {
        if (leftPart[i] <= rightPart[j])
        {
            a[k] = leftPart[i];
            i++;
        }
        else
        {
            a[k] = rightPart[j];
            j++;
        }

        k++;
    }

    while (i < leftPart.size())
    {
        a[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < rightPart.size())
    {
        a[k] = rightPart[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(vector<int>& a, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSort(a, left, middle);
    mergeSort(a, middle + 1, right);

    mergeArrays(a, left, middle, right);
}

// Quick Sort
int getPivotPosition(vector<int>& a, int low, int high)
{
    int pivot = a[high];
    int position = low;

    for (int i = low; i < high; i++)
    {
        if (a[i] < pivot)
        {
            swap(a[i], a[position]);
            position++;
        }
    }

    swap(a[position], a[high]);

    return position;
}

// Quick Sort
void quickSort(vector<int>& a, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivotIndex = getPivotPosition(a, low, high);

    quickSort(a, low, pivotIndex - 1);
    quickSort(a, pivotIndex + 1, high);
}

int main()
{
    const int SIZE = 100;

    vector<int> numbers(SIZE);
    vector<int> copy;

    srand(time(0));

    // Generate random numbers
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = rand() % 1000;
    }

    cout << "Number of Elements = " << SIZE << "\n\n";

    // Bubble Sort
    copy = numbers;

    auto start = high_resolution_clock::now();
    bubbleSort(copy);
    auto end = high_resolution_clock::now();

    cout << "Bubble Sort Time    : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";


    // Selection Sort
    copy = numbers;

    start = high_resolution_clock::now();
    selectionSort(copy);
    end = high_resolution_clock::now();

    cout << "Selection Sort Time : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";


    // Insertion Sort
    copy = numbers;

    start = high_resolution_clock::now();
    insertionSort(copy);
    end = high_resolution_clock::now();

    cout << "Insertion Sort Time : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";


    // Merge Sort
    copy = numbers;

    start = high_resolution_clock::now();
    mergeSort(copy, 0, SIZE - 1);
    end = high_resolution_clock::now();

    cout << "Merge Sort Time     : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";


    // Quick Sort
    copy = numbers;

    start = high_resolution_clock::now();
    quickSort(copy, 0, SIZE - 1);
    end = high_resolution_clock::now();

    cout << "Quick Sort Time     : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    return 0;
}
