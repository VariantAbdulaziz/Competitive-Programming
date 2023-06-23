#User function Template for python3

class Solution: 
    def select(self, arr, i):
        _min = arr[i]
        min_idx = i
        for j in range(i, len(arr)):
            if arr[j] < _min:
                min_idx = j
                _min = arr[j]
        
        return min_idx
    
    def selectionSort(self, arr,n):
        #code here
        for i in range(len(arr)):
            rp = self.select(arr, i)
            arr[i], arr[rp] = arr[rp], arr[i]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        Solution().selectionSort(arr, n)
        for i in range(n):
            print(arr[i],end=" ")
        print()
# } Driver Code Ends