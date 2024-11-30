#include <iostream>
using namespace std;

class quick
{
public:
    int n;

    void swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // it will make a partition
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void quicksort()
    {
        cout << "Enter the number of elements you want to store: ";
        cin >> n;
        int arr[n];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        quickSort(arr, 0, n - 1);

        cout << "Sorted array is: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    quick q;
    q.quicksort();
    return 0;
}
