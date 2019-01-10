
	/* Area of a shape Demo */
	#include <stdio.h>
	#include <math.h>
	
	
	typedef struct
	{
		float radius;
	}
	CIRCLE;
	
	typedef struct
	{
		float side;
	}
	SQUARE;
	
	typedef struct
	{
		float side1;
		float side2;
	}
	RECTANGLE;
	
	typedef struct
	{
		float base;
		float height;
	}
	TRIANGLE;
	
	union shape
	{
		CIRCLE circle;
		SQUARE square;
		RECTANGLE rectangle;
		TRIANGLE triangle;
	};
	
	enum shapes
	{
		circle = 1, square, rectangle, triangle
	};
	
	int main(void)
	{
		int MyShape;
		union shape EnteredShape;
		system("clear");
		printf(" Find the area of a shape \n\n");
		printf("1. Circle \n 2. Square \n 3. Rectangle \n 4. Triangle \n\n Enter choice ");
		scanf("%d", &MyShape);
		printf("\n\n");
		
		switch(MyShape)
		{
			case circle :
				printf("Enter the radius of the circle ");
				scanf("%f", &EnteredShape.circle.radius);
				break;
			case square :
				printf("Enter the length of one side");
				scanf("%f", &EnteredShape.square.side);
				break;
			case rectangle :
				printf("Enter length of side 1 ");
				scanf("%f", &EnteredShape.rectangle.side1);
				printf("Enter the length of side 2 ");
				scanf("%f", &EnteredShape.rectangle.side2);
				break;
			case triangle :
				printf(" Enter the length of the base ");
				scanf("%f", &EnteredShape.triangle.base);
				printf("Enter th length of the height ");
				scanf("%f",&EnteredShape.triangle.height);
				break;
			default :
				printf(" You are out of shape\n");
		}
		
		printf("\n\n");
		
		switch (MyShape)
		{
			case circle:
				printf(" The area of your circle is %f\n",
				M_PI*pow(EnteredShape.circle.radius, 2));
				break;
			
			case square:
				printf("The area of yoru square is %f \n",
				pow(EnteredShape.square.side, 2));
				break;
			
			case rectangle:
				printf("The area of your rectangle is %f \n",
				EnteredShape.rectangle.side1*EnteredShape.rectangle.side2);
				break;
			
			case triangle :
				printf("The area of your triangle is %f \n",
				EnteredShape.triangle.height*EnteredShape.triangle.base/2);
				break;
			
			default:
				printf("You are out of SHAPE AGAIN!");
		}
		return 0;
	}

	