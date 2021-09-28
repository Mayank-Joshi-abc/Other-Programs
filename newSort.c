// 6 2 8 2 3 5 9 2 12 90
#include<stdio.h>
#include<malloc.h>
#include<time.h>
int count = 0;
void merge(int arr[],int a,int b )
{
	int n1 = a-1,n2 = b-1;
	int *ar2;
	ar2 = malloc(sizeof(int)*(b));
	int k = 0,i=0,j=a;
//	printf("\nGOOD9");
	while(i<=n1&&j<=n2)
	{
		if(arr[i]<=arr[j])
		{
			ar2[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			ar2[k] = arr[j];
			k++;
			j++;
		}
	}
//	printf("\nGOODchk1");
//	printf("\ni = %d, j = %d,  n1 = %d, n2 = %d",i,j,n1,n2);
	while(i<=n1)
	{
		ar2[k] = arr[i];
		k++;
		i++;
	}
//	printf("\nGOODchk2");
	while(j<=n2)
	{
		ar2[k] = arr[j];
		j++;
		k++;
	}
	for(i = 0;i<b;i++)
	{
		arr[i] = ar2[i];
	}
//	printf("\n");
//	for(i = 0;i<b;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\nGOOD41");
}
double Main(int _arg)
{
	count = 0;
	int n=_arg,i;
	//scanf("%d",&n);
	int *arr1 = NULL,*arr2=NULL;
	arr1 = (int *)malloc(n*sizeof(int));
	
	arr2 = (int *)malloc(n*sizeof(int));
	srand(time(0));
	for(i=0;i<n;i++)
	{
//		scanf("%d",arr1+i);
		*(arr1+i) = rand();
		*(arr2+(n-i-1)) = *(arr1+i);
	}
	double timeUsed;
	clock_t top = clock();
//	printf("\nTime before algorithm = %lf secs",(double)top/CLOCKS_PER_SEC);
	int cur1 = arr1[0];
	int cur2 = arr2[0];
	int noch1=1;
	int noch2=1;
	for(i=1;i<n;i++)// 6 2 8 2 3 5 9 2 12 90
	{
		if(cur1>arr1[i])
		{
			noch1++;
			cur1=arr1[i];
		}
		else
		{
			cur1=arr1[i];
		}
		if(cur2>arr2[i])
		{
			noch2++;
			cur2=arr2[i];
		}
		else
		{
			cur2=arr2[i];
		}
	}
	int *indarr;
	indarr = (int *)malloc(sizeof(int)*(noch1<=noch2?noch1:noch2));
	int noch;
	int k=0;
//	printf("\nGOOD78");
	if(noch1<=noch2)
	{
		cur1=arr1[0];
		for(i=1;i<n;i++)
		{
			if(cur1>arr1[i])
			{
				cur1=arr1[i];
				*(indarr+k) = i;
				k++;
			}
			else
			{
				cur1=arr1[i];
			}
		}
		*(indarr+k) = n;
		noch = noch1;
//		printf("\nGOOD97");
//		i = 0;
//		while(i<noch)
//		{
//			printf("\ni = %d, indarr = %d",i,indarr[i]);
//			i++;
//		}
		i=0;
		while(i<noch-1)
		{
//			printf("\nNOCH = %d",noch);
			merge(arr1,indarr[i],indarr[i+1]);
//			printf("\nGOOD5");
			i++;
		}
//		printf("\nGOOD102");
	}
	else
	{
		cur2=arr2[0];
		for(i=1;i<n;i++)
		{
			if(cur2>arr2[i])
			{
				cur2=arr2[i];
				*(indarr+k) = i;
				k++;
			}
			else
			{
				cur2=arr2[i];
			}
		}
		*(indarr+k) = n;
		noch = noch2;
		i=0;
		while(i<noch-1)
		{
			merge(arr2,indarr[i],indarr[i+1]);
			i++;
		}
	}
	clock_t bott = clock();
/*	printf("\nTime after algorithm = %lf secs",(double)bott/CLOCKS_PER_SEC);
	printf("\nTime taken by algorithm = %lf secs",(double)(bott-top)/CLOCKS_PER_SEC);
	printf("\nNo. of operations = %d",count);
	printf("\n");
	if(noch1<=noch2)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",*(arr1+i));
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",*(arr2+i));
		}
	}
	printf("\n");*/
//	system("pause");
	return count;
//	return (double)(bott-top)/CLOCKS_PER_SEC;
}
int main()
{
	FILE *f;
	f = fopen("Y.dat","w");
	int i,n=1000;
	double a;
	scanf("%d",&n);
	clock_t z1 = clock();
	for(i = 1;i<=n;i++)
	{
		a = Main(i);
		fprintf(f,"%d %lf\n",i,a);
	}
	fclose(f);
	clock_t z2 = clock();
	printf("\ntime = %lf secs",(double)(z2-z1)/CLOCKS_PER_SEC);
//	system("pause")
//	system("notepad X.txt");
	return 0;
}





















