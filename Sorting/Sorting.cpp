#include <iostream>
using namespace std;

class Sorting
{
private:
    void Swap(int *, int *);
    void Merge(int *array1, int *array2, int *array, int left, int right);
    void Merge2(int *array, int left, int right);
    int Partition(int *array, int left, int right);

public:
    Sorting(/* args */);
    ~Sorting();
    void SelectionSort(int *array, int n);
    void BubleSort(int *array, int n);
    void MergeSort(int *array, int left, int right);
    void MergeSort2(int *array, int left, int right);
    void QuickSort(int *array, int left, int right);
};

Sorting::Sorting(/* args */)
{
}

Sorting::~Sorting()
{
}

// Swap with the smallest element on the right
void Sorting::SelectionSort(int *array, int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int *smallestFromRight = array + i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (*(array + j) < *smallestFromRight)
                smallestFromRight = (array + j);
        }

        if (*smallestFromRight < *(array + i))
        {
            Swap(array + i, smallestFromRight);
        }
    }
}

// Compare and swap with adjucent element on the right if needed
void Sorting::BubleSort(int *array, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        bool sorted = true;
        for (int j = 0; j <= n - 2; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                Swap((array + j), (array + j + 1));
                sorted = false;
            }
        }

        if (sorted)
            break;
    }
}

void Sorting::MergeSort(int *array, int left, int right)
{
    if (left >= right)
        return;

    // find mid
    auto mid = left + (right - left) / 2;

    // copy left from mid to new array
    int *leftArray = new int[100];
    for (int i = 0; i <= mid; i++)
    {
        leftArray[i] = array[i];
    }

    // copy right from mid to new array
    int *RightArray = new int[100];
    for (int i = mid + 1; i <= right; i++)
    {
        RightArray[i] = array[i];
    }

    MergeSort(leftArray, left, mid);
    MergeSort(RightArray, mid + 1, right);

    Merge(leftArray, RightArray, array, left, right);
}

void Sorting::MergeSort2(int *array, int left, int right)
{
    if (left >= right)
        return;

    // find mid
    auto mid = left + (right - left) / 2;

    MergeSort(array, left, mid);
    MergeSort(array, mid + 1, right);

    Merge2(array, left, right);
}

void Sorting::QuickSort(int *array, int left, int right)
{
    if (left >= right)
        return;

    int pivot = Partition(array, left, right);
    QuickSort(array, left, pivot - 1);
    QuickSort(array, pivot + 1, right);
}

void Sorting::Swap(int *ele1, int *ele2)
{
    auto temp = *ele1;
    *ele1 = *ele2;
    *ele2 = temp;
}

void Sorting::Merge(int *array1, int *array2, int *array, int left, int right)
{
    auto mid = left + (right - left) / 2;
    auto i = left;
    auto j = mid + 1;
    auto k = left;

    while (i <= mid && j <= right)
    {
        if (array1[i] < array2[j])
        {
            array[k] = array1[i];
            i++;
            k++;
        }
        else
        {
            array[k] = array2[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        array[k] = array1[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        array[k] = array2[j];
        j++;
        k++;
    }
}

void Sorting::Merge2(int *array, int left, int right)
{

    auto mid = left + (right - left) / 2;

    // right arrays size
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int a[10];
    int b[10];

    for (int i = 0; i < n1; i++)
    {
        a[i] = *(array + left + i);
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = *(array + mid + 1 + i);
    }

    auto i = 0;
    auto j = 0;
    auto k = left;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            array[k] = a[i];
            i++;
        }
        else
        {
            array[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = b[j];
        j++;
        k++;
    }
}

int Sorting::Partition(int *array, int left, int right)
{
    int pivot = array[right];
    // int i = left;
    // for (int j = left; j <= right - 1; j++)
    // {
    //     if (array[j] < array[pivot])
    //     {
    //         swap(array[j], array[i]);
    //         i++;
    //     }
    // }
    // swap(array[i], array[right]);
    // return i;

    int count = 0;
    for (int i = left; i <= right; i++)
    {
        if (array[i] < pivot)
            count++;
    }
    count += left;

    swap(array[count], array[right]);

    int i = left;
    int j = right;

    while (i < count && j > count)
    {
        if (array[i] > pivot && array[j] < pivot)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }

        if (array[i] < array[count])
        {
            i++;
        }

        if (array[j] > array[count])
        {
            j--;
        }
    }

    return count;
}
