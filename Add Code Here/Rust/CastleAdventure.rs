use std::collections::HashMap;
use std::io;

// Define a structure for a Room
struct Room {
    name: String,
    description: String,
    exits: HashMap<String, String>, // Exit name -> Room name
    items: Vec<String>,
}

impl Room {
    fn new(name: &str, description: &str) -> Room {
        Room {
            name: name.to_string(),
            description: description.to_string(),
            exits: HashMap::new(),
            items: Vec::new(),
        }
    }

    fn add_exit(&mut self, exit_name: &str, destination_room: &str) {
        self.exits.insert(exit_name.to_string(), destination_room.to_string());
    }

    fn add_item(&mut self, item_name: &str) {
        self.items.push(item_name.to_string());
    }
}

fn main() {
    println!("Welcome to the Text Adventure Game!");
    println!("You find yourself in a mysterious castle. Can you find the hidden treasure?");

    let mut rooms: HashMap<String, Room> = HashMap::new();

    // Create rooms and set their exits
    let mut room1 = Room::new("Entrance Hall", "You are in a grand entrance hall.");
    let mut room2 = Room::new("Library", "You are in a dusty old library.");
    let mut room3 = Room::new("Treasure Room", "You found the treasure room!");
    
    room1.add_exit("north", "Library");
    room2.add_exit("south", "Entrance Hall");
    room2.add_exit("east", "Treasure Room");
    room3.add_exit("west", "Library");

    // Add items to rooms
    room1.add_item("key");
    room2.add_item("book");
    room3.add_item("treasure chest");

    rooms.insert(room1.name.clone(), room1);
    rooms.insert(room2.name.clone(), room2);
    rooms.insert(room3.name.clone(), room3);

    let mut current_room = "Entrance Hall".to_string();

    loop {
        println!("You are in the {}.", current_room);

        if current_room == "Treasure Room" {
            println!("Congratulations! You found the hidden treasure!");
            break;
        }

        println!("Exits: {:?}", rooms[&current_room].exits.keys());

        if !rooms[&current_room].items.is_empty() {
            println!("You see some items here: {:?}", rooms[&current_room].items);
        }

        println!("What would you like to do? (Type 'exit' to quit)");

        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        let input = input.trim().to_lowercase();

        if input == "exit" {
            println!("Thanks for playing! Goodbye.");
            break;
        } else if rooms[&current_room].exits.contains_key(&input) {
            current_room = rooms[&current_room].exits[&input].clone();
        } else if input == "look around" {
            println!("{}", rooms[&current_room].description);
        } else if input.starts_with("take ") {
            let item_name = input.trim_start_matches("take ");
            if rooms[&current_room].items.contains(&item_name.to_string()) {
                rooms.get_mut(&current_room).unwrap().items.retain(|item| item != item_name);
                println!("You took the {}.", item_name);
            } else {
                println!("There's no {} here to take.", item_name);
            }
        } else {
            println!("Invalid command. Try 'look around', 'take <item>', or an exit direction.");
        }
    }
}
