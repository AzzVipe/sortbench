#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<helper.h>

int array_find_max(int array[], int size)
{
	int max = array[0];

	for (int i = 1; i < size; ++i)
		max = array[i] > max ? array[i] : max;

	return max;
}
		
void counting_sort(int array[], int len, int max) {
	int *temp, *result;

	temp = (int *) malloc((sizeof(int) * max) + 1);
	result = (int *) malloc(sizeof(int) * len);

	for(int i = 0; i <= max; temp[i++] = 0);

	for(int i = 0; i < len; i++)
		temp[array[i]] = temp[array[i]] + 1;

	for(int i = 1; i <= max; i++)
		temp[i] = temp[i] + temp[i - 1];	

	for(int i = len - 1; i >= 0; i--) {
		result[temp[array[i]] - 1] = array[i];
		temp[array[i]] = temp[array[i]] - 1;
	}

	for(int i = 0; i < len; i++) 
		array[i] = result[i];
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

	max = array_find_max(array, size);
	printf("\nMax = %d\n", max);
	counting_sort(array, size, max);

	printf("\nArray after sorting: \n\n");
	for(int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	free(filename);
	free(array);

	return EXIT_SUCCESS;
}
