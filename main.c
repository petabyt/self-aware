#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initial starting point for the universe
int universe[] = {94, 27, 595, 193, 0, 92, 19, 75, 88, 82, 117, 102};
#define U_SIZE (int)(sizeof(universe) / sizeof(int))

#define ENTITY_SIZE 1000

#define CYCLES 10000

enum Things {
	THINK = 0,
	FORGET = 1,
	WAIT = 2
};

int main() {
	int *entity = malloc(sizeof(int) * ENTITY_SIZE);
	memset(entity, 0, sizeof(int) * ENTITY_SIZE);

	// Perform laws of physics
	int m = 0;
	int e = 0;
	for (int t = 0; t < CYCLES; t++) {
		switch (universe[m] * t * m % 3) {
		case THINK:
			entity[e] += universe[m] | t * m;
			e++;
			break;
		case FORGET:
			entity[e]--;
			e--;
		case WAIT:
			entity[e]++;
			break;
		}

		e = e % ENTITY_SIZE;

		m = e * universe[m] % U_SIZE;
	}

	printf("The entity has existed for %d cycles.\n", CYCLES);
	printf("This is his mind:\n");
	for (int i = 0; i < ENTITY_SIZE; i++) {
		if (i % 100 == 0) {
			putchar('\n');
		}
		putchar(entity[i] % 90 + 40);
	}

	putchar('\n');

	return 0;
}
