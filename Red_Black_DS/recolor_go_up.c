

/*
   Function defination (Algorithm case-1)
   steps: 	1) Recolor the parent and uncle as BLACK, grand parent as RED. 
   			2) Then change the member pointing to grand_parent
   */

#include "main.h"
#include "red_black.h"

STATUS	recolor_go_up(RB_node **member)
{
	RB_node	*parent = NULL, *uncle = NULL, *grand_parent = NULL;
	
	parent = (*member)->parent;
	grand_parent = parent->parent;

	/*
	   	Uncle Node:
		1) If parent is right child of grand parent then uncle is left child of grand parent
		2) If parent is left child of grand parent then uncle is right child of grand parent
	   */
	if (grand_parent->r_c != parent)
	{
		uncle = grand_parent->r_c;
	}
	else
	{
		uncle = grand_parent->l_c;
	}
//	printf("uncle %p\n", uncle);	
//	printf("parent %p\n", parent);	
//	printf("g_parent %p\n", grand_parent);	
	/* Step 1 */
	parent->color = BLACK;
	uncle->color = BLACK;
	grand_parent->color = RED;
//	printf("Color change done\n");	
	/* Step 2*/
	(*member) = grand_parent;
	printf("Recolor and go up successful\n");	
	return success;
}	
