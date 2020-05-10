/*
   Function defination 
   1) BST insert
   2) return type is structure pointer
   */
#include "main.h"
#include "red_black.h"
RB_node *BST_insert(RB_node **root, int data)
{
	RB_node *new = NULL;
	new = malloc(sizeof(RB_node));

	/* Validation of memory*/
	if (new)
	{
		new->data = data;
		new->l_c = NULL;
		new->r_c = NULL;
		new->parent = NULL;
		
		/* Check BST empty or not */
		if (*root)
		{
			RB_node *temp = *root, *parent = *root;

			/* Traverse till leaf node */
			while (temp)
			{
				parent = temp;
				if (temp->data > data)
				{
					temp = temp->l_c;
				}
				else if (temp->data < data)
				{
					temp = temp->r_c;
				}
				else
				{
					printf("Error: No duplicate data is allowed\n");
					free(new);
					return NULL;
				}
			}
			if (parent->data > data)
			{
				parent->l_c = new;
			}
			else
			{
				parent->r_c = new;
			}
			new->parent = parent;
		}
		else
		{
			*root = new;
		}
	}
	else
	{
		printf("Error: Memory not available\n");
		return NULL;
	}
	printf("%d Data BST insert successful\n", new->data);
	return new;
}
