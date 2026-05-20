/*
 * Bucket sort using linked-list buckets
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<helper.h>

#define BUCKET_COUNT 997

struct ht_node{
	double data;
	struct ht_node *next;	
};

struct ht_node *ls_array[BUCKET_COUNT];

int calc_index(double key) 
{
	int index = (int)(key * BUCKET_COUNT);

	if(index >= BUCKET_COUNT)
		index = BUCKET_COUNT - 1;

	return index;
}

struct ht_node *new_node(double data) 
{
	struct ht_node *node = malloc(sizeof(struct ht_node));

	if(node == NULL) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	node->data = data;
	node->next = NULL;

	return node;
}

int ht_size(struct ht_node *list)
{
	int len = 0;

	for(struct ht_node *temp = list; temp != NULL; temp = temp->next)
		len++;

	return len;
}

void bs_insert(double data) 
{
	struct ht_node *node;
	int index = calc_index(data);

	node = new_node(data);

	node->next = ls_array[index];
	ls_array[index] = node;	
}

void bs_print(void) 
{
	for(int i = 0; i < BUCKET_COUNT; i++) {
		printf("[%d]: [", i);
		for (struct ht_node *node = ls_array[i]; node != NULL; node = node->next) {
			printf(" %lf", node->data);
		}
		puts(" ]");
	}	
}

struct ht_node* ht_swap(struct ht_node* ptr1, struct ht_node* ptr2)
{
    struct ht_node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
  
/* Function to sort the list */
void bubble_sort(struct ht_node** head, int count)
{
	struct ht_node** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {
			struct ht_node* p1 = *h;
			struct ht_node* p2 = p1->next;

			if (p1->data > p2->data) {
				/* update the link after swapping */
				*h = ht_swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
}

void free_list(struct ht_node *head)
{
	struct ht_node *temp;

	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

void bucket_sort(double *array, int size) 
{
	int count = 0;

	for(int i = 0; i < size; i++)
		bs_insert(array[i]);

	for(int i = 0; i < BUCKET_COUNT; i++) {
		count = ht_size(ls_array[i]);
		if(count > 1)
			bubble_sort(&ls_array[i], count);
	}

	for(int i = 0; i < BUCKET_COUNT; i++) {
		free_list(ls_array[i]);
	}
}

int main(int argc, char *argv[]) 
{
	int size = 0;
	double *array;
	char *filename;
	FILE *fp;

	if(argc != 2) {
		fprintf(stderr, "Usage: <%s> <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	filename = strdup(argv[1]);
	if(filename == NULL) {
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(filename, "r")) == NULL) {
		perror("fopen error");
		exit(EXIT_FAILURE);
	}
 	
	size = populate_array_double(fp, &array);
	bucket_sort(array, size);

	free(filename);
	free(array);

	return EXIT_SUCCESS;
}
