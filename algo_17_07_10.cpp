#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


int w, h;
vector<vector<char>> arr;

int func()
{
	int x = -1;
	int y = -1;
	int cnt = 0;
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] == '.')
			{
				y = i;
				x = j;
				goto AAA;
			}
		}
	}

	AAA:

	if (x == -1 && y == -1)
		return 1;

	/// ㄱ모양
	if (x < w - 1 && y < h - 1) //아래 한줄이 더있고 오른쪽 한줄이 더있는지 
	{ //그런 경우에만 ㄱ모양 블럭이 들어갈수있다
		if (arr[y][x] == '.' && arr[y][x + 1] == '.' && arr[y + 1][x + 1] == '.') 
		{ //ㄱ모양이 비어있는 경우 채운다 그리고 재귀 시작
			arr[y][x] = '#';
			arr[y][x + 1] = '#';
			arr[y + 1][x + 1] = '#';
			cnt += func();
			arr[y][x] = '.';
			arr[y][x + 1] = '.';
			arr[y + 1][x + 1] = '.';
		}
	}

	//ㄴ모양
	if (x < w - 1 && y < h - 1)
	{
		if (arr[y][x] == '.' && arr[y + 1][x] == '.' && arr[y + 1][x + 1] == '.')
		{ //모양이 비어있는 경우 채운다 그리고 재귀 시작
			arr[y][x] = '#';
			arr[y+1][x ] = '#';
			arr[y + 1][x + 1] = '#';
			cnt += func();
			arr[y][x] = '.';
			arr[y+1][x ] = '.';
			arr[y + 1][x + 1] = '.';
		}
	}

	// reverse ㄱ모양
	if (x < w -1 && y < h - 1)
	{
		if (arr[y][x] == '.' && arr[y + 1][x] == '.' && arr[y ][x + 1] == '.')
		{ //모양이 비어있는 경우 채운다 그리고 재귀 시작
			arr[y][x] = '#';
			arr[y + 1][x] = '#';
			arr[y ][x + 1] = '#';
			cnt += func();
			arr[y][x] = '.';
			arr[y + 1][x] = '.';
			arr[y ][x + 1] = '.';
		}
	}

	//reverse ㄴ모양
	if (x > 0 && y < h-1)
	{
		if (arr[y][x] == '.' && arr[y + 1][x] == '.' && arr[y + 1][x - 1] == '.')
		{ //모양이 비어있는 경우 채운다 그리고 재귀 시작
			arr[y][x] = '#';
			arr[y + 1][x] = '#';
			arr[y + 1][x - 1] = '#';
			cnt += func();
			arr[y][x] = '.';
			arr[y + 1][x] = '.';
			arr[y + 1][x - 1] = '.';
		}
	}

	return cnt;
}


int main()
{

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &h, &w);

		for (int p = 0; p < h; p++)
		{
			vector<char> elem;
			elem.resize(w);
			arr.push_back(elem);
		}

		scanf("\n");

		for (int p = 0; p < h; p++)
		{
			for (int q = 0; q < w; q++)
			{
				scanf("%c", &arr[p][q]);
			}
			scanf("\n");
		}

		printf("%d\n", func());

		arr.clear();
	}
	return 0;
}