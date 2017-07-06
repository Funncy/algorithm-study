#include <stdio.h>
#include <stdlib.h>

int n;
int f;
bool Farray[10][10] = { false};
bool isFriend[10] = { false };

int func()
{
	int FirstFriend = -1;
	for (int i = 0; i < n; i++)
	{
		if (isFriend[i] == false)
		{
			FirstFriend = i;
			break;
		}
	}

	if (FirstFriend == -1)
		return 1;

	int rect = 0;

	for (int i = FirstFriend + 1; i < n; i++)
	{
		if (!isFriend[i] && Farray[i][FirstFriend])
		{
			isFriend[i] = isFriend[FirstFriend] = true;
			rect += func();
			isFriend[i] = isFriend[FirstFriend] = false;
		}
	}
	return rect;
}


int main()
{
	bool isFriend[10] = { false };
	int N;
	int f_1, f_2;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &n, &f);
		for (int j = 0; j < f; j++)
		{
			scanf("%d %d", &f_1, &f_2);
			Farray[f_1][f_2] = true;
			Farray[f_2][f_1] = true;
		}

		printf("%d\n",func());

		for (int j = 0; j < 10; j++)
		{
			isFriend[j] = false;
			for (int p = 0; p < 10; p++)
				Farray[j][p] = false;
		}
	}

	return 0;
}