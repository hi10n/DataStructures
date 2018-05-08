# binarySearchTree

1. Create a binary tree (not necessarily complete) : Lower numbers to left subtree, Higher to the right
2. Print the depth of the tree
3. Preorder / Postorder / Inorder traversal
4. Binary search the numbers in the tree
5. Delete nodes in the binary tree
	a) Handle trivial case of deleting a node with 0 or 1 child
	b) Delete nodes with 2 nodes:
		i)   Find the inorder successor of the node being deleted
		ii)  Remove the inorder successor node from the tree (do not delete the node, just remove)
		iii) Delete the actual node being requested to be deleted
		iv)  Replace the deleted node with the inorder successor
	c) After deleting every node search for it in the tree to make sure its deleted
6. Tree will be empty at the end of the program by deleting every single node

