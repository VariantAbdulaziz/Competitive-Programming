// solution: https://practice.geeksforgeeks.org/problems/selection-sort/1

// strategy: ad hoc solution
class Solution{
public:
    int select(int arr[], int n, int i)
    {
        // code here such that selectionSort() sorts arr[]
        for(int j = i + 1; j < n; j ++){
            if(arr[j] < arr[i]) i = j;
        }
        return i;
    }
     
    void selectionSort(int arr[], int n)
    {
        
       for(int i{}; i < n - 1; i++){
           
           int minElem = select(arr, n, i);
           int temp = arr[minElem];
           arr[minElem] = arr[i];
           arr[i] = temp;
       }
    }
};