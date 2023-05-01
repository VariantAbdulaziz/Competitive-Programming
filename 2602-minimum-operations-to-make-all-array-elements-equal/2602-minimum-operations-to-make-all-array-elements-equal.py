class Solution:
    def solve(self, nums, prefix_sum, query):
        # solve ans for each query
        lower_bound = bisect_left(nums, query)
        upper_bound = bisect_right(nums, query)
        ans = 0
        lower_expected = query * lower_bound
        lower_actual = prefix_sum[lower_bound]
        
        ans += lower_expected - lower_actual
        
        upper_expected = query * (len(nums) - upper_bound)
        upper_actual = prefix_sum[-1] - (0 if upper_bound == 0 else prefix_sum[upper_bound])
        ans += upper_actual - upper_expected
        
        return ans
            
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        
        
        # initialize answer array
        ans = []
        # sort the array
        nums.sort()
        # initialize the prefix sum
        prefix_sum = [0 for i in range(len(nums) + 1)]
        for i in range(len(nums)):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        for query in queries:
            ans.append(self.solve(nums, prefix_sum, query))
            
        return ans
        