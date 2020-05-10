#ifndef RED_BLACK_H
#define RED_BLACK_H

#define	RED 	'r'
#define BLACK	'b'
#define DUPLICATE -1

typedef enum 
{
	failure,
	success,
	not_found,
	empty
} STATUS;

typedef struct Node
{
	int data;
	char color;
	struct Node *l_c, *r_c, *parent;
} RB_node;


/*
  	Function prototypes
   */

/* */
STATUS recolor_go_up(RB_node **member); 

/* */
RB_node *BST_insert(RB_node **root, int data);

/* */
STATUS left_rotate(RB_node *member);

/* */
STATUS right_rotate(RB_node *member);

/* */
STATUS insert(RB_node **root, int data);

/**/
RB_node *RBT_search(RB_node *root, int key);

/* */
void RBT_print(RB_node *root);

/**/
STATUS delete_data(RB_node **root, int key);

/* */
RB_node *find_minimum(RB_node *root);

/* */
RB_node *find_maximum(RB_node *root);

/* */
STATUS delete_minimum(RB_node **root);

/* */
STATUS delete_maximum(RB_node **root);

/* */
int decide_case(RB_node *node);
#endif
