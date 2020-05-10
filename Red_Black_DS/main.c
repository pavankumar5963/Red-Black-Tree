/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "main.h"
#include "red_black.h"

int main()
{
	/* Declare the pointers */
	RB_node *root = NULL;
	int data;
//	int minimum;
//	int maximum;
	int operation;
	char option;
	do
	{
		/* Display the menu */
		printf("1. Insert\n2. Delete\n3. Search\n4. Find Minimum\n5. Delete Minimum\n6. Find Maximum\n7. Delete Maximum\n");

		/* Read the option for performing the operation */
		printf("Enter the choice: ");
		scanf("%d", &operation);

		/* Jump to the option entered by the user */
		switch (operation)
		{
			case 1:
				printf("Enter the data to be inserted into the RB Tree: ");
				scanf("%d", &data);
				/* Function call to insert new data */
				insert(&root, data);
				printf("Root node is %d\n", root->data);
				RBT_print(root);
				break;
			case 2:
				printf("Enter the data to be deleted from the RB Tree: ");
				scanf("%d", &data);
				/* Function call to delete a data */
				delete_data(&root, data);
				printf("Root node is %d\n", root->data);
				RBT_print(root);
				break;
			case 3:
				printf("Enter the key: ");
				scanf("%d", &data);
				if (RBT_search(root, data))										// Function call to search for data in Red Black tree
				{
					printf("Key Found\n");
				}
				else
				{
					printf("Key Not Found\n");
				}
				printf("Root node is %d\n", root->data);
				RBT_print(root);
				break;
			case 4:
				/* To get Minimum data and print it on standard output */
				printf("Minimum data: %d\n", (find_minimum(root))->data);			// Function call to get minimum value data from red black tree
				printf("Root node is %d\n", root->data);
				RBT_print(root);
				break;
			case 5:
				delete_minimum(&root);
				/* Modify the above line to handle the error */
				printf("Root node is %d\n", root->data);
				RBT_print(root);
				break;
			case 6:
				/* To get Maximum data and print it on standard output */
				printf("Maximum data: %d\n", (find_maximum(root))->data);
				printf("Root node is %d\n", root->data);
				RBT_print(root);
				break;				
			case 7:
				/* To delete the maximum data from red black tree */
				delete_maximum(&root);
				printf("Root node is %d\n", root->data);
				RBT_print(root);
				break;
			default:
				printf("Error: Invalid option\n");				
		}
		printf("\nWant to continue? Press [yY | nN]: ");
		scanf("\n%c", &option);
	}while (option == 'y' || option == 'Y');
	return 0;
}
