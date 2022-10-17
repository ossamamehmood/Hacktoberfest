class Sol:
    def rookCaptures(self, board):
        bod = board[::]
        rows =  [[i for i in ro if i != "."] for ro in bod]
        cols = [[i for i in list(co) if i != "."]for co in list(zip(*bod))]
        
        count = 0
        rows = rows + cols
        
        for row in rows:
            if len(row) < 2:
                continue
            if "pR" in "".join(row):
                count += 1
            if "Rp" in "".join(row):
                count += 1
                
        return count
a = Sol()
print(a.rookCaptures(board = [[".",".",".",".",".",".",".","."],
                             [".",".",".","p",".",".",".","."],
                             [".",".",".","R",".",".",".","p"],
                             [".",".",".",".",".",".",".","."],
                             [".",".",".",".",".",".",".","."],
                             [".",".",".","p",".",".",".","."],
                             [".",".",".",".",".",".",".","."],
                             [".",".",".",".",".",".",".","."]]))
