import random

# Define Uno deck with colors and values
colors = ['Red', 'Green', 'Blue', 'Yellow']
values = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'Skip', 'Reverse', 'Draw Two']

# Create Uno deck
deck = [{'color': color, 'value': value} for color in colors for value in values]

# Function to shuffle the deck
def shuffle_deck():
    random.shuffle(deck)

# Function to draw a card from the deck
def draw_card():
    if len(deck) == 0:
        print("No cards left in the deck.")
        return None
    return deck.pop()

# Initialize players and hands
players = ['Player 1', 'Player 2']
hands = {player: [] for player in players}

# Function to deal 7 cards to each player
def deal_initial_hands():
    for _ in range(7):
        for player in players:
            card = draw_card()
            if card:
                hands[player].append(card)

# Function to display a player's hand
def display_hand(player):
    print(f"{player}'s Hand:")
    for i, card in enumerate(hands[player]):
        print(f"{i + 1}. {card['color']} {card['value']}")

# Function to play a card
def play_card(player, index, discard_pile):
    card = hands[player][index]
    if is_valid_play(card, discard_pile[-1]):
        discard_pile.append(card)
        hands[player].pop(index)
        return True
    else:
        print("Invalid play. Choose another card.")
        return False

# Function to check if a card is a valid play
def is_valid_play(card, top_card):
    return card['color'] == top_card['color'] or card['value'] == top_card['value']

# Initialize the discard pile with the first card from the deck
discard_pile = [draw_card()]

# Main game loop
shuffle_deck()
deal_initial_hands()
current_player = players[0]

while True:
    print("\nTop card on the discard pile:")
    print(f"{discard_pile[-1]['color']} {discard_pile[-1]['value']}\n")
    
    display_hand(current_player)
    
    choice = input("Enter the index of the card you want to play (or 'draw' to draw a card): ")
    
    if choice == 'draw':
        card = draw_card()
        if card:
            hands[current_player].append(card)
        else:
            print("No cards left in the deck.")
    else:
        try:
            choice = int(choice) - 1
            if 0 <= choice < len(hands[current_player]) and play_card(current_player, choice, discard_pile):
                if len(hands[current_player]) == 0:
                    print(f"{current_player} wins!")
                    break
                if discard_pile[-1]['value'] == 'Reverse':
                    players.reverse()
                elif discard_pile[-1]['value'] == 'Skip':
                    current_player = players[1 - players.index(current_player)]
        except (ValueError, IndexError):
            print("Invalid input. Try again.")
    
    current_player = players[1 - players.index(current_player)]
