// // source: https://www.hackerrank.com/challenges/ctci-bubble-sort/problem

void countSwaps(vector<int> a) {
    
    int n = a.size();
    int numSwaps{};
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                numSwaps++;
            }
        }
    }
    std::cout << "Array is sorted in " << numSwaps << " swaps." << std::endl;
    std::cout << "First Element: " << a[0] << std::endl;
    std::cout << "Last Element: " << a[n - 1] <<  std::endl;
}