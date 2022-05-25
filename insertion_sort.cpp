// source: https://www.hackerrank.com/challenges/insertionsort1/problem

// strategy: ad hoc solution
void print(int n, const vector<int>& arr){
    
    for(int i{}; i < n; i ++){
        std::cout << arr[i] << " " ;
    }
}

void insertionSort1(int n, vector<int> arr) {
    
    for(int i=1; i < n; i ++){
        
        int temp = arr[i];  
        int j= i-1;  
        while(j>=0 && temp <= arr[j])  
        {  
            arr[j+1] = arr[j];  
            j = j-1;
            print(n, arr);
            std::cout << std::endl;
        }
        arr[j+1] = temp;
    }
    print(n, arr);
}