class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        run = 0
        result = len(nums) + 1
        for r in range(len(nums)):
            run += nums[r]
            while run >= target:
                result = min(result, r - l + 1)
                run -= nums[l]
                l += 1
        return 0 if result == len(nums) + 1 else result
                