class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        N, result = len(nums), 0
        max_win, min_win = deque([]), deque([])
        l = 0
        for r in range(N):
            while max_win and nums[max_win[-1]] < nums[r]:
                max_win.pop()

            while min_win and nums[min_win[-1]] > nums[r]:
                min_win.pop()
            
            max_win.append(r)
            min_win.append(r)
            while nums[max_win[0]] - nums[min_win[0]] > limit:
                if max_win[0] < min_win[0]:
                    l = max(l, max_win[0] + 1)
                    max_win.popleft()
                else:
                    l = max(l, min_win[0] + 1)
                    min_win.popleft()
            result = max(result, r - l + 1)
        
        return result