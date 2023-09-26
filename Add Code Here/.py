class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        # Check rows
        for row in board:
            digits = []
            for cell in row:
                if cell != '.':
                    if cell in digits:
                        return False
                    digits.append(cell)

        # Check columns
        for col in range(9):
            digits = []
            for row in range(9):
                cell = board[row][col]
                if cell != '.':
                    if cell in digits:
                        return False
                    digits.append(cell)

        # Check subgrids
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                digits = []
                for x in range(i, i + 3):
                    for y in range(j, j + 3):
                        cell = board[x][y]
                        if cell != '.':
                            if cell in digits:
                                return False
                            digits.append(cell)

        return True
