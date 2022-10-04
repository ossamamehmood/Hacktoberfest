# This is an AUTOMATIC TicTacToe script written in GDScript for Godot Engine 3.x
# Ported form a JAVA script > https://github.com/fenix-hub/Hacktoberfest2022/blob/fenixhub-code/Add%20Code%20Here/JAVA/TicTacToe.java

const PLAYER_ONE: int = 1
const PLAYER_TWO: int = 2
const TOTAL_MOVES: int = 9

var grid: PoolIntArray = [[0,0,0],[0,0,0],[0,0,0]]

func _ready() -> void:
	randomize()
	
  var match_won: bool = false
  print_board()
  var current_moves: int = 0
  var current_player: int = 0
  
  while (current_moves < TOTAL_MOVES):
    current_player = int(current_moves % 2 != 0) + 1
    play_move(current_player)
    match_won = check_frame()
    if match_won:
      print("Player %s won!" % str(current_player))
      print_board()
			return
  
  print_board()
  current_moves += 1
  
  if not match_won:
    print("Game draw!")

func print_board() -> void:
  print("-------------")
  for i in range(0,3):
    for j in range(0,3):
      var line: String = ("| " if j == 0 else "") + grid[i][j] + " | "
      print(line)
    print()
    print("-------------")
    print()
  
func play_move(player: int) -> void:
	var row: int
	var column: int
	while (true):
		row = randi() % 3
		column = randi() % 3
		if (grid[row][column] == 0):
			print("%s, %s is marked!" % [row, column])
		else:
			break
	grid[row][column] = player
	
func check_frame() -> bool:
	return (check_rows() or check_columns() or check_diagonals())

func check_rows() -> bool:
	for i in grid[0].size():
		if (grid[i][0] == grid[i][1] == grid[i][2]):
			return true
	return false

func check_columns() -> bool:
	for i in grid[0].size():
		if (grid[0][i] == grid[1][i] == grid[2][i]):
			return true
	return false

func check_diagonals() -> bool:
	return (grid[0][0] == grid[1][1] == grind[2][2]) or (grid[0][2] == grid[1][1] == grid[2][0])
  
