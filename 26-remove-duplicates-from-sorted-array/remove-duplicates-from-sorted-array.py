class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        left =0
        right=0

        while right < len(nums):
            if nums[right] == nums[left]:
                right += 1
            else:
                if left < len(nums)-1:
                    left += 1
                    nums[left] = nums[right]
                    right += 1
        
        return left+1