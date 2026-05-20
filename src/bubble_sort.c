#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<helper.h>

void bubble_sort(int array[], int size) {
	for(int i = 0; i < size - 1; i++) {
		for(int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1])
				swap(&array[j + 1], &array[j]);
		}
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

	bubble_sort(array, size);
	printf("Array after sorting: \n");
	print_array(array, size);

	free(filename);
	free(array);

	return EXIT_SUCCESS;
}
