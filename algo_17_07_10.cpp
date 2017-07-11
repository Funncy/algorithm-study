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

	/// �����
	if (x < w - 1 && y < h - 1) //�Ʒ� ������ ���ְ� ������ ������ ���ִ��� 
	{ //�׷� ��쿡�� ����� ���� �����ִ�
		if (arr[y][x] == '.' && arr[y][x + 1] == '.' && arr[y + 1][x + 1] == '.') 
		{ //������� ����ִ� ��� ä��� �׸��� ��� ����
			arr[y][x] = '#';
			arr[y][x + 1] = '#';
			arr[y + 1][x + 1] = '#';
			cnt += func();
			arr[y][x] = '.';
			arr[y][x + 1] = '.';
			arr[y + 1][x + 1] = '.';
		}
	}

	//�����
	if (x < w - 1 && y < h - 1)
	{
		if (arr[y][x] == '.' && arr[y + 1][x] == '.' && arr[y + 1][x + 1] == '.')
		{ //����� ����ִ� ��� ä��� �׸��� ��� ����
			arr[y][x] = '#';
			arr[y+1][x ] = '#';
			arr[y + 1][x + 1] = '#';
			cnt += func();
			arr[y][x] = '.';
			arr[y+1][x ] = '.';
			arr[y + 1][x + 1] = '.';
		}
	}

	// reverse �����
	if (x < w -1 && y < h - 1)
	{
		if (arr[y][x] == '.' && arr[y + 1][x] == '.' && arr[y ][x + 1] == '.')
		{ //����� ����ִ� ��� ä��� �׸��� ��� ����
			arr[y][x] = '#';
			arr[y + 1][x] = '#';
			arr[y ][x + 1] = '#';
			cnt += func();
			arr[y][x] = '.';
			arr[y + 1][x] = '.';
			arr[y ][x + 1] = '.';
		}
	}

	//reverse �����
	if (x > 0 && y < h-1)
	{
		if (arr[y][x] == '.' && arr[y + 1][x] == '.' && arr[y + 1][x - 1] == '.')
		{ //����� ����ִ� ��� ä��� �׸��� ��� ����
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