#ifndef _UV_LIB_BINARY_TREE_H_
#define _UV_LIB_BINARY_TREE_H_

typedef enum traverse_order
{
	traverse_unknow = 0,
	traverse_preorder = 1,	//前序遍历
	traverse_inorder,		//中序遍历
	traverse_postorder,		//后续遍历
	traverse_levelorder,	//层次遍历
	traverse_max,
} traverse_order_e;

typedef struct tree_node
{
	int value;
	struct tree_node* left;
	struct tree_node* right;
} tree_node_e;

class IBinaryTree
{
public:
	IBinaryTree();
	virtual ~IBinaryTree();

public:
	int CreateTree();

public:
	int Traverse(traverse_order_e type);

private:
	int inorder_traverse();
	int preorder_traverse();
	int postorder_traverse();
	int levelorder_traverse();
};

#endif
