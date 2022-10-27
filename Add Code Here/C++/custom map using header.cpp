class Map {
	static class Map* root;

	// Number of elements in the map
	static int cnt;

	// Left child, right child and parent
	Map *left, *right, *par;

	// First is key, second is value
	// and depth is height of the subtree
	// for the given node
	int first, second, depth;
};
