class Sorting
{
private:
    void Swap(int *, int *);

public:
    Sorting(/* args */);
    ~Sorting();
    void SelectionSort(int *array, int n);
    void BubleSort(int *array, int n);
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
        int *smallestFromRight = nullptr;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (smallestFromRight == nullptr || *(array + j) < *smallestFromRight)
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
    for (int i = 1; i < n; i++)
    {
        bool sorted = true;
        for (int j = 0; j < n - 1; j++)
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

void Sorting::Swap(int *ele1, int *ele2)
{
    auto temp = *ele1;
    *ele1 = *ele2;
    *ele2 = temp;
}
