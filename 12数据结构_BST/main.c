#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BST.h"

int main(void) {
	
	BST* tree = bst_create();

	bst_insert(tree, 9);
	bst_insert(tree, 42);
	bst_insert(tree, 13);
	bst_insert(tree, 5);
	bst_insert(tree, 3);
	bst_insert(tree, 57);

	// bst_insert(tree, 5);

	// TreeNode* node1 = bst_search(tree, 13);
	// TreeNode* node2 = bst_search(tree, 10086);

	// bst_inorder(tree);
	// bst_levelorder(tree);
	/*bst_preorder(tree);*/
	bst_levelorder2(tree);

	// bst_delete(tree, 3);
	// bst_delete(tree, 5);
	// bst_delete(tree, 9);
	/*bst_delete(tree, 42);*/
	return 0;
}

