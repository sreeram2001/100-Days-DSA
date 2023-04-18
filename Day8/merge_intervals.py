class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merge = []
        intervals.sort()

        #initialise array
        arr = intervals[0]

        for i in range(len(intervals)):
            
            if (intervals[i][0] <= arr[1]):
                arr[1] = max(arr[1],intervals[i][1])
            else:
                merge.append(arr)
                arr = intervals[i]
        
        merge.append(arr)
        return merge
