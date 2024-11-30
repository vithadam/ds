#include <iostream>
using namespace std;

class Select {
public:
    int n;

    void selectt() {
        cout << "Enter how many elements you want to store: ";
        cin >> n;
        int arr[n];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

      

       
        for (int i = 0; i < n - 1; i++) {
            int min = i;  

           
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }

          
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;

cout << "array after " << i+1 << " pass is: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

       
        cout << "The sorted array is: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
      
       
    }
};

int main() {
    Select s;
    s.selectt();
    return 0;
}
