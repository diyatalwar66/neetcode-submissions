class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows = []
        cols = []
        m = len(matrix)
        n = len(matrix[0])

        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    if i not in rows:
                        rows.append(i)
                    if j not in cols:
                        cols.append(j)

        for r in rows:
            for j in range(n):
                if matrix[r][j]!=0:
                    matrix[r][j] = 0
        
        for c in cols:
            for i in range(m):
                if matrix[i][c]!=0:
                    matrix[i][c] = 0
        


        
        