#include<iostream>
using namespace std;

class hashh {
public:
    void msquare() {
        int n, a, collision = 0;

        cout << "Enter the number of elements you want to store: ";
        cin >> n;

        
        int arr [n];
        cout << "Enter elements: ";
        for (long i = 0; i < n; i++) {
            cin >> arr[i];
        }

      
        cout << "Enter the number of hash locations: ";
        cin >> a;

      
        int hash[a];
        for (int i = 0; i < a; i++) {
            hash[i] = 0;  
        }

      
        for (int i = 0; i < n; i++) {
            int key = arr[i];
            long long squared = key * key; 

           
            int middle = (squared / 10) % 100; 

            int loc = middle % a; 
            while (hash[loc] != 0) { 
                loc = (loc + 1) % a;
                collision++; 
            }
            hash[loc] = key; 
        }

        for (int i = 0; i < a; i++) {
            cout << i << ": " << hash[i] << endl;
        }
         cout << "Collisions: " << collision << endl;
    }
    
};

int main() {
    hashh h;
    h.msquare();
    return 0;
}
