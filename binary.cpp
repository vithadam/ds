#include <iostream>
#define max 100
using namespace std;
int n, key;
int a[max];
int b;
class binary
{

public:
    void input()
    {
        cout << "Enter how many elements you want to store: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter element  " << i << ": ";
            cin >> a[i];
        }

        for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) { 
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout<<"Sorted array : ";
       for (int i = 0; i < n; i++)
        {
            cout << a[i] << " "<< endl;
           
        }
    }
    
    void search()
    {

        while (true)
        {

            cout << "Enter the element you want to search: ";
            cin >> key;
            
            int low = 0, high = n - 1;
            int pos = -1;
            
            while (low <= high)
            {
                int mid = (low + high) / 2;

                if (a[mid] == key)
                {
                    pos = mid;
                    break;
                }
                else if (a[mid] < key)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            if (pos == -1)
            {
                cout << "Element " << key << " is not found " << endl;
            }
            else
            {
                cout << "Element " << key << " is found at index " << pos << endl;
            }

            cout << "Press 1 to quit, press 0 to continue: ";
            cin >> b;
            if (b == 1)
            {
                cout << "Exiting...";
                break;
            }
        }
    };
};

int main()
{
    binary s;
    s.input();
    s.search();
    return 0;
}
