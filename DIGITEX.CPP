#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class hashh {
public:
    void digitExtraction() {
        int n, a, pos, collision = 0;

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

        cout << "Enter the digit position to extract (1 for unit place, 2 for tens, etc.): ";
        cin >> pos;

        for (int i = 0; i < n; i++) {
            int key = arr[i];
            string keyStr = to_string(key);
            reverse(keyStr.begin(), keyStr.end());  // Reverse string to extract digit easily

            int extractedDigit = 0;
            if (pos - 1 < keyStr.length()) {
                extractedDigit = keyStr[pos - 1] - '0';  // Extract digit at the given position
            }

            int loc = extractedDigit % a;  // Hash location
            while (hash[loc] != 0) {  
                loc = (loc + 1) % a;
                collision++;
            }
            hash[loc] = key;  
        }

        for (int i = 0; i < a; i++) {
            cout << i << ": " << hash[i] << endl;
        }

        cout << "Collisions: " << collision << endl;  // Output the number of collisions
    }
};

int main() {
    hashh h;
    h.digitExtraction();
    return 0;
}
