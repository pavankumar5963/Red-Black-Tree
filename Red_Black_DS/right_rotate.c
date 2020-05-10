
/*
   Function defination (Right rotate)
Steps : 
1) Check member is root node or not
2) Check member is right child or left child of the parent
3) Do Right rotation on member by changing both the parents and childs link on each modified node
 */
#include "main.h"
#include "red_black.h"

STATUS right_rotate(RB_node *member)
{
		RB_node *right_child = NULL, *left_child = NULL, *parent = NULL;

		/* Get right, left child and parent of the member */
		right_child = member->r_c;			// Can be NULL or subtree
		left_child = member->l_c;
		parent = member->parent;			// May be NULL or NOT

		if (parent)
		{
				/* Change child links */
				if (member == parent->l_c)
				{
						parent->l_c = left_child;
				}
				else
				{
						parent->r_c = left_child;
				}
				member->l_c = left_child->r_c;		// left_child's right child may be NULL or NOT
				left_child->r_c = member;
				/* Change Parent links */
				left_child->parent = parent;
				member->parent = left_child;
				if (member->l_c)
				{
					(member->l_c)->parent = member;	
				}
		}
		else
		{
				/* Change child links */
				member->l_c = left_child->r_c;		// Left_child's right child may be NULL or NOT
				left_child->r_c = member;
				/* Change Parent links */
				member->parent = left_child;
				left_child->parent = parent;
				//(left_child->r_c)->parent = member;
				if (member->l_c)
				{	
					(member->l_c)->parent = member;	
				}
		}
		printf("rotate right on data %d successful\n", member->data);
		return success;
}
