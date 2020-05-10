#include "main.h"
#include "red_black.h"

STATUS delete_maximum(RB_node **root)
{
	int key;
	key = (find_maximum(*root))->data;
	if(delete_data(root, key) == success)
	{
		printf("Maximum data %d deletion successful\n", key);
	}
	else
	{
		printf("Maximum data deletion function failed\n");
		return failure;	
	}
	return success;
}
