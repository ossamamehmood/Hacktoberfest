/*
	Time complexity: O(1) for all operations.
	Space Complexity: O(S + N)
	
	Where S is the size of the array, 
    N is the number of stacks.
*/

class NStack
{
    // Array to implement the stacks.
    vector<int> arr;

    // Array to keep track of the indices of the top elements of every stack.
    vector<int> top;

    int n, s;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;

        // Create the arrays.
        arr = vector<int>(s);
        top = vector<int>(n);

        // Initialise the 'top' array.
        int count = s / n;
        for (int i = 0; i < n; i++)
        {
            top[i] = i * count - 1;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (top[m - 1] >= ((m * s) / n - 1))
        {
            // Stack overflow. So, element cannot be inserted.
            return false;
        }

        // Update the index of the new top element.
        top[m - 1]++;

        // Insert the element X into the stack.
        arr[top[m - 1]] = x;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] < (m - 1) * (s / n))
        {
            // Stack is empty. So, return -1.
            return -1;
        }

        // Pop the top element of Mth stack.
        int element = arr[top[m - 1]];

        // Update the index of the new top element.
        top[m - 1]--;

        return element;
    }
};
