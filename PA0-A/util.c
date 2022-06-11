#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "util.h"

int is_large(int num1, int num2)
{
	return num1 > num2;
}

int sum_x(int x1, int x2)
{
	int sum = 0;
	sum = x1 + x2;
	return sum;
}

void sub_y(int y1, int y2, int *sub)
{
	*sub = y1 - y2;
}

// You have to allocate memory for pointer members of "struct Point_ref"
// Hint: Use malloc()
void Point_val_to_Point_ref(struct Point_val *P1, struct Point_ref *P2)
{
	P2->x = malloc(sizeof(int));
	P2->y = malloc(sizeof(int));
	*(P2->x) = P1->x;
	*(P2->y) = P1->y;
}

void Point_ref_to_Point_val(struct Point_ref *P1, struct Point_val *P2)
{
	P2->x = *(P1->x);
	P2->y = *(P1->y);
}

int calc_area1(struct Point_val *P1, struct Point_val *P2)
{
	/* Fill this function */
	int area = 0;
	if ((P1->x - P2->x) < 0 && (P1->y - P2->y) < 0) {
		area = ((P2->x - P1->x) * (P2->y - P1->y));
	} else if ((P1->x - P2->x) < 0) {
		area = ((P2->x - P1->x) * (P1->y - P2->y));
	} else if ((P1->y - P2->y) < 0) {
		area = ((P1->x - P2->x) * (P2->y - P1->y));
	} else {
		area = ((P1->x - P2->x) * (P1->y - P2->y));
	}

	return area;
}

void calc_area2(struct Point_ref *P1, struct Point_ref *P2, int *area)
{
	if ((*(P1->x) - *(P2->x)) < 0 && (*(P1->y) - *(P2->y)) < 0) {
		*area = ((*(P2->x) - *(P1->x)) * (*(P2->y) - *(P1->y)));
	} else if ((*(P1->x)- *(P2->x)) < 0) {
		*area = ((*(P2->x) - *(P1->x)) * (*(P1->y) - *(P2->y)));
	} else if ((*(P1->y) - *(P2->y)) < 0) {
		*area = ((*(P1->x) - *(P2->x)) * (*(P2->y) - *(P1->y)));
	} else {
		*area = ((*(P1->x) - *(P2->x)) * (*(P1->y) - *(P2->y)));
	}
}

char* reverse(char *word)
{
	char temp;
	for (int i = 0; i < strlen(word) / 2; i++) {
		temp = word[i];
		word[i] = word[strlen(word) - (1+i)];
		word[strlen(word) - (1+i)] = temp;
	}
	return word;
}
