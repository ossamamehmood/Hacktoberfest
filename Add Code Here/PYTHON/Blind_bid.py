from replit import clear

players = {}
more_players = True
while more_players:
  name = input("What is your name? ")
  bid_amount = int(input("How much amount you want to bid? "))
  players[name] = bid_amount

  next_player = input("Is there any more bidders? 'yes' or 'no': ").lower()
  if next_player == 'no':
    break
  elif next_player == 'yes':
    clear()

clear()
max_bidded_amount = max(players.values())
max_bidder = max(players, key=players.get)

print(f"The highest bid was made by {max_bidder} of ${max_bidded_amount}")
