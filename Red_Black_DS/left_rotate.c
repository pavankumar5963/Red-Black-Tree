
/*
   	Function defination (Left rotate)
	Steps : 
	1) Check member is right child or left child of the parent
	2) Do left rotation on member by changing both the parents and 		 childs link on each modified node
   */
#include "main.h"
#include "red_black.h"

STATUS left_rotate(RB_node *member)
{
	RB_node *right_child = NULL, *left_child = NULL, *parent = NULL;
	
	/* Get right, left child and parent of the member */
	right_child = member->r_c;
	left_child = member->l_c;		// Can have NULL or subtree
	parent = member->parent;		// May be NULL or NOT
	if(parent)
	{
		/* Change child links */
		if (member == parent->l_c)
		{
			parent->l_c = right_child;
		}
		else
		{
			parent->r_c = right_child;
		}
		member->r_c = right_child->l_c;		// right_child's left child may be NULL or NOT
		right_child->l_c = member;
			
		/* Change Parent links */
		right_child->parent = parent;
		member->parent = right_child;
	   	//(right_child->l_c)->parent = member;
		if (member->r_c)
		{	
	   		(member->r_c)->parent = member;	
		}
	}
	else
	{
		/* Change child links */
		member->r_c = right_child->l_c;		// right_child's left child may be NULL or NOT
		right_child->l_c = member;

		/* Change parent links */
		member->parent = right_child;
		right_child->parent = NULL;
	//	(right_child->l_c)->parent = member;
		if (member->r_c)
		{
	   		(member->r_c)->parent = member;	
		}
	}
	printf("Left rotate on data %d successful\n", member->data);
	return success;
}
