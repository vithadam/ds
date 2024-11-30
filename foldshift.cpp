#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class hashh {
public:
    void foldShifting() {
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
            hash[i] = 0; 
        }

        for (int j = 0; j < n; j++) {
            int k = arr[j];
            int h = foldShiftingHash(k, a); // Calculate initial hash location
            
            // Handle collisions using linear probing
            while (hash[h] != 0) {
                collision++;     
                h = (h + 1) % a; 
            }
            hash[h] = k;  // Insert element into the hash table
        }

        for (int i = 0; i < a; i++) {
            cout << i << ": " << hash[i] << endl;
        }

        cout << "Collisions: " << collision << endl;
    }

    int foldShiftingHash(int key, int a) {
        int value = 0;
        int len = to_string(a).length(); // Length of the number of hash locations
        string keyStr = to_string(key);  // Convert key to string for digit extraction

        for (int i = keyStr.length(); i > 0; i -= len) {
            int start = max(0, i - len);
            string part = keyStr.substr(start, i - start); // Extract part of the key
            value += stoi(part); // Add extracted part to value

            // Restrict value to the last 'len' digits
            int max_value = 1;
            for (int j = 0; j < len; j++) {
                max_value *= 10; // Calculate 10^len
            }
            value = value % max_value; // Keep last 'len' digits
        }
        return value % a; // Return final hash location
    }
};

int main() {
    hashh h;  
    h.foldShifting(); 
    return 0;  
}
