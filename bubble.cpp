#include <iostream>
using namespace std;
class bubble
{
public:
    int n;
    void buble()
    {
        cout << "Enter the number of elements you want to store  ";
        cin >> n;
        int arr[n];
        cout << "Enter elements ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {

            for (int j = 0; j < n - 1 - i; j++)
            {
                
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            cout << "array after " << i + 1 << " pass is: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        cout << "Sorted array is: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    };
};
int main()
{
    bubble b;
    b.buble();
    return 0;
}
