#ifndef _UV_LIB_TREE_H_
#define _UV_LIB_TREE_H_

typedef enum traverse_order
{
	traverse_unknow = 0,
	traverse_preorder = 1,	//ǰ�����
	traverse_inorder,		//�������
	traverse_postorder,		//��������
	traverse_levelorder,	//��α���
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
