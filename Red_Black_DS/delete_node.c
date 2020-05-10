/*
   Function defination to delete a node
   */

#include "main.h"
#include "red_black.h"

/*
Input:	Address of the root node and the key to be deleted
Output:	Returns 
		a) success on successful deletion
		b) not_found on key not found in thr red black tree
		c) empty when root of the tree is NULL
 */

STATUS delete_data(RB_node **root, int key)
{
	if (*root == NULL)
	{
		return empty;	
	}
	// Get address of the node to be deleted or replaced
	RB_node *search_node = NULL;
	search_node = RBT_search(*root, key);
	
	if (search_node == NULL)
	{
		return not_found;
	}

	// Decide search_data node is internal or leaf node
	// If search_data is an internal node
	if ( search_node->l_c && search_node->r_c)
	{
		RB_node *successor_node = NULL;

		// Get the successor of the search_data node
		successor_node = find_minimum(search_node->r_c);
		
		//	Copy the successor_node data to search_node
		search_node->data = successor_node->data;
		
		// Make successor node as search node
		search_node = successor_node;
	}
	
	// Now the search is a leaf node
	RB_node *parent = search_node->parent;
	// If leaf node red black (For a Red leaf node there will not be any sub trees)
	if (search_node->color == 'r')
	{
		if (parent->l_c == search_node)
		{
			parent->l_c = NULL;
			free(search_node);
			printf("Data %d is successfully deleted\n", key);
			return success;
		}
		// Mirror case
		else
		{
			parent->r_c = NULL;
			free(search_node);
			printf("Data %d is successfully deleted\n", key);
			return success;
		}
	}
	// If leaf node is black (For a black leaf node can have a red child or null childs(i.e double black case))
	else
	{
		RB_node *child = NULL;
		if (search_node->l_c)
		{
			child = search_node->l_c;
		}
		else
		{
			child = search_node->r_c;
		}
		// Non double black node
		if (child && child->color == 'r')
		{
			if (parent->l_c == search_node)
			{
				parent->l_c = child;
				child->parent = parent;
				child->color = 'b';
				free(search_node);
				printf("Data %d is successfully deleted\n", key);
				return success;
			}
			// Mirror case
			else
			{
				parent->r_c = child;
				child->parent = parent;
				child->color = 'b';
				free(search_node);
				printf("Data %d is successfully deleted\n", key);
				return success;
			}
		}
		// Double black node
		else
		{
			printf("Its a double balck case\n");
			int option, terminal_case = 1;
			RB_node *sibling = NULL;
			if (child)
			{
				if (parent->l_c == search_node)
				{
					parent->l_c = child;
					child->parent = parent;
					free(search_node);
				}
				// Mirror case
				else
				{
					parent->r_c = child;
					child->parent = parent;
					free(search_node);
				}
				search_node = child; 
			}
			while(terminal_case)
			{
				parent = search_node->parent;
				if (parent && (parent->l_c == search_node))
				{
					sibling = parent->r_c;
				}
				else if(parent)
				{
					sibling = parent->l_c;
				}
				if (search_node->l_c)
				{	
					child = search_node->l_c;
				}
				else
				{
					child = search_node->r_c;
				}

				// Obtaining the cases
				option = decide_case(search_node);
				// Every case as normal case and mirror case
				switch(option)
				{
					case 1:
							{
								terminal_case = 0;	
							}
							break;
					case 2:
							{
								if(search_node == parent->l_c)
								{
									parent->color = 'r';
									sibling->color = 'b';
									left_rotate(parent);
								}
								// Its mirror case
								else
								{
									parent->color = 'r';
									sibling->color = 'b';
									right_rotate(parent);
								}
								if (sibling->parent == NULL)
								{
									*root = sibling;
								}
								terminal_case = 1;	
							}
							break;
					case 3:
							{
								if (parent->l_c == search_node)
								{
									sibling->color = 'r';
									parent->l_c = NULL;
								}	
								// Its mirror case
								else
								{
									sibling->color = 'r';
									parent->r_c = NULL;
								}
								if (search_node)
								{
									free(search_node);	
								}
								search_node = parent;

								terminal_case = 1;	
							}
							break;
					case 4:
							{
								
								if (parent->l_c == search_node)
								{
									parent->color = 'b';
									sibling->color = 'r';
									free(search_node);
									parent->l_c = NULL;
								}
								// Its Mirror case
								else
								{
									parent->color = 'b';
									sibling->color = 'r';
									free(search_node);
									parent->r_c = NULL;
								}	
								terminal_case = 0;	
							}
							break;
					case 5:
							{
								if (parent->l_c == search_node)
								{
									(sibling->l_c)->color = 'b';
									sibling->color = 'r';
									right_rotate(sibling);
								}
								// Mirror case
								else
								{
									(sibling->r_c)->color = 'b';
									sibling->color = 'r';
									left_rotate(sibling);
								}
								terminal_case = 1;	
							}
							break;
					case 6:
							{
								if (parent->l_c == search_node)
								{
									left_rotate(parent);
									sibling->color = parent->color;
									if (sibling->parent == NULL)
									{
										*root = sibling;
									}
									parent->color = 'b';
									(sibling->r_c)->color = 'b';
									parent->l_c = NULL;
									free(search_node);
								}
								// Its mirror case
								else
								{
									right_rotate(parent);
									sibling->color = parent->color;
									if (sibling->parent == NULL)
									{
										*root = sibling;
									}
									parent->color = 'b';
									(sibling->l_c)->color = 'b';
									parent->r_c = NULL;
									free(search_node);
								}
								terminal_case = 0;	
							}
							break;
				}
			}
		}
	}
	printf("Data %d is successfully deleted\n", key);
	return success;
}
