#include "main.h"
#include "red_black.h"

int decide_case(RB_node *node)
{
	RB_node *parent = node->parent;
	if (parent)
	{
		RB_node *sibling = NULL;
		if (parent->l_c == node)
		{
			sibling = parent->r_c;
		}
		else
		{
			sibling = parent->l_c;
		}
		if (sibling->color == 'r')
		{
//			printf("Sibling color is red\n");
			printf("Case :2\n");
			return 2;
		}
		else
		{
//			printf("Sibling color is black\n");
			RB_node *sibling_l_c = sibling->l_c, *sibling_r_c = sibling->r_c;
			// When sibling and parent both are black (i.e case 3 or 5 and 6)
			if (parent->color == 'b')
			{
//				printf("parent color is black\n");
				
				   // Normal case
					if (sibling == parent->r_c)
					{
						if (sibling_l_c || sibling_r_c)
						{
							if (sibling_r_c && (sibling_r_c->color == 'r'))
							{
								printf("Case :6\n");
								return 6;
							}
							else if (sibling_l_c && (sibling_l_c->color == 'r'))
							{
								printf("Case :5\n");
								return 5;
							}
							else
							{
								printf("Case :3\n");
								return 3;
							}
						}
						else
						{
							
							printf("Case :3\n");
							return 3;
						}
					}
					// Mirror case
					else
					{
						if (sibling_l_c || sibling_r_c)
						{
							if (sibling_l_c && (sibling_l_c->color == 'r'))
							{
								printf("Case :6\n");
								return 6;
							}
							else if (sibling_r_c && (sibling_r_c->color == 'r'))
							{
								printf("Case :5\n");
								return 5;
							}
							else
							{
								printf("Case :3\n");
								return 3;
							}
						}
						else
						{
							
							printf("Case :3\n");
							return 3;
						}
					}
			}
			// When parent is red
			else
			{
//				printf("parent color is red\n");
				// Normal case
				if (sibling == parent->r_c)
				{
					if (sibling_r_c && sibling_r_c->color == 'r')
					{
						printf("Case :6\n");
						return 6;
					}
					else
					{
						printf("Case :4\n");
						return 4;
					}
				}
				// Mirror case
				else
				{
					if (sibling_l_c && sibling_l_c->color == 'r')
					{
						printf("Case :6\n");
						return 6;
					}
					else
					{
						printf("Case :4\n");
						return 4;
					}
				
				}
			}	
		}
	}
	else
	{
		printf("Case :1\n");
		return 1;
	}	
}
