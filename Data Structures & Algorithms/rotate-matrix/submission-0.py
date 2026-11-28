class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        m = len(matrix)
        n = len(matrix[0])
        vis = [[False] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if i != j and not vis[i][j]:
                    matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
                    vis[i][j] = True
                    vis[j][i] = True

        for row in matrix:
            row.reverse()

        
        