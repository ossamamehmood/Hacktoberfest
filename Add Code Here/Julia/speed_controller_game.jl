using UnicodePlots
using KeyboardInterrupt

# Constants
character = '🚗'
road_length = 30
max_speed = 5
acceleration = 1
deceleration = 1

function draw_game(character_position)
    game_state = fill(' ', road_length)
    game_state[character_position] = character
    println(plot(game_state, border = :none))
end

function main()
    character_position = 1
    speed = 0

    while true
        draw_game(character_position)

        # Check for user input
        key = getch(stdin)
        if key == 'a' && speed > -max_speed
            speed -= acceleration
        elseif key == 'd' && speed < max_speed
            speed += acceleration
        elseif key == 's'
            speed = 0
        end

        # Update character position
        character_position += speed

        # Ensure character stays on the road
        character_position = max(1, min(road_length, character_position))
    end
end

main()
