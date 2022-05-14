// source: https://www.hackerrank.com/challenges/countingsort1/problem

vector<int> countingSort(vector<int> arr) {
    #define SIZE 100
    vector<int> result(SIZE, 0);
    
    int n = arr.size();
    
    for(int i{}; i < n; i++){
        result[arr[i]]++;
    }
    return result;
}