//Console.log a tree with a trunk
function tree(length) {
	for (i = 1; i <= length; i++) {
		console.log("*".repeat(i));
	}
	console.log("*".repeat(length));
}
tree(10);

// That's a lot of code to write for a tree.  I wonder if there is a way to make it shorter?

// If 200 does not equal 3, make a bigger tree
if (200 !== 3) {
	tree(100);
}
