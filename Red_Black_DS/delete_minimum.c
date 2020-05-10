#include "main.h"
#include "red_black.h"


STATUS delete_minimum(RB_node **root)
{
	int key;
	key = (find_minimum(*root))->data;
	if (delete_data(root, key) == success)
	{
		printf("Minimum data %d deletion successful\n", key);
	}
	else
	{
		printf("Minimum data deletion function failed\n");
		return failure;
	}
	return success;
}
