//Danielle Hubbard


template <class ItemType>
BTree<ItemType>::BTree ()
{
  //set root and cursor
	root = NULL;
	cursor = NULL;

}  //Constructor

template <class ItemType>
void BTree<ItemType>::CopySubTree (TreeNode * parent, TreeNode *& p, TreeNode *& otherp)
{
  //if other subtree is empty, no subtree to copy
	if(otherp != NULL)
	{
	  //create new node at p and copy the item's value and 
		p=new TreeNode;
		p -> Item = otherp -> Item;
		//set pointers to null
		p -> left = NULL;
		p -> right = NULL;
		p -> parent = parent; 


	  //copy the left subtree
		CopySubTree(p, p-> left, otherp->left);

	  //copy the right subtree
		CopySubTree(p, p-> right, otherp->right);
	}
}

template <class ItemType>
BTree<ItemType>::BTree (BTree & other)
{
  TreeNode * p;

  //set root and cursor to start
  root = NULL;
  cursor = NULL;

  //check if other tree is not empty
  if (other.root != NULL)
  {
	 //create root node
     CreateFirstNode (other.root->Item);

	 //start at roots
	 p = root; 
	 other.cursor = other.root;

	 //copy left and right subtrees
     CopySubTree (p, p->left, other.cursor->left);
	 CopySubTree (p, p->right, other.cursor->right);
  }

}  //Copy Constructor

template <class ItemType>
void BTree<ItemType>::CreateFirstNode (const ItemType & Item)
{
  //allocate first node (root)
  root = new TreeNode;

  //put value in it
  root->Item = Item;

  //initialize children pointers and parent pointer to NIL
  root->left = NULL;
  root->right = NULL;
  root->parent = NULL;

  cursor = root;
}

template <class ItemType>
void BTree<ItemType>::DisposeSubTree (TreeNode *& p)
{
  //if subtree is empty, no subtree to dispose
  if (p != NULL)
  {
	  DisposeSubTree (p->left);
	  DisposeSubTree (p->right);
	  delete p;
	  p = NULL;
  }
}

template <class ItemType>
BTree<ItemType>::~BTree ()
{
  //dispose of tree nodes
	DisposeSubTree (root);

	//make sure cursor is set to NULL as well
	cursor = NULL;
} 

template <class ItemType>
void BTree<ItemType>:: ClearTree ( )
{
  //dispose of tree nodes
	DisposeSubTree(root);

	//make sure cursor is set to NULL as well
	cursor = NULL;

}  

template <class ItemType>
void  BTree<ItemType>::SwapTrees (BTree<ItemType> & T2)
{
  TreeNode * tempRoot;
  TreeNode * tempCursor;
  

  //swap root pointers
  tempRoot = root;
  root = T2.root;
  T2.root = tempRoot;

  //swap cursor pointers
  tempCursor = cursor;
  cursor = T2.cursor;
  T2.cursor = tempCursor;
} 

template <class ItemType>
bool BTree<ItemType>::IsEmpty ( ) 
{
	bool empty = false;
	//returns true iff root is null so tree is empty
	if(root == NULL)
	{
		empty = true;
	}
	
	return empty;

}

template <class ItemType>
bool BTree<ItemType>::HasParent ()
{
	bool parent=false;
	//returns true iff cursor points to node with null parent pointer
	if(cursor -> parent != NULL)
	{
		parent = true;
	}

	return parent;


} 

template <class ItemType>
bool BTree<ItemType>::HasNoChildren ()
{
	bool noChildren = false;
	//returns true iff cursor points to node with no children
	if(cursor -> left == NULL && cursor -> right == NULL)
	{
		noChildren = true;
	}

	return noChildren;
	
} 

template <class ItemType>
bool BTree<ItemType>::HasLeftChild ()
{
	bool leftchild = false;
	//returns true iff cursor points to node with left child
	if(cursor -> left != NULL)
	{
		leftchild = true;
	}

	return leftchild;
}

template <class ItemType>
bool BTree<ItemType>::HasRightChild ()
{
  return ((cursor != NULL) &&(cursor->right != NULL));
} 

template <class ItemType>
void BTree<ItemType>::ShiftToRoot ()
{
	//if root is a value
	if(root != NULL)
	{
		//move cursor to root
		cursor = root;
	}

} 

template <class ItemType>
void BTree<ItemType>::ShiftLeft ()
{
	//check that node is not a leaf
	if((cursor -> left == NULL) && (cursor -> right == NULL))
	{
		cout << "ERROR: cannot shift left, cursor at leaf\n";
	}
	//check that cursor and left child point to existing nodes
	else if((cursor == NULL) || (cursor -> left == NULL))
	{
		cout << "ERROR: cursor cannot shift left\n";
	}
	else
	{
		//move cursor left
		cursor = cursor->left;
	}
} 

template <class ItemType>
void BTree<ItemType>:: ShiftRight ()
{
  if ((cursor == NULL ) || (cursor->right == NULL))
	  cout << "ERROR:  T's cursor cannot advance right" << endl;
  else
	{
	 //move the actual cursor
	 cursor = cursor->right;
	}
} 

template <class ItemType>
void BTree<ItemType>::ShiftUp ()
{
	//check if cursor at root (cannot go any higher)
	if(cursor == root)
	{
		cout << "ERROR: cursor at root, cannot shift up\n";
	}
	else
	{
		//move cursor
		cursor = cursor -> parent;
	}

} 

template <class ItemType>
void BTree<ItemType>::RetrieveItem (ItemType & Item)
{
	//if cursor is not at end
	if(cursor != NULL)
	{
		//sets item as whatever item cursor is pointing to
		Item = cursor-> Item;
	}
	//if cursor is at end
	else
	{
		cout << "ERROR: cursor at end, cannot retrieve item\n";
	}
} 

template <class ItemType>
void BTree<ItemType>::ChangeItem (const ItemType & Item)
{
  if (cursor == NULL)
	 cout << "ERROR:  T's cursor at end, cannot update item" << endl;
  else
	 cursor->Item= Item;
} //ChangeItem

template <class ItemType>
void BTree<ItemType>::AddLeft (const ItemType & Item)
{
	//check that cursor is not at end
	if(cursor == NULL)
	{
		cout << "ERROR cursor at end cannot add left" << endl;
	}
	//check that cursor does not already have left child
	else if(cursor -> left != NULL)
	{
		cout << "ERROR node already has left child, cannot add" << endl;
	}
	else
	{
		//create new node
		cursor -> left = new TreeNode;
		//initialize values
		cursor -> left -> Item = Item;
		cursor -> left -> left = NULL;
		cursor -> left -> right = NULL;
		cursor -> left -> parent = cursor;
	}
  

} 

template <class ItemType>
void BTree<ItemType>::AddRight (const ItemType & Item)
{
  //check if tree empty or right subtree not empty
  if (cursor == NULL)
	  cout << "ERROR:  T's cursor at end, cannot add leaf" << endl;
  else if (cursor->right != NULL)
	  cout << "ERROR:  Right subtree has a node, cannot add leaf" << endl;
  //add a right child
  else
    {
		//allocate a new node
		cursor->right = new TreeNode;

		//initialize the new node's item and pointer fields
		cursor->right->Item = Item;
		cursor->right->left = NULL;
		cursor->right->right = NULL;
		cursor->right->parent = cursor;
	 }
} 

template <class ItemType>
void BTree<ItemType>::RemoveLeft ()
{
  //check if tree empty
	if(root == NULL)
	{
		cout << "tree is empty, cannot remove left" << endl;
	}
  //check if left child
	else if(cursor -> left == NULL)
	{
		cout << "ERROR cannot remove left, node has no left child" << endl;
	}
	
  //else delete left child and set parent's left pointer
	else
	{
		delete cursor-> left;
		cursor -> left = NULL;
	}
} 

template <class ItemType>
void BTree<ItemType>::RemoveRight ()
{
	  //check if tree empty
	if(root == NULL)
	{
		cout << "tree is empty, cannot remove right" << endl;
	}
  //check if right child
	else if(cursor -> right == NULL)
	{
		cout << "ERROR cannot remove right, node has no right child" << endl;
	}
	
  //else delete right child and set parent's right pointer
	else
	{
		delete cursor-> right;
		cursor -> right = NULL;
	}

  
} 

template <class ItemType>
void BTree<ItemType>::SwapSubTrees (BTree<ItemType> & T)
{
  TreeNode * p;

	//if T not empty 
	if (T.cursor != NULL)
	{
	  //if not at root, ChangeItem parent nodes' child pointers
	  if (T.cursor->parent != NULL)
	  {
		 if (T.cursor->parent->left == T.cursor)
			T.cursor->parent->left = cursor;
		 else
			T.cursor->parent->right = cursor;
	  }
	  else //at root
		  T.root = cursor;
	}

	//if this not empty
	if (cursor != NULL)
	{
	  if (cursor->parent != NULL)
	  {
		 if (cursor->parent->left == cursor)
			cursor->parent->left = T.cursor;
		 else
			cursor->parent->right = T.cursor;
	  }
	  else
		  root = T.cursor;
	}

	//reset parent pointers, if the swapped subtrees are not empty trees
	if (T.cursor != NULL)
	{
	  if (cursor != NULL)
	  {
		 p = T.cursor->parent;
		 T.cursor->parent = cursor->parent;
		 cursor->parent = p;
	  }
	  else
		 T.cursor->parent = NULL;
	}
	else if (cursor != NULL)
	  cursor->parent = NULL;

	//swap two cursors
	p = T.cursor;
	T.cursor = cursor;
	cursor = p;

	//if we made the cursors point to an empty subtree because that was what
	//was swapped, set the cursors to the roots in their respective trees
	if (cursor == NULL)
	  cursor = root;
	if (T.cursor == NULL)
	  T.cursor = T.root;

	//if a root is NULL and cursor is not null, then root should be changed
	if (T.root == NULL)
	  T.root = T.cursor;
	if (root == NULL)
	  root = cursor;

} //SwapSubTrees

