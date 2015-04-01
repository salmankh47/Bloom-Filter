#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 64
int func_1 (int);
int func_2 (int);
int search (int *, int);

int main(void)
{
	int array[MAX], val, hash_val, ch, flag;

	while (1)
	{
		printf("\nBloom Filter\n");
		printf("1 : Add\n");
		printf("2 : Search\n");
		printf("3 : Exit\n");
		printf("--------------\n");
		printf("Choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1 : printf("\nEnter the Value : ");
	  			 scanf("%d", &val);
				 hash_val = func_1 (val);
				 array[hash_val] = 1;
				 printf("Hash level 1 : %d\n", hash_val);
				 hash_val = func_2 (val);
				 printf("Hash level 2 : %d\n", hash_val);
				 array[hash_val] = 1;
				 break;
	
			case 2 : printf("Search for : ");
				 scanf("%d", &val);
				 flag = search (array, val);
				 if (0 == flag)
				 	printf("May be present\n");
				else
					printf("Not existing\n");
				 break;
			default : exit(0);
		}
	}

}

int func_1 (int no)
{
	int val;
	val = (no * 31)%MAX;
	return val;
}

int func_2 (int no)
{
	int val;
	val = ((no * 31*13)+(no * 31)+47)%MAX;
	return val;
}

int search (int *a, int val)
{
	if (a[func_1(val)] == 1 && a[func_2(val)] == 1)
		return 0;
	else 
		return 1;
}
