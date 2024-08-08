#include "vec3.h"
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

static float	random_float(void);
static int		random_seed(void);

/*
*@brief return random vec3 format number from -1 to 1
*/
t_vec3	vec3_random(void)
{
	return ((t_vec3){random_float(), \
					random_float(), \
					random_float()});
}

/*
*@brief return random vec3 number from min to max
*/
t_vec3	vec3_random_range(float min, float max)
{
	return ((t_vec3){random_float() * (max - min) + min, \
					random_float() * (max - min) + min, \
					random_float() * (max - min) + min});
}

/*
*@brief return random float number from 0 to 1
*/
static float	random_float(void)
{
	srand(random_seed());
	return ((float)rand() / RAND_MAX);
}

static int	random_seed(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (tv.tv_sec == 0 || tv.tv_usec == 0)
		return (42);
	if (tv.tv_usec % 10 == 0)
		return (tv.tv_usec + tv.tv_sec);
	else if (tv.tv_usec % 10 == 1)
		return (tv.tv_usec - tv.tv_sec);
	else if (tv.tv_usec % 10 == 2)
		return (tv.tv_usec * tv.tv_sec);
	else if (tv.tv_usec % 10 == 3)
		return (tv.tv_usec / tv.tv_sec);
	else if (tv.tv_usec % 10 == 4)
		return (tv.tv_usec % tv.tv_sec);
	else if (tv.tv_usec % 10 == 5)
		return (tv.tv_usec + tv.tv_sec % 1000);
	else if (tv.tv_usec % 10 == 6)
		return (tv.tv_usec - tv.tv_sec % 1000);
	else if (tv.tv_usec % 10 == 7)
		return (tv.tv_usec * tv.tv_sec % 1000);
	else if (tv.tv_usec % 10 == 8)
		return (tv.tv_usec / tv.tv_sec % 1000);
	return (tv.tv_usec % tv.tv_sec % 1000);
}

int main() 
{
	for (int i = 0; i < 10; ++i) {
		t_vec3 random = vec3_random();
		printf("%lf, %lf, %lf\n", random.x, random.y, random.z);
	}
}