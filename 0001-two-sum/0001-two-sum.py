class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # nums[j] = target - nums[i] 
        book = defaultdict(int)
        for i in range(len(nums)):
            comp = target - nums[i]
            if nums[i] in book:
                return [book[nums[i]], i]
            book[comp] = i