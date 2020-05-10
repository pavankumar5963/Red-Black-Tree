
/* Function defination */

/* 	Input: 	Red Black tree root node address and key
	Output:	a) when key found in tree then return address of key
			b) when key not found in tree then return NULL pointer
			*/

#include "red_black.h"

RB_node *RBT_search(RB_node *root, int key)
{
	if ( root && root->data > key)
	{
		return RBT_search(root->l_c, key);
	}
	else if (root && root->data < key)
	{
		return RBT_search(root->r_c, key);
	}
	return root;
}
