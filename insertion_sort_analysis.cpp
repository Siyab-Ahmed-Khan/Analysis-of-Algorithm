
#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Insertion Sort Function
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to generate random array
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // random numbers between 0 and 999
    }
    return arr;
}

int main() {
    srand(time(0)); // Seed random generator

    vector<int> sizes = {5, 10, 50, 100};

    cout << "Array Size\tAverage Execution Time (nanoseconds)\n";

    for (int size : sizes) {
        long long total_time = 0;

        for (int run = 0; run < 5; run++) {
            vector<int> arr = generateRandomArray(size);

            auto start = high_resolution_clock::now();
            insertionSort(arr);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<nanoseconds>(end - start);
            total_time += duration.count();
        }

        long long average_time = total_time / 5;
        cout << size << "\t\t" << average_time << endl;
    }

    return 0;
}
