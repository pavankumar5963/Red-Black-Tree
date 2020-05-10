/* Function defination */

/*	Input: 	Red Black Tree root node address
	Output:	a) If root is not NULL then return's address of the maximum key node
			b) If root is NULL then returns NULL
	*/

#include "red_black.h"

RB_node *find_maximum(RB_node *root)
{
	if (root && root->r_c)
	{
		return find_maximum(root->r_c);
	}
	return root;
}
