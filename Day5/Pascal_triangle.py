class Solution:
    def generate(self, numRows: int) -> List[List[int]]:

        if numRows == 1:
            return [[1]]
        
        arr = [[0 for i in range(1)] for j in range(numRows)]

        for i in range(1,numRows):
            for j in range(i):
                arr[i].append(0)

        arr[0][0] = 1
        arr[1][0] = 1
        arr[1][1] = 1

        if numRows == 2:
            return arr

        for i in range(numRows):
            arr[i][0] = 1 
        
        for i in range(numRows):
            arr[i][i] = 1

        for i in range(2,numRows):
            for j in range(1,i):
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j]

        return arr
