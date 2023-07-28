class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        zeroes = 0
        l = 0
        longest = 0
        for r in range(len(nums)):
            zeroes += 1 - nums[r]
            while l <= r and zeroes > 1:
                zeroes -= 1 - nums[l]
                l += 1
            
            longest = max(longest, r - l)
        
        return longest