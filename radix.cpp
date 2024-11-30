#include <iostream>
using namespace std;

class radix
{
public:
    int n;

    int maxdigit(int arr[], int n)
    {
        int max = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max; // Return the largest element.
    }

    // Counting sort used for sorting based on a particular digit (exponent).
    // 'exp' is used to extract the digit (1's place, 10's place, etc.)
    void countSort(int arr[], int n, int exp)
    {
        int output[n];       // Temporary output array to store sorted results.
        int count[10] = {0}; // Count array to store occurrences of each digit (0-9).

        // Count the occurrences of digits at the current 'exp' place.
        for (int i = 0; i < n; i++)
        {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
    }
    void radixSort(int arr[], int n)
    {
        int max = maxdigit(arr, n);

        // Apply counting sort to sort elements based on each digit
        for (int exp = 1; max / exp > 0; exp *= 10)
        {
            countSort(arr, n, exp); // Sort the array based on the current digit.
        }
    }

    void radixsort()
    {
        cout << "Enter the number of elements you want to store: ";
        cin >> n;
        int arr[n];

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        radixSort(arr, n);

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
    radix rs;
    rs.radixsort();
    return 0;
}
