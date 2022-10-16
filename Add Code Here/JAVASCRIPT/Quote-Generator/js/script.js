
//Object Array to hold quotes, sources, citaitons and years
var quotes = [
	{
	quote: "Be who you are and say what you feel, because those who mind don't matter and those who matter don't mind.",
	source: "Dr. Seuss"
	},
	{
	quote: "This too, shall pass.",
	source: "Anonymous"
	},
	{
	quote: "Keep your eyes on the stars and your feet on the ground.",
	source: "Theodore Roosevelt"
	},
	{
	quote: "The only person you should try to be better than is the person you were yesterday.",
	source: "Anonymous"
	},
	{
	quote: "Never be bullied into silence. Never allow yourself to be made a victim. Accept no one's definition of your life; define yourself.",
	source: "Harvey Fierstein"
	},
	{
	quote: "Faith is the art of holding on to things your reason has once accepted, in spite of your changing moods.",
	source: "C.S. Lewis"
	},
	{
	quote: "A man who flies from his fear may find that he has only taken a shortcut to meet it.",
	source: "Sador", 
	citation: "Children of Húrin" 
	},
	{
	quote:  "Life's too mysterious to take too serious.",
	source: "Mary Engelbreit"
	},
	{
	quote: "No one can make you feel inferior without your consent.",
	source: "Eleanor Roosevelt"
	},
	{
	quote: "The woman who follows the crowd will usually go no further than the crowd. The woman who walks alone is likely to find herself in places no one has been before.",
	source: "Albert Einstein"
	},
	{
	quote: "You can't go around building a better world for people. Only people can build a better world for people. Otherwise it's just a cage.",
	source: "Terry Pratchett", 
	citation: "Witches Abroad",
	year: "1991" 
	},
	{
	quote: "There isn't a way things should be. There's just what happens, and what we do.",
	source: "Terry Pratchett", 
	citation: "A Hat Full of Sky" 
	},
	{
	quote: "It's not about how hard you can hit; it's about how hard you can get hit and keep moving forward.",
	source: "Rocky Balboa",
	citation: "Rocky",
	year: "1976"
	},
	{
	quote: "More fuck yeah, less fuck that.",
	source: "Anonymous"
	},
	{
	quote: "If you want to go fast, go alone. If you want to go far, go together.",
	source: "African proverb"
	},
	{
	quote: "It's OK to not be OK, as long as you don't stay that way.",
	source: "Anonymous"
	},
	{
	quote: "I can be changed by what happens to me but I refuse to be reduced by it.",
	source: "Maya Angelou"
	},
	{
	quote: "Believe you can and you're halfway there.",
	source: "T. Roosevelt"
	},
	{
	quote: "May I never be complete. May I never be content. May I never be perfect.",
	source: "Chuck Palahniuk"
	},
	{
	quote: "Nothing in life is to be feared; it is only to be understood. Now is the time to understand more so that we may fear less.",
	source: "Marie Curie"
	},
	{

	quote: "Those who don't believe in magic will never find it.",
	source: "Roald Dahl"
	},
	{
	quote: "There is no elevator to success  you have to take the stairs.",
	source: "Anonymous"
	},
	{
	quote: "Plant your garden and decorate your own soul, instead of waiting for someone to bring you flowers.",
	source: "Jose Luis Borges"
	},
	{
	quote: "It does not do to dwell on dreams and forget to live.",
	source: "Albus Dumbledore", 
	citation: "Harry Potter and the Sorcerer's Stone",
	year: "1997"
	},
	{
	quote: "Don't sweat the petty things and don't pet the sweaty things.",
	source: "George Carlin"
	},
	{
	quote: "Do what you feel in your heart to be right, for you'll be criticized anyway.",
	source: "Eleanor Roosevelt"
	},
	{
	quote: "Do not set yourself on fire in order to keep others warm.",
	source: "Anonymous"
	},
	{
	quote: "The way I see it, every life is a pile of good things and bad things. The good things don't always soften the bad things, but vice versa, the bad things don't always spoil the good things and make them unimportant.",
	source: "Doctor Who"
	},
	{
	quote: "It's supposed to be hard. If it were easy, everyone would do it.",
	source: "Jimmy Dugan",
	citation: "A League of Their Own"
	},
	{
	quote: "Ask yourself if what you're doing today will get you closer to where you want to be tomorrow.",
	source: "Anonymous"
	},
	{
	quote: "Life may not be the party we hoped for, but while we're here, we should dance.",
	source: "Anonymous"
	},
	{
	quote: "Never cowardly or cruel. Never give up, never give in.",
	source: "Doctor Who"
	},
	{
	quote: "Do not go where the path may lead, go instead where there is no path and leave a trail.",
	source: "Ralph Waldo Emerson"
	},
	{
	quote: "In 20 years, you probably won't even remember this.",
	source: "Anonymous"
	},
	{
	quote: "Love all, trust a few, do wrong to none.",
	source: "William Shakespeare"
	},
	{
	quote: "Clear eyes, full hearts, can't lose.",
	source: "Dillon Panthers",
	citation: "Friday Night Lights",
	year: "1990"
	},
	{
	quote: "We are what we repeatedly do. Excellence, then, is not an act, but a habit.",
	source: "Aristotle"
	}
];

//Function to randomly select a quote value and return a random quote object from the quotes array
function getRandomQuote () {
	var randomNumber = Math.floor(Math.random() * (quotes.length));
	var randomQuote = quotes[randomNumber];
	return randomQuote;
}	

//Function to select random rgb color value
function getRandomColor () {
	var red = Math.floor(Math.random() * 256 );
	var green = Math.floor(Math.random() * 256 );
	var blue = Math.floor(Math.random() * 256 );
	 var randomColor = 'rgb(' + red + ',' + green + ',' + blue + ')';
	return randomColor;
}

//Function to call the getRandomQuote function and stores the returned quote object in a variable
//Constructs a string containing the different properties of the quote object 
function printQuote () {
		var quotes = getRandomQuote ();
		var quoteContainer = document.getElementById("quote-box");
		var quoteString = `<p class="quote">${quotes.quote}</p><p class="source">${quotes.source}`;
				if (quotes.citation) {quoteString += `<span class="citation">${quotes.citation}</span>`}
				if (quotes.year) {quoteString += `<span class="year">${quotes.year}</span></p>`}
				else {quoteString += '</p>'};
					quoteContainer.innerHTML = quoteString;

					//assigns random color value to document background color 
					document.body.style.backgroundColor = getRandomColor ();
}

//Quote automatically refreshes every 15 seconds
window.setInterval(function(){
printQuote ();
}, 15000);

//Event listener on LoadQuote button to generate new quote		
document.getElementById("loadQuote").addEventListener("click", printQuote, false);






	
