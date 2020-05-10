
/*
   Function defination to insert data in Red-Black Tree

 */
#include "main.h"
#include "red_black.h"

STATUS insert(RB_node **root, int data)
{
		RB_node *new = NULL;

		/* Insert data by BST insert algorithm */
		new = BST_insert(root, data);
		if (new)
		{
			/* Color the new node as red color */
			new->color = RED;
		}
		else
		{
			return failure;
		}

		/* Continue if the new node parent is not NULL and parent color is RED*/
		if (new->parent && (new->parent)->color == RED)
		{
				/* */
				while ((new != *root) && (new->color == RED) && (new->parent)->parent)
				{

						RB_node *grand_parent = (new->parent)->parent;
						/* Category A */
						/* Continue if new node parent is left child of grand_parent*/
						if (new->parent == grand_parent->l_c)
						{
								printf("Category A\n");
								RB_node *uncle = grand_parent->r_c;
								/* Uncle key is present  AND its color is red*/
								if (uncle && uncle->color == RED)
								{
										printf("Recolour_go_up\n");
										recolor_go_up(&new);			
								}
								// Continue if new node is zig-zag child format
								else if (new == (new->parent)->r_c)
								{
										//printf("zigzag to linear with uncle present\n");
										left_rotate(new->parent);	
										/* Now new is changed to new child */
										new = new->l_c;

										right_rotate((new->parent)->parent);
										/* Now new is changed to new parent */
										new = new->parent;
										if (new->parent == NULL)
										{
												*root = new;
										}
										new->color = BLACK;
										(new->r_c)->color = RED;
								}
								// Continue if new node is linear child format
								else
								{
										//printf("Linear relation with uncle present\n");
										right_rotate((new->parent)->parent);
										/* Now new is changed to new parent */
										new = new->parent;
										if (new->parent == NULL)
										{
												*root = new;
										}
										new->color = BLACK;
										(new->r_c)->color = RED;
								}
#if 0
								// If the new member is zig-zag or linear
#endif
						}
						/* Category B */
						/* Continue if new node parent is right child of grand_parent*/
						else
						{
								printf("Category B\n");
								RB_node *uncle = grand_parent->l_c;
								// Uncle key is present  AND its color is red
								if (uncle && uncle->color == RED)
								{
										printf("Recolour_go_up\n");
										recolor_go_up(&new);			
								}
								// Continue if new node is zig-zag child format
								else if (new == (new->parent)->l_c)
								{
										//printf("zigzag to linear with uncle present\n");
										right_rotate(new->parent);
										/* Change new as new right children */
										new = new->r_c;

										left_rotate((new->parent)->parent);
										/* Change new as new parent */
										new = new->parent;
										if (new->parent == NULL)
										{
												*root = new;
										}
										new->color = BLACK;
										(new->l_c)->color = RED;
								}
								// Continue if new node is linear child format
								else
								{
										//printf("Linear relation uncle present\n");
										left_rotate((new->parent)->parent);
										/* Change new as new parent */
										new = new->parent;
										if (new->parent == NULL)
										{
												*root = new;
										}
										new->color = BLACK;
										(new->l_c)->color = RED;
								}
						}
				}
		}
		/* Change the root node color to BLACK */
		if ((*root)->color == RED)	
		{
			(*root)->color = BLACK;
		}
		printf("%d Data Red_Black insertion successful\n", data);
		return	success; 
}
