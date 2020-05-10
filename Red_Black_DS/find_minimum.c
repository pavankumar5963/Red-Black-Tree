
/* Function defination */

/*	Input: 	Red Black Tree root node address
	Output:	a) If root is not NULL then return's address of the minimum key node
			b) If root is NULL then returns NULL
	*/

#include "red_black.h"
RB_node *find_minimum(RB_node *root)
{
	if (root && root->l_c)
	{
		return find_minimum(root->l_c);
	}
	return root;
}
