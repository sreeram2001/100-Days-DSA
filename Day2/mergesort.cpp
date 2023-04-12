Select tags
0/5
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        #mergesort implementation
        def mergesort(arr):

            if len(arr) > 1:

                #get mid element to split array
                mid = len(arr)//2

                #split the array into two
                arr_l = arr[:mid]
                arr_r = arr[mid:]

                #recrusive call to left and right halves
                mergesort(arr_l)
                mergesort(arr_r)

                i = j = k = 0

                #compare, swap and sort the elements
                while i<len(arr_l) and j<len(arr_r):
                    if arr_l[i] < arr_r[j]:
                        arr[k] = arr_l[i]
                        i += 1
                    else:
                        arr[k] = arr_r[j]
                        j += 1
                    k += 1
                
                while i<len(arr_l):
                    arr[k] = arr_l[i]
                    i += 1
                    k += 1
                
                while j<len(arr_r):
                    arr[k] = arr_r[j]
                    j += 1
                    k += 1

            return arr

        op = mergesort(nums)
        return op
