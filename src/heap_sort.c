#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<helper.h>

void max_heapify(int arr[], int size, int i) {

	int largest = i;

	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (i != largest) {

		swap(&arr[i], &arr[largest]);

		max_heapify(arr, size, largest);

	}
}

void build_max_heap(int *arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		max_heapify(arr, size, i);
}

void heap_sort(int arr[], int size) {

	build_max_heap(arr, size);

	for (int i = size - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);

		max_heapify(arr, i, 0);
	}
}

int main(int argc, char *argv[]) 
{
	int size = 0, max = 0, *array;
	char *filename;
	FILE *fp;

	if(argc == 2) {
		filename = strdup(argv[1]);

		if((fp = fopen(filename, "r")) == NULL) {
			perror("fopen error");
			exit(EXIT_FAILURE);
		}

		size = populate_array(fp, &array);
	} else if (argc == 1) {
		scanf("%d", &size);
		array = malloc(sizeof(int) * (size + 1));

		if(array == NULL) {
			perror("malloc error");
			exit(EXIT_FAILURE);
		}

		for(int i = 0; i < size; i++)
			scanf("%d", &array[i]);
	} else {
		fprintf(stderr, "Usage: %s || <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Array before sorting: \n");
	print_array(array, size);

	heap_sort(array, size);

	printf("\nArray after sorting: \n\n");

	for(int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	free(filename);
	free(array);

	return EXIT_SUCCESS;
}
