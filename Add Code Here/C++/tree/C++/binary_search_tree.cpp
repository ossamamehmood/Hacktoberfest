#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
};

//1-------------------------------------------------------------------------------------------------------------------------------

struct treenode *create(int data)
{
    struct treenode *newnode = new treenode;
    newnode->info = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct treenode *insertion(struct treenode *root, int data)
{
    if (root == NULL)
    {
        root = create(data);
        return root;
    }

    else if (data < root->info)
    {
        root->left = insertion(root->left, data);
    }

    else
    {
        root->right = insertion(root->right, data);
    }

    return root;
}

/*
ITERATIVE APPROACH:

void insertion(struct treenode *root , int data)
{
    struct treenode *temp , *newnode;
    newnode = new treenode;

    while(root != NULL)
    {
        temp = root;

        if(data ==  root->info)
            return;

        if(data < root->info)
            root = root->left;

        if(data > root->info)
            root = root->right;
    }

    newnode->info = data;
    newnode->left = newnode->right = NULL;

    if(newnode->info < root->info)
        root->left = newnode;
    else
        root->right = newnode;
}
*/

//2-----------------------------------------------------------------------------------------------------------------------------------------------

void preorder(struct treenode *root)
{
    if (root == NULL)
        return;

    cout << root->info << "  ";
    preorder(root->left);
    preorder(root->right);
}

//3-----------------------------------------------------------------------------------------------------------------------------------------------

void inorder(struct treenode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->info << "  ";
    inorder(root->right);
}

//4-----------------------------------------------------------------------------------------------------------------------------------------------

void postorder(struct treenode *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->info << "  ";
}

//5-----------------------------------------------------------------------------------------------------------------------------------------------

void levelorder(struct treenode *root)
{
    if (root == NULL)
        return;

    queue<treenode *> q;

    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        cout << root->info << "  ";

        if (root->left)
            q.push(root->left);

        if (root->right)
            q.push(root->right);
    }
}

//6-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *findelement(struct treenode *root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->info == data)
        return root;

    if (data < root->info)
        return (findelement(root->left, data));

    if (data > root->info)
        return (findelement(root->right, data));
}

//7-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *minimum(struct treenode *root)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL)
        return root;

    else
        minimum(root->left);
}

//8-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *maximum(struct treenode *root)
{
    if (root == NULL)
        return NULL;

    if (root->right == NULL)
        return root;

    else
        maximum(root->right);
}

//9-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *in_predecessor(struct treenode *root, int data)
{
    struct treenode *answer = NULL;

    while (1)
    {
        if (root == NULL)
            return NULL;

        else if (data < root->info)
            root = root->left;

        else if (data > root->info)
        {
            answer = root;
            root = root->right;
        }

        else
        {
            if (root->left)
                answer = maximum(root->left);
            break;
        }
    }
    return answer;
}

//10-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *in_successor(struct treenode *root, int data)
{
    struct treenode *answer = NULL;

    while (1)
    {
        if (root == NULL)
            return NULL;

        else if (data < root->info)
        {
            answer = root;
            root = root->left;
        }

        else if (data > root->info)
            root = root->right;

        else
        {
            if (root->right)
                answer = maximum(root->right);
            break;
        }
    }
    return answer;
}

//11-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *deleteelement(struct treenode *root, int data)
{
    struct treenode *temp = NULL;

    if (root == NULL)
        return NULL;

    if (data < root->info)
        root->left = deleteelement(root->left, data);

    else if (data > root->info)
        root->right = deleteelement(root->right, data);

    else
    {
        if (root->left != NULL && root->right != NULL)
        {
            temp = maximum(root->left);
            root->info = temp->info;
            root->left = deleteelement(root->left, temp->info); //important
            return root;
        }

        else if (root->left != NULL)
            return (root->left);

        else if (root->right != NULL)
            return (root->right);

        else //both left and left is null
            return NULL;
    }
}

//12-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *lca(struct treenode *root, int n1, int n2)
{
    while (1)
    {
        if ((n1 <= root->info && n2 >= root->info) || (n2 <= root->info && n1 >= root->info))
            return root;
        if (n1 < root->info)
            root = root->left;
        else
            root = root->right;
    }
}

//13-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *previous;
struct treenode *head;
void convert(struct treenode *root)
{
    if (root == NULL)
        return;

    convert(root->left);

    if (previous == NULL)
    {
        head = root;
        previous = root;
    }
    else
    {
        previous->right = root;
        previous = root;
    }
    convert(root->right);
    previous->right = head;
}

//14-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *convertBST(int a[], int left, int right)
{
    if (left > right)
        return NULL;

    int mid = (left + right) / 2;
    struct treenode *root = create(a[mid]);
    root->left = convertBST(a, left, mid - 1);
    root->right = convertBST(a, mid + 1, right);
    return root;
}

//15-----------------------------------------------------------------------------------------------------------------------------------------------

int counting = 1;
void findkth(struct treenode *root, int k)
{
    if (root == NULL)
        return;

    findkth(root->left, k);

    if (counting == k)
        cout << "Kth smallest element is = " << root->info;
    counting++;

    findkth(root->right, k);
}

//16-----------------------------------------------------------------------------------------------------------------------------------------------

void floorceiling(struct treenode *root, int data)
{
    if (root == NULL)
        return;
    int floor = 0, ceiling = 0;

    while (root != NULL)
    {
        if (data < root->info)
        {
            ceiling = root->info;
            root = root->left;
        }
        else if (data > root->info)
        {
            floor = root->info;
            root = root->right;
        }
        else
        {
            ceiling = floor = root->info;
            break;
        }
    }
    cout << "Floor = " << floor << endl;
    cout << "Ceiling = " << ceiling << endl;
}

//17-----------------------------------------------------------------------------------------------------------------------------------------------

int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

void treescount(int data)
{
    int result = (fact(2 * data)) / ((fact(data)) * (fact(data + 1)));

    cout << "Number of possible BSTs are = " << result << endl;
}

//18----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *removehalf(struct treenode *root)
{
    if (root == NULL)
        return NULL;

    root->left = removehalf(root->left);
    root->right = removehalf(root->right);

    if (root->left == NULL && root->right == NULL)
        return root;

    if (root->left == NULL)
    {
        //for avoiding memory issue
        //struct treenode *temp = root->right;
        //delete root;
        //return temp;
        return root->right;
    }

    if (root->right == NULL)
    {
        //for avoiding memory issue
        //struct treenode *temp = root->left;
        //delete root;
        //return temp;
        return root->left;
    }

    return root;
}

//19----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode *removerange(struct treenode *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    root->left = removerange(root->left, n1, n2);
    root->right = removerange(root->right, n1, n2);

    //There are 2 possible cases for toot
    //1.a) Root's key is smaller than min value (root is not in range)
    if (root->info < n1)
        return root->right;

    //1.b) Root's key is greater than max value (root is not in range)
    if (root->info > n2)
        return root->left;

    return root;
}

//20----------------------------------------------------------------------------------------------------------------------------------------------

int sum = 0;
int maxsum(struct treenode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->info;

    int l = maxsum(root->left);
    int r = maxsum(root->right);

    int max_one = max(root->info, (root->info + max(l, r))); //for case when both left and right child is -ve
    int max_two = max(max_one, (l + r + root->info));        //for case when only one child is -ve

    sum = max(max_two, sum);

    return max_one;
}

int main()
{
    int choice, data, ans, n;
    struct treenode *root = NULL;
    struct treenode *temp;

    while (1)
    {
        cout << "\n1. Create Tree" << endl;
        cout << "2. Pre-order of the tree" << endl;
        cout << "3. In-order of the tree" << endl;
        cout << "4. Post-order of the tee" << endl;
        cout << "5. Level-order of the tee" << endl;
        cout << "6. Find or Search an element" << endl;
        cout << "7. Find minimum element" << endl;
        cout << "8. Find maximum element" << endl;
        cout << "9. Find in-order predecessor" << endl;
        cout << "10. Find in-order successor" << endl;
        cout << "11. Delete an element" << endl;
        cout << "12. Find LCA" << endl;
        cout << "13. Convert BST into Doubly-Circular Linked List" << endl;
        cout << "14. Convert array into Doubly Linked List" << endl;
        cout << "15. Find kth smallest element of the tree" << endl;
        cout << "16. To get floor and ceiling of BST" << endl;
        cout << "17. Number of unique BST possible" << endl;
        cout << "18. Remove half nodes(single child)" << endl;
        cout << "19. Remove BST keys outside the given range" << endl;
        cout << "20. Find maximum path sum of the tree" << endl;
        cout << "21. EXIT" << endl;

        cout << "Enter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            while (1)
            {
                cout << "Enter element or press -1 : ";
                cin >> data;
                if (data == -1)
                    break;
                else
                    root = insertion(root, data);
            }
            break;
        }

        case 2:
            cout << "\nPre-order is : ";
            preorder(root);
            break;

        case 3:
            cout << "\nIn-order is : ";
            inorder(root);
            break;

        case 4:
            cout << "\nPost-order is : ";
            postorder(root);
            break;

        case 5:
            cout << "\nLevel-order is : ";
            levelorder(root);
            break;

        case 6:
        {
            cout << "\nEnter data to search : ";
            cin >> data;

            temp = findelement(root, data);
            if (temp != NULL)
                cout << "\nElement is found" << endl;
            else
                cout << "\nElement is not found" << endl;

            break;
        }

        case 7:
        {
            temp = minimum(root);
            cout << "\nMinimum element is : " << temp->info << endl;
            break;
        }

        case 8:
        {
            temp = maximum(root);
            cout << "\nMaximum element is : " << temp->info << endl;
            break;
        }

        case 9:
        {
            cout << "\nEnter element to search : ";
            cin >> data;

            temp = in_predecessor(root, data);
            if (temp != NULL)
                cout << "Predecessor is = " << temp->info << endl;
            else
                cout << "Not found" << endl;
            break;
        }

        case 10:
        {
            cout << "\nEnter element to search : ";
            cin >> data;

            temp = in_successor(root, data);
            if (temp != NULL)
                cout << "Successor is = " << temp->info << endl;
            else
                cout << "Not found" << endl;

            break;
        }

        case 11:
        {
            cout << "\nEnter element to be deleted : ";
            cin >> data;

            deleteelement(root, data);
            break;
        }

        case 12:
        {
            int data1, data2;
            cout << "\nEnter numbers : ";
            cin >> data1 >> data2;
            temp = lca(root, data1, data2);

            cout << "\nLCA = " << temp->info;
            break;
        }

        case 13:
        {
            convert(root);

            struct treenode *trav = head;
            do
            {
                cout << trav->info << "  ";
                trav = trav->right;
            } while (trav != head);
            break;
        }

        case 14:
        {
            cout << "\nEnter size of array : ";
            cin >> n;
            int a[n];
            cout << "\nEnter sorted array : ";
            for (int i = 0; i < n; i++)
                cin >> a[i];
            root = convertBST(a, 0, n - 1);
            break;
        }

        case 15:
        {
            cout << "\nEnter the number : ";
            cin >> n;
            findkth(root, n);
            counting = 1;
            break;
        }

        case 16:
        {
            cout << "\nEnter the number : ";
            cin >> data;
            floorceiling(root, data);
            break;
        }

        case 17:
        {
            cout << "\nEnter number of nodes : ";
            cin >> data;
            treescount(data);
            break;
        }

        case 18:
        {
            temp = removehalf(root);
            cout << "\nLevel-order is : ";
            levelorder(temp);
            break;
        }

        case 19:
        {
            int n1, n2;
            cout << "\nEnter the range : ";
            cin >> n1;
            cin >> n2;

            temp = removerange(root, n1, n2);
            cout << "\nLevel-order is : ";
            levelorder(temp);
            break;
        }

        case 20:
        {
            maxsum(root);
            cout << "\nMaximum sum = " << sum;
            break;
        }

        case 21:
            exit(0);
            break;

        default:
            cout << "\nINVALID CHOICE\n";
        }
    }
    return 0;
}
