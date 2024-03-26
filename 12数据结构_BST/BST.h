// BST.h
#ifndef BST_H
#define BST_H
typedef int K;

typedef struct tree_node {
	K key;
	struct tree_node* left;
	struct tree_node* right;
}TreeNode;

typedef TreeNode* E;

typedef struct BST_tree{
	TreeNode* root;
} BST;
#endif BST_H
// API
BST* bst_create(void);
void bst_destroy(BST* tree);

void bst_insert(BST* tree, K key);
TreeNode* bst_search(BST* tree, K key);
void bst_delete(BST* tree, K key);

// 深度优先遍历
void bst_preorder(BST* tree);
void bst_inorder(BST* tree);
void bst_postorder(BST* tree);
// 广度优先遍历
void bst_levelorder(BST* tree);
void bst_levelorder2(BST* tree);