
/* 	Function defination 
 	1) To print Red black tree inorder format by recursion 
 */
#include "main.h"
#include "red_black.h"
void RBT_print(RB_node *root)
{
	if(root)
	{
		RBT_print(root->l_c);
		//printf("%d(%c)-> ", root->data, root->color);
		printf("%d(%c)(r_c - %p)(l_c - %p)(p - %p)(self - %p)->\n", root->data, root->color, root->r_c, root->l_c, root->parent, root);
		RBT_print(root->r_c);
	}
}
