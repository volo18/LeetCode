from collections import defaultdict;

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result  = [-1,-1] #init result
        myDict = defaultdict(lambda: None)

        for ii in nums:
            if myDict.get(ii) == None:
                myDict[ii] = ii

        for ii in range(len(nums)):

            diff = target - nums[ii]

            if myDict.get(diff) != None:
                result[0] = myDict[diff]
                result[1] = nums[ii]

                return result

        return result


if __name__ == "__main__":

    nums = [2,7,11,15]
    mySolution = Solution()

    print(mySolution.twoSum(nums,9))