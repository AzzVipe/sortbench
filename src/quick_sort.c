#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<helper.h>

int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = low - 1;

	for(int j = low; j <= high - 1; j++) {
		if(array[j] < pivot) {
			i++;
			swap(&array[j], &array[i]);
		}
	}

	swap(&array[i + 1], &array[high]);

	return i + 1;
}

void quick_sort(int array[], int start, int end) {
	if(start < end) {
 		int mid = partition(array, start, end);

		quick_sort(array, start, mid - 1);
		quick_sort(array, mid + 1, end);
	}
}

int main(int argc, char *argv[]) 
{
	int size = 0, *array;
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

	quick_sort(array, 0, size - 1);

	printf("Array after sorting: \n");
	print_array(array, size);

	free(filename);
	free(array);

	return EXIT_SUCCESS;
}
