class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        book = [(nums[i], i) for i in range(len(nums))]
        book.sort()
        lo, hi = 0, len(nums) - 1
        while lo < hi and book[lo][0] + book[hi][0] != target:
            if book[lo][0] + book[hi][0] < target:
                lo += 1
            else:
                hi -= 1
        
        return [book[lo][1], book[hi][1]]