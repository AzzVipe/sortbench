#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<helper.h>

void selection_sort(int array[], int size) 
{
	int min;

	for(int i = 0; i < size - 1; i++) {
		min = i;
		for(int j = i + 1; j < size; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}
		if(i == min) continue;
		swap(&array[i], &array[min]);
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
	
	selection_sort(array, size);

	printf("\nArray after sorting\n");
	print_array(array, size); 
	
	free(filename);
	free(array);
	
	return EXIT_SUCCESS;
}
