/**
 * @file divide_and_conquer.c
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 30/08/2018
 * 
 * Divide and conquer to 
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h> // srand
#include <time.h>   // time
#include <float.h>  // DBL_MAX

#define MAX_NUM 1000

struct Point
{
	double x, y;
};

struct Point make_point(double x, double y)
{
	return (struct Point){x, y};
}

double distance(struct Point a, struct Point b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	struct Point points[MAX_NUM];

	int i;
	for (i = 0; i < MAX_NUM; i++)
	{
		points[i] = make_point((double)rand(), (double)rand());
	}

	size_t in, out;
	double dist_max = DBL_MIN, dist_min = DBL_MAX, temp_dist = 0.0;
	struct Point *max1, *max2, *min1, *min2;
	for (out = 0; out < MAX_NUM; out++)
	{
		for (in = 0; in < MAX_NUM; in++)
		{
			temp_dist = distance(points[out], points[in]);

			if (temp_dist != 0.0)
			{
				if (temp_dist < dist_min)
				{
					dist_min = temp_dist;
					min1 = &(points[out]);
					min2 = &(points[in]);
				}
				
				if (temp_dist > dist_max)
				{
					dist_max = temp_dist;
					max1 = &(points[out]);
					max2 = &(points[in]);
				}
			}
		}
	}

	printf("\n\nSmallest distance is: %8.2f between points [%8.2f, %8.2f] and [%8.2f, %8.2f]", dist_min, min1->x, min1->y, min2->x, min2->y);
	printf("\nBiggest  distance is: %8.2f between points [%8.2f, %8.2f] and [%8.2f, %8.2f]", dist_max, max1->x, max1->y, max2->x, max2->y);

	// TODO implement divide and conquer to search faster for closest point. Also to sort it.

	return 0;
}
