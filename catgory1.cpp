#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the total number of books produced in 'time' seconds
long long books_produced_in_time(const vector<int>& machines, long long time) {
    long long total_books = 0;
    for (int k : machines) {
        total_books += time / k;
        if (total_books >= 1e9) { // No need to count more if we exceed t
            return total_books;
        }
    }
    return total_books;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> machines(n);
    
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    // Binary search for the minimum time required to produce at least t books
    long long low = 1, high = 1LL * *min_element(machines.begin(), machines.end()) * t;
    long long answer = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (books_produced_in_time(machines, mid) >= t) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
