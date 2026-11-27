class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)] # right, down, left, up
        i = j = d = 0
        res = []
        vis = [[False] * n for _ in range(m)]

        for _ in range(m*n):
            res.append(matrix[i][j])
            vis[i][j] = True
            ni, nj = i + dirs[d][0], j + dirs[d][1]
            if not(0 <= ni < m and 0 <= nj < n) or vis[ni][nj]:
                d = (d+1)%4
                ni, nj = i + dirs[d][0], j + dirs[d][1]
            i, j = ni, nj
        
        return res
                
        
        