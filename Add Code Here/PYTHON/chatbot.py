# -*- coding: utf-8 -*-
import nltk
from nltk.chat.util import Chat, reflections

reflections = {
  "i am"       : "you are",
  "i was"      : "you were",
  "i"          : "you",
  "i'm"        : "you are",
  "i'd"        : "you would",
  "i've"       : "you have",
  "i'll"       : "you will",
  "my"         : "your",
  "you are"    : "I am",
  "you were"   : "I was",
  "you've"     : "I have",
  "you'll"     : "I will",
  "your"       : "my",
  "yours"      : "mine",
  "you"        : "me",
  "me"         : "you",

}
pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, How are you today ?",]
    ],
    [
        r"hi|hey|hello",
        ["Hello", "Hey there",]
    ], 
    [
        r"what is your name ?|your name|name please",
        ["I am Y2K. You can call me crazy individual!",]
    ],
    [
        r"how are you ?|how you doing|what about you|how about you ?",
        ["I'm doing good. How can I help you ?",]
    ],
    [
        r"sorry (.*)",
        ["Its alright","Its OK, never mind",]
    ],
    [
        r"I am fine",
        ["Great to hear that, How can I help you?",]
    ],
    [
        r"(.*) continents",
        ["Asia, Africa, North America, South America, Antarctica, Europe, and Australia ",]
    ],
    [
     r"(.*) (english|hollywood) movie",
     ["The Shawshank Redemption", " The Lord of the Rings: The Return of the King","Inception", "Interstellar", "Parasite", "Twilight", "Fast & Furious", "Lucky one","A walk to remember", "The Last Song", "The Notebook","The Fault in Our Stars", "Joker", "Me Before You", "All the boys have met before","Kissing booth", "Titanic",]
    ],
    [
        r"i'm (.*) doing good",
        ["Nice to hear that","How can I help you?:)",]
    ],
    [
        r"(.*) age?|are you an (idiot|stupid)|what do you think you are",
        ["I'm a computer program dude....Seriously you are asking me this?",]
    ],
    [
        r"(.*) (online|free) courses",
        ["Udemy","Udacity","Great Learning","Google Digital Garage","Swayam",]
    ],
    [
        r"(.*) (news channel|news)",
        ["BCC World News","Fox News","Cable News Network (CNN)","Sky News","MSNCB","Republic World","ZEE News","ABP News",]
    ],
    [
     r"(.*) (horror|spooky) movie",
     ["The Nun", "Annabelle", "The conjuring", "Sinister", "The cabin in the wood", "insidious", "IT","Ouija", "Train to Busan", "The Ring", "Hush", "Evil Dead", "Oculus",]
    ],
    [
     r"(.*) (bollywood|hindi) movie",
     ["War", "My name is Khan", "Happy new year", "Dilwale", "Uri", "Don", "Don 2", "Raees","Raazi", "Kalank", "Kalank", "Dangal", "LUDO", "Good Newz", "PK", "Jab Tak Hai Jaan","Cocktail", "Bahubali", "M.S.Dhoni", "Aashiqui 2","Dear Zindagi","Anand", "Mughal-E-Azam", "Mother India", "Don ", " Parinda", "Mr. India","Mera Naam Joker", "Amar, Akbar and Anthony", " Agneepath ", "Sahib Bibi Aur Ghulam","Sholay",]
    ],
    [
     r"(.*) (webseries|series)",
     ["You", "Lucifer", "Cursed", "Mismatched", "Money Heist", "Stranger Things", "Merlin","The Protector", "Sabrina", "Dark", "Friends", "The Big Bang Theory", "Little Things","Lock & Key", "Sherlock", "Sweet Tooth", "The Witcher", "Shadow and Bones","Never Have i ever", "Brooklyn Nine-Nine", "Ragnarok", "Originals", "Vampire Diaries","The Order", "The Boss Baby", "The Haunting of Hill House", "Pup Academy", "Mary Queen of Scots","Bitten", "Titans", "Warrior Nun","The Haunting of bly Manor",]
    ],
    [
     r"(.*) k-drama",
     ["descendants of the sun","busted", "her private life", "whats wrong with secretary kim","its okay to not be okay", "hospital playlist", "crash landing on you","weightlifting fairy kim bok joo", "my first first love", "beauty inside", "was it love",]
    ],
    [
     r"(.*) (novel|book)",
     ["Harry Potter", "Twilight", "Alchemist", "Angel And Demon", "Dead Beautiful", "Lost Symbol", "The Vinche Code", "Hunger Games",]
    ],
    [
        r"(.*) created ?",
        ["I am created using Python's NLTK library ","top secret",]
    ],
    [
        r"(.*) band",
        ["BTS", "The Beatles", "The rolling stones", "Maroon 5", "One Direction", "No Doubt","Black Pink", "EXO", "MonstaX", "Stray Kids","The chainsmokers",]
    ],
    [
        r"(.*) actress",
        ["Scarlett Johansson", "Jennifer Lawrence", "Emma Watson", " Margot Robbie","Angelina Jolie", "Kristen Stewart", "Rachel McAdams","Deepika Padukone", "Priyanka Chopra", "Alia Bhatt", "Kareena Kapoor","Nora Fatehi", "Jacqueline Fernandez", "Aishwarya Rai", "Sara Ali Khan", "Shraddha Kapoor","Anushka Sharma", "Disha Patani",]
    ],
    [
        r"(.*) (game|sport)",
        ["Cricket","Hockey", "Basketball", "Football", "Baseball","Badminton", "Tennis", "Swimming", "Archery","Skates", "Volleyball", "Table Tennis", "Golf",]
    ],
    [
        r"(.*) (sports person|player)",
        ["Lionel Messi","Sania Mirza", "Sachin Tendulkar", "Virat Kohli", "Kevin Durant","Hardik Pandya", "Rohit Sharma", "P. V. Sindhu", "Parupalli Kashyap","Sania Mirza", "Dhyan Chand", "Cristiano Ronaldo", "Robert Lewandowski","Chris Gayle", "Steve Smith", "David Warner", "Ricky Ponting","Stephen Curry", "LeBron James", "M.S.Dhoni", "Chris Paul",]   
    ],
    [
        r"(.*) actor",
        ["Robert Downey, Jr.", "Chris Hemsworth", "Tom Holland", "Brad Pitt","Tom Hiddleston", "Tom Cruise", "Chris Evans", "Benedict Cumberbatch","Paul Rudd", "Jeremy Renner", "Ian Somerhalder ","Paul Wesley", "Aamir Khan", "Amitabh Bachchan","Anil Kapoor", "Ranveer Singh", "Ranbir Kapoor", "Salman Khan","Sanjay Dutt", "Shah Rukh Khan", "Tiger Shroff", "Varun Dhawan",]
    ],
    [
     r"(.*) dialogue",
     ["Mere paas maa hai.","Pushpa, I hate tears…","Kitne aadmi the!","Babumoshai, zindagi badi honi chahiye, lambi nahi.","Rishtey mein toh hum tumhare baap lagte hai, naam hai Shahenshaah!","Dosti ka ek usool hai madam – no sorry, no thank you.","Mogambo khush hua!","Hum jahan khade hote hain line yahi se shuru hoti hai.","Bade bade deshon mein aisi choti-choti baatein hoti rehti hai, Senorita.","Haar kar jeetne wale ko baazigar kehte hai.","Mere Karan Arjun aayenge.","Agar maa ka doodh piya hai toh samne aa!","Uska to na bad luck hi kharab hai.","Crime Master Gogo naam hai mera, aankhen nikal ke gotiyan khelta hun main.","Tareekh pe tareekh, tareekh pe tareekh, tareekh pe tareekh milti gayi My Lord, par insaaf nahi mila","Rahul, naam toh suna hi hoga.","Mein apni favourite hoon!","Picture abhi baaki hai mere dost!","How’s the josh?","Thappad se darr nahi lagta sahab, pyaar se lagta hai.","Filmein sirf teen cheezo ke wajah se chalti hai…entertainment, entertainment, entertainment…aur main entertainment hoon.","All izz well",]
    ],
    [
        r"quit",
        ["Bye take care. See you soon :) ","It was nice talking to you. See you soon :)",]
    ],
    [
        r"(.*) joke",
        ["Why did the tomato blush? Because it saw the salad dressing.","What do you call bears with no ears? B","What do dentists call X-rays? Tooth pics.","Did you hear about the first restaurant to open on the moon? It had great food, but no atmosphere.","What did one wall say to the other wall? I’ll meet you at the corner.","When does a joke become a “dad” joke? When the punchline is apparent.","What did the paper say to the pencil? Write on!","How did the bullet lose its job? It got fired.","Why should you never trust stairs? They are always up to something.","Sometimes I tuck my knees into my chest and lean forward.That’s just how I roll.","What do you call a cheese that’s not yours? Nacho cheese!","Did you hear about the cheese factory that exploded in France?There was nothing left but de Brie.",]
    ],
    [
        r"even me",
        ["That's great"]
    ],
    [
        r"thank you",
        ["Your welcome , would you like to know something else if no then please type in QUIT to exit",]
    ],
]
def chat():
    print("Hi! I am Y2K..")
    chat = Chat(pairs, reflections)
    chat.converse()

#initiate the conversation
if __name__ == "__main__":
    chat()
