/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int to_int(char *date, int i, int j)
{
	int result=0;
	for (; i<j; i++)
	{
		result= result *10 + (date[i] - '0');
	}
	return result;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL || len <= 0)
		return NULL;
	int i;
	for (i = 0; i < len; i++)
	{
		if (to_int(Arr[i].date, 6, 10) >= to_int(date, 6, 10))
			if (to_int(Arr[i].date,3,5)>=to_int(date,3,5))
			if (to_int(Arr[i].date, 0, 2) > to_int(date, 0, 2))
				return len - i;
	}
	return 0;
}
