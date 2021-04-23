#include "buffer.h"

int insert_item(buffer_item item, buffer_item buffer[], int *ptr)
{
	if ((*ptr) < BUFFER_SIZE) {
		
		buffer[(*ptr)] = item;
		(*ptr)++;
		return 0;

	} else {

		return 1;
	}
}

int remove_item(buffer_item *item, buffer_item buffer[], int *ptr)
{
	if ((*ptr) >= 1) {
		(*ptr)--;
		*item = buffer[(*ptr)];
		return 0;

	} else {
		
		return 1;
	}
}
