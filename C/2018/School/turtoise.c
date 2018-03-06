#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("\n\nIn this example we will see how the Achilles and turtoise paradox.");
	printf("\nHow many iterations it takes for Achilles to reach the turtoise\n\n");
	system("pause");
	long double a_dist = 0, t_dist = 99999999999999999999;
	int iteration = 0;

	while (a_dist < t_dist)
	{
		a_dist += (t_dist - a_dist) / 2;
		iteration++;

		printf("%Lf", a_dist);
		system("cls");
	}

	printf("\n\n%d\n\n", iteration);
	system("pause");
	system("cls");

	return 0;
}
