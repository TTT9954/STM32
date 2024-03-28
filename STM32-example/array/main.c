#include <stdio.h>
#include <stdint.h>

void input_array(uint8_t *const pArray, uint8_t size_Array);
void array_display(uint8_t const *const pArray, uint8_t size_Array);
void swap(uint8_t *pArray1, uint8_t *pArray2, uint8_t size_Array1,  uint8_t size_Array2);

int main()
{
	uint8_t arr[4] = {1,2,3,4};

	printf("Address of array: %p\n", &*(arr+0));
	printf("Value of array:   %lld\n", &*(arr+1) - &arr[1]);
	/*uint8_t size_array1,size_array2;

	printf("Enter number of elements of 2 arrays: ");
	scanf("%hhu %hhu", &size_array1, &size_array2);

	uint8_t a[size_array1], b[size_array2];

	printf("Enter elements of array 1: ");
	input_array(a, size_array1);
	printf("Enter elements of array 2: ");
	input_array(b, size_array2);

	printf("\nBefore:\n");
	printf("Elements of array 1: ");
	array_display(a, size_array1);
	printf("Elements of array 2: ");
	array_display(b, size_array2);

	printf("\nAfter:\n");
	swap(a, b, size_array1,  size_array2);
	printf("Elements of array 1: ");
	array_display(a, size_array1);
	printf("Elements of array 2: ");
	array_display(b, size_array2);*/
	return 0;
}

void input_array(uint8_t *const pArray, uint8_t size_Array)
{
	for(uint8_t i = 0; i < size_Array; i++)
	{
		scanf("%hhu", &(*(pArray+i)));
	}
}

void array_display(uint8_t const *const pArray, uint8_t size_Array)
{
	for(uint8_t i = 0; i < size_Array; i++)
	{
		printf(" a[%d]= %u ", i, *(pArray+i));
	}
	printf("\n");
}

void swap(uint8_t *pArray1, uint8_t *pArray2, uint8_t size_Array1,  uint8_t size_Array2)
{
	uint8_t length = ((size_Array1 <  size_Array2) ? size_Array1 : size_Array2);
	for(uint8_t i = 0; i < length; i++)
	{
		/*uint8_t temp = *(pArray1+i);
		*(pArray1+i) = *(pArray2+i);
		*(pArray2+i) = temp;*/
		*(pArray1+i) ^= *(pArray2+i);
		*(pArray2+i) ^= *(pArray1+i);
		*(pArray1+i) ^= *(pArray2+i);
	}
}
