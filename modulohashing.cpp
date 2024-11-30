#include <iostream>
using namespace std;

class hashh {
public:
    void modulo() {
        int n, a, collision = 0; 

        cout << "Enter the number of elements you want to store: ";
        cin >> n;
        int arr[n];

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Enter the number of hash locations: ";
        cin >> a;
        int hash[a];
        for (int i = 0; i < a; i++) {
            hash[i] = 0; // Initialize hash table to 0 to stop error
        }

       
        for (int i = 0; i < n; i++) {
            int loc = arr[i] % a;
            while (hash[loc] != 0) {  
                loc = (loc + 1) % a;   // Linear probing
                collision++;      
            }
            hash[loc] = arr[i];  
        }

        // Display the hash table
        for (int i = 0; i < a; i++) {
            cout << i << ": " << hash[i] << endl;
        }

        cout << "Collisions: " << collision << endl;
    }
};

int main() {
    hashh h;
    h.modulo();
    return 0;
}
