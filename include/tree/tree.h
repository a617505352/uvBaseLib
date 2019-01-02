#ifndef _UV_LIB_TREE_H_
#define _UV_LIB_TREE_H_

typedef enum traverse_order
{
	traverse_unknow = 0,
	traverse_preorder = 1,	//前序遍历
	traverse_inorder,		//中序遍历
	traverse_postorder,		//后续遍历
	traverse_levelorder,	//层次遍历
	traverse_max,
} traverse_order_e;

class CTree
{
public:
	CTree();
	virtual ~CTree();

public:


};

#endif
