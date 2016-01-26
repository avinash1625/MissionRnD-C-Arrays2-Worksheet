/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int get_int(char *date, int i, int j)
{
	int result = 0;
	for (; i<j; i++)
	{
		result = result * 10 + (date[i] - '0');
	}
	return result;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A== NULL ||B==NULL)
		return NULL;
	int i,j,k=-1;
	struct transaction *ans = (struct transaction*)malloc(sizeof(struct transaction) * 20);
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++){
			if (get_int(A[i].date, 6, 10) == get_int(B[j].date, 6, 10))
			if (get_int(A[i].date, 3, 5) == get_int(B[j].date, 3, 5))
			if (get_int(A[i].date, 0, 2) == get_int(B[j].date, 0, 2))
			{
				k++;
				ans[k] = B[j];
				break;
			}
		}
	}
	if (k == -1)
		return NULL;
	return ans;
}