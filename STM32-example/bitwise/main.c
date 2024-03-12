#include <stdio.h>
#include <stdint.h>

void wait_for_inputting();
int main()
{
	uint32_t number,output;
	printf("Enter your number: ");
	scanf("%d", &number);
//	if(number&1) printf("Number is Odd\n");
//	else printf("Number is Even\n");
	output = number | 0x90;
	printf("[input] [output]: [0x%x] [0x%x]\n", number, output);
	wait_for_inputting();
	return 0;
}

void wait_for_inputting()
{
	printf("Press enter to exit the application");
	while(getchar() != '\n');
	getchar();

}
