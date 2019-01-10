/* Donald Adams 1000768238 Coding Assignment4 */
#include <stdio.h>

void bubble_sort(int[], int);
void swap(int *, int *);

void bubble_sort(int data[], int num_elts)
{
	int i, j;
	
	for(i=0; i< num_elts-1; i++)
		for(j =0; j < num_elts -i -1; j++)
			if(data[j] > data[j+1])
				swap(&data[j], &data[j+1]);
				
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
int index, data[10] = {10, 3, 4, 8, 2, 5, 9, 7, 1, 6};

bubble_sort(data, 10);

for(index = 0; index < 10; index ++)
	printf("%d ", data[index]);
printf("\n");
return 0;
}

