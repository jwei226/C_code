// BST.c
#include "BST.h"
#include"Queue.h"
#include <stdlib.h>
#include <stdio.h>

BST* bst_create(void) {
	return calloc(1, sizeof(BST));
}

void bst_insert(BST* tree, K key) {
	// 1. �ҵ���ӵ�λ��
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;

	int cmp;
	while (curr) {
		cmp = key - curr->key;
		if (cmp < 0) {
			parent = curr;
			curr = curr->left;
		}
		else if (cmp > 0) {
			parent = curr;
			curr = curr->right;
		}
		else {
			// key �Ѵ���
			return;
		}
	}	// curr == NULL, cmp = key - parent->key
	// 2. ��ӽڵ�
	// a. �����ڵ㲢��ʼ��
	TreeNode* newnode = calloc(1, sizeof(TreeNode));
	newnode->key = key;
	// b. ����
	if (parent == NULL) {
		tree->root = newnode;
	}
	else if (cmp < 0) {
		parent->left = newnode;
	}
	else {
		parent->right = newnode;
	}
}

TreeNode* bst_search(BST* tree, K key) {
	TreeNode* curr = tree->root;
	while (curr) {
		int cmp = key - curr->key;
		if (cmp < 0) {
			curr = curr->left;
		}
		else if (cmp > 0) {
			curr = curr->right;
		}
		else {
			return curr;
		}
	} // curr == NULL
	return NULL;
}

void bst_delete(BST* tree, K key) {
	// 1. �ҵ�ɾ���Ľڵ�
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;
	while (curr) {
		int cmp = key - curr->key;
		if (cmp < 0) {
			parent = curr;
			curr = curr->left;
		}
		else if (cmp > 0) {
			parent = curr;
			curr = curr->right;
		}
		else {
			break;
		}
	} // curr == NULL || curr != NULL
	if (curr == NULL) return;
	// 2. ɾ�� curr �ڵ�
	if (curr->left && curr->right) {
		// �˻��ɶ�Ϊ0���߶�Ϊ1�����
		TreeNode* minp = curr;
		TreeNode* min = curr->right;
		while (min->left) {
			minp = min;
			min = min->left;
		}
		// �˻�
		curr->key = min->key;
		curr = min;
		parent = minp;
	}

	// �ҵ�Ψһ�ĺ���
	TreeNode* child = curr->left ? curr->left : curr->right;

	if (parent == NULL) {
		tree->root = child;
	}
	else {
		// ��child���ӵ�parent����ȷλ��
		int cmp = curr->key - parent->key;	// Caution: �����±Ƚ�
		if (cmp < 0) {
			parent->left = child;
		}
		else if (cmp > 0) {
			parent->right = child;
		}
		else {
			// Caution: ����cmp == 0
			parent->right = child;
		}
	}
	free(curr);
}

void inorder(TreeNode* root) {
	// �߽�����
	if (root == NULL) {
		return;
	}
	// �ݹ鹫ʽ
	// ����������
	inorder(root->left);
	// ���������
	printf("%d ", root->key);
	// ����������
	inorder(root->right);
}

void bst_inorder(BST* tree) {
	inorder(tree->root);
	printf("\n");
}

// ��α���
void bst_levelorder(BST* tree) {
	Queue* q = queue_create();
	// ������������
	queue_push(q, tree->root);
	// �ж϶����Ƿ�Ϊ��
	while (!queue_empty(q)) {
		// �����У���������ڵ�
		TreeNode* node = queue_pop(q);
		printf("%d ", node->key);
		// �ж��Ƿ�������
		if (node->left) {
			queue_push(q, node->left);
		}
		// �ж��Ƿ����Һ���
		if (node->right) {
			queue_push(q, node->right);
		}
	} // queue_empty(q)
	printf("\n");
}

void preorder(TreeNode* root) {
	//�ݹ����ÿ�����

	//�߽�����
	if (!root) return;
	//�ݹ鹫ʽ
	printf("%d   ", root->key);
	preorder(root->left);
	preorder(root->right);
}

void bst_preorder(BST* tree) {
	//ǰ�����
	if (!tree) {
		printf("Tree is NULL.\n");
		return;
	}
	preorder(tree->root);
	printf("\n");
}

void postorder(TreeNode* root) {
	//�ݹ�������
	if (!root) return;
	postorder(root->left);
	postorder(root->right);
	printf("\n");
}
void bst_postorder(BST* tree) {
	//�����������������
	if (!tree) {
		printf("Tree is NULL.\n");
		return;
	}
	postorder(tree->root);
	printf("\n");
}
//void bst_levelorder2(BST* tree) {
//	//�ֲ��ӡ�������
//	Queue* q = queue_create();
//	queue_push(q, tree->root);//���ڵ����
//	int current_level = 1;
//	int next_level = 0;
//	printf("Level 1 is: ");
//	while (!queue_empty(q)) {
//		TreeNode* node=queue_pop(q);
//		if (node) {
//			printf("%d  ", node->key);
//			if (node->left) {
//
//				queue_push(q, node->left);
//			}
//			if (node->right) {
//				queue_push(q, node->right);
//			}
//			if (--next_level == 0) {
//				printf("\nLevel %d is: ", next_level);
//				next_level = (queue_empty(q) == 0) ? 0 : (q->rear - q->front + 1);
//			}
//		}
//		
//
//	}
//}
void bst_levelorder2(BST* tree) {
	// �ֲ��ӡ�������
	
	
	Queue* q = queue_create();
	if (tree->root != NULL)
		queue_push(q, tree->root); // ���ڵ����
	else {
		printf("Tree is empty\n");
		return;
	}
	int next_level = 1; // ��һ��ڵ���
	int current_level = 1; // ��ǰ�㼶
	

	while (!queue_empty(q)) {
		
		printf("Level %d is: ", current_level);
		int current_level_num = q->rear - q->front + 1;
		for (int i = 0; i < current_level_num; i++) {
			TreeNode* node = queue_pop(q);
			printf("%d  ", node->key);

			if (node->left) {
				queue_push(q, node->left);
				
			}
			if (node->right) {
				queue_push(q, node->right);
				
			}
			next_level++;
			printf("\n");
		}

	}
}
void bst_levelorder_daan(BST* tree) {
	//������
	Queue* q = queue_create();
	// ������������
	queue_push(q, tree->root);
	// �ж϶����Ƿ�Ϊ��
	while (!queue_empty(q)) {
		int size = q->size;
		for (int i = 0; i < size; i++) {
			// ������һ�����н�㣬����һ������ӵ�������
			TreeNode* node = queue_pop(q);
			printf("%d ", node->key);
			// �ж��Ƿ�������
			if (node->left) {
				queue_push(q, node->left);
			}
			// �ж��Ƿ����Һ���
			if (node->right) {
				queue_push(q, node->right);
			}
		}
		printf("\n");
	} // queue_empty(q)
}
void bst_destroy(BST* tree) {
	//����BST
	while (tree) {
		TreeNode* current = tree->root;
		while (current)
		{
			
			free(current->left);
			free(current->right);
		}
	}
	free(tree);
}
