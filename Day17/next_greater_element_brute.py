class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        #BRUTE FORCE APPROACH
        op = []

        for i in nums1:
            ind = nums2.index(i)
            flag = 0

            #find greater element
            for j in range(ind+1,len(nums2)):
                if nums2[j] > i:
                    op.append(nums2[j])
                    flag = 1
                    break
            
            #if there is no element set value to -1
            if flag == 0:
                op.append(-1)

        return op
            
