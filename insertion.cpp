#include <iostream>
using namespace std;

class Insert {
public:
    int n;

    void insertt() {
        cout << "Enter how many elements you want to store: ";
        cin >> n;
        int arr[n];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        } 

     
        for (int i = 1; i < n; i++) {
            int k = arr[i];
            int j = i - 1;

            
            while (j >= 0 && arr[j] > k) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = k;

          cout << "array after " << i << " pass is: ";
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
    Insert i;
    i.insertt();
    return 0;
}
