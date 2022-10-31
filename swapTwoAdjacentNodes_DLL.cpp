void List::sortList()
{
Node *curr = _head;

Node *rightNode = NULL;		

if (_head->_data > _head->_next->_data)
{			
	curr = _head;
	rightNode = _head->_next;
	curr->_prev = rightNode;
	curr->_next = rightNode->_next;
	rightNode->_prev = NULL;
	rightNode->_next = curr;
	_head = rightNode;
}

while (curr->_next != NULL)
{
	if (curr->_data > curr->_next->_data &&    curr->_prev != NULL)
	{
		Node *left, *right;
		left = curr;
		right = curr->_next;


		left->_next = right->_next;
		right->_prev = left->_prev;
		right->_next = left;
		left->_prev = right;
		
		
	}
	if (curr->_next != NULL)
	curr = curr->_next;
}

}
