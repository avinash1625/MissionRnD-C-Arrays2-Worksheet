/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int _int(char *date, int i, int j)
{
	int result = 0;
	for (; i<j; i++)
	{
		result = result * 10 + (date[i] - '0');
	}
	return result;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
		if (A == NULL || B == NULL)
			return NULL;
		int i = 0, j = 0,k=0, day = 0,flag=0, month = 0, year = 0, day1 = 0, month1 = 0, year1 = 0;
		struct transaction *result = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
		while (i < ALen&&j < BLen)
		{
			day = _int(A[i].date, 0, 2);
			month = _int(A[i].date, 3, 5);
			year = _int(A[i].date, 6, 10);
			day1 = _int(B[j].date, 0, 2);
			month1 = _int(B[j].date, 3, 5);
			year1 = _int(B[j].date, 6,10 );

			if (year1 < year)
			{
				result[k] = B[j];
				k++;
				j++;
				flag = 1;
			}
			else if (year1 == year&&month1 < month)
			{
				result[k] = B[j];
				k++;
				j++;
				flag= 1;
			}
			else  if (year1 == year&&month1 == month&&day1 < day)
			{
				result[k] = B[j];
				k++;
				j++;
				flag = 1;
			}
			if (flag != 1)
			{
				result[k] = A[i];
				i++;
				k++;
			}
			day1 = 0;
			month1 = 0;
			year1 = 0;
			flag= 0;
		}
		while (i < ALen)
		{
			result[k] = A[i];
			i++;
			k++;
		}
		while (j < BLen)
		{
			result[k] = B[j];
			j++;
			k++;
		}
		return result;
}
	
