#include<stdio.h>
#define LINE "------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
int search(int arr[],int i, int n)
{
	if(i<n&&arr[i]!=0) return i;
	else if(i>=n-1) search(arr,0,n);
	else search(arr, i+1,n);
}
int main()
{
	int i,arr[10000],range,choice;
	printf(LINE);
	printf("\n\t\t\t\t\t\t\t\tLET US SEE WHO WILL BE THERE TO BLAME\n\n");
	printf(LINE);
	printf("\nPlease enter the no. of players: ");
	scanf("%d",&range);
	printf("\nPlease press 1 if you want to see all the kills else press 0 : ");
	scanf("%d",&choice);
	for(i = 0;i<range;i++)
		arr[i] = i+1;
	int size = range;
	int curr = 0;
	int killed = 0,kill;
	do
	{
		if(choice == 1)
			printf("\n%d killed ",curr+1);
		curr = search(arr,curr+1,range);
		if(choice == 1)
			printf("%d",curr+1);
		arr[curr] = 0;
		killed=killed+1;
		if(choice == 1)
			printf("\nNo of deaths = %d",killed);
		curr = search(arr,curr+1,range);
		if(choice == 1)
		{
			printf("\n");	
			for(i = 0;i<range;i++)
				if(arr[i]!=0)
					printf("%d ",arr[i]);
				printf("\nHi we are still alive\n");
			printf("Press and hold enter key or ");
			system("pause");
			
		}
	}while(killed < range-1);
	printf("\n");
	for(i = 0;i<range;i++)
		if(arr[i]!=0)
		printf("%d ",arr[i]);
	printf("\nHi I am left");
	getchar();
	getchar();
	system("pause");
}
