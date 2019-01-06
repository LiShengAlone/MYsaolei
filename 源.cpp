#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<mmstream.h>

#pragma comment (lib,"winmm.lib")
#define length	500
#define wide	500
#define N		50//�����εı߳�
#define M		10//���߸�����Ŀ

VOID InitGame();
VOID DrawMap();
VOID MouseMessage();
VOID Judge();
VOID swap(int X, int Y);

HWND hWnd;
MOUSEMSG s;
IMAGE img[12];

int map[M + 2][M + 2] = { 0 };
int m, n, i, j;
int X, Y;				//�����������
int flag = 1;			//0��ʾ����

int main()
{
	initgraph(length, wide, NULL);
	PlaySound(L"�����  ������ - ɨ��2.0.wav",NULL,SND_LOOP|SND_FILENAME|SND_ASYNC);
	while (1)
	{
		InitGame();
		while (flag==1)
		{
			MouseMessage();
			DrawMap();
		//	swap(X,Y);
			Judge();
		}
		flag = 1;
		getch();
	}
	/*
	while (1)
	{
	DrawMap(map, img);
	if (MouseMessage(map))
	{
	DrawMap(map, img);
	//MessageBox(hWnd,"","",MB_OK);
	//return;
	}
	}*/
	return 0;
}

VOID InitGame()
{
	srand((unsigned)time(NULL));
	loadimage(&img[0], L"0.jpg", N, N);
	loadimage(&img[1], L"1.jpg", N, N);
	loadimage(&img[2], L"2.jpg", N, N);
	loadimage(&img[3], L"3.jpg", N, N);
	loadimage(&img[4], L"4.jpg", N, N);
	loadimage(&img[5], L"5.jpg", N, N);
	loadimage(&img[6], L"6.jpg", N, N);
	loadimage(&img[7], L"7.jpg", N, N);
	loadimage(&img[8], L"8.jpg", N, N);
	loadimage(&img[9], L"lei.jpg", N, N);
	loadimage(&img[10], L"map.jpg", N, N);
	loadimage(&img[11], L"flag.jpg", N, N);
	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= M; j++)
		{
			map[i][j] = 0;
		}
	}
	for (n = 0; n<M;)         	//����
	{
		i = rand() % M + 1;
		j = rand() % M + 1;
		if (map[i][j] == 0)
		{
			map[i][j] = -1;//-1����һ����
			n++;//���˷������׵ĸ���
		}}
	//������
	for (i = 1; i<M + 1; i++)
	{
		for (j = 1; j <M + 1; j++)
		{
			if (map[i][j] != -1)//�жϲ�����
			{
				for (m = i - 1; m <= i + 1; m++)
				{
					for (n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] == -1)
						{
							map[i][j]++;
						}}}}}}
	for (int i = 1; i <= M; i++)
	{for (int j = 1; j <= M; j++)
		{putimage((i - 1)*N, (j - 1)*N, &img[10]);
		}}}

VOID DrawMap()
{
	if (map[X][Y] >=19)
	{
		putimage((X - 1)*N, (Y - 1)*N, &img[11]);
	}else switch (map[X][Y])
	{
	case 0:
		putimage((X - 1)*N, (Y - 1)*N, &img[0]);
		break;
	case -1:
		putimage((X - 1)*N, (Y - 1)*N, &img[9]);
		break;
	case 10:
		putimage((X - 1)*N, (Y - 1)*N, &img[0]);
		break;
	case 11:
		putimage((X - 1)*N, (Y - 1)*N, &img[1]);
		break;
	case 12:
		putimage((X - 1)*N, (Y - 1)*N, &img[2]);
		break;
	case 13:
		putimage((X - 1)*N, (Y - 1)*N, &img[3]);
		break;
	case 14:
		putimage((X - 1)*N, (Y - 1)*N, &img[4]);
		break;
	case 15:
		putimage((X - 1)*N, (Y - 1)*N, &img[5]);
		break;
	case 16:
		putimage((X - 1)*N, (Y - 1)*N, &img[6]);
		break;
	case 17:
		putimage((X - 1)*N, (Y - 1)*N, &img[7]);
		break;
	case 18:
		putimage((X - 1)*N, (Y - 1)*N, &img[8]);
		break;
	default:
		putimage((X - 1)*N, (Y - 1)*N, &img[10]);
	}
}

//���ڵ���9��ʾû����
VOID MouseMessage()
{
	s = GetMouseMsg();
	switch (s.uMsg)
	{
	case WM_LBUTTONUP:
		X = s.x / N + 1;
		Y = s.y / N + 1;
		if (map[X][Y] < 10 && map[X][Y] != -1&& map[X][Y]!=0)
		{
			map[X][Y] += 10;
		}
		else if (map[X][Y] == -1)
		{
			flag = 0;
		}
		else if (map[X][Y] == 0)
			swap(X, Y);
		break;
	case WM_RBUTTONUP:
		X = s.x / N + 1;
		Y = s.y / N + 1;
		if (map[X][Y] < 10)
			map[X][Y] += 20;
		else if (map[X][Y] >=19)
			map[X][Y] -= 20;
		break;
	}
}

VOID Judge()
{
	if (flag == 0)
	{
		hWnd = GetHWnd();
		MessageBox(hWnd, L"��ը��", L"���ź���", MB_OK);
	}
}


VOID swap(int X,int Y)
{
	putimage((X - 1)*N, (Y - 1)*N, &img[0]);
for (i = X - 1; i <= X + 1; i++)
{
for (j = Y - 1; j <= Y + 1; j++)
{
if (map[i][j] == 0)
{
putimage((i - 1)*N, (j - 1)*N, &img[0]);
}
}
}
}
