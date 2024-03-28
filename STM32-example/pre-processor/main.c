#include <stdio.h>
#include <stdint.h>

#define AREA_TRI
int main()
{
	float Area;
#ifndef AREA_CIRCLE

	float length, width;
		printf("Enter height: ");
		scanf("%f", &length);
		printf("Enter width: ");
		scanf("%f", &width);
		Area = length * width;
		printf("Area of circle: %.2f\n", Area);
#endif

#ifndef AREA_TRI
		float PI = 3.14;
			float r;
			printf("Enter radius: ");
			scanf("%f", &r);
			Area = PI * r * r;
			printf("Area of circle: %.2f\n", Area);
#endif

	return 0;

}

