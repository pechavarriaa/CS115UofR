#include <cstdio>
#include <cstring>
char arr[30];
int i, j, k;
int main()
{
	scanf("%s", arr);
	j = strlen(arr);
	j--;
	while (arr[j] == '0')j--;
	
	while (i < j)
	{
		if (arr[i] != arr[j])
		{
			printf("NO");
			return 0;
		}
		i++, j--;
	}
	printf("YES");
}
