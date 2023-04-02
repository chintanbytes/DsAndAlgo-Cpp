class Searching
{
private:
    /* data */
public:
    Searching(/* args */);
    ~Searching();
    bool BinarySearch(int *array, int length, int key);
    bool BSearchRecursive(int *array, int key, int start, int end);
};

Searching::Searching(/* args */)
{
}

Searching::~Searching()
{
}

bool Searching::BinarySearch(int *array, int length, int key)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (*(array + mid) == key)
            return true;
        else if (*(array + mid) < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}

bool Searching::BSearchRecursive(int *array, int key, int start, int end)
{
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    // if mid is the key, return true
    if (*(array + mid) == key)
        return true;
    // if mid is > key, Call recursive with array left from mid and same key
    else if (*(array + mid) > key)
    {
        return BSearchRecursive(array, key, start, mid - 1);
    }
    // if mid is < key, Call recursive with arary right from mid and same key
    else
    {
        return BSearchRecursive(array, key, mid + 1, end);
    }
}
