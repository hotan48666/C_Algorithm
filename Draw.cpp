#include <iostream>
#include <stack>
#include <windows.h>

using namespace std;


char Map[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,1,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};

//좌표 구조체 정보 
struct Position
{
	int X;
	int Y;
};

void DrawView(Position PlayPosition, char Map[][10])
{
	// 정보 확인하기 
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (PlayPosition.Y == Y && PlayPosition.X == X)
			{
				cout << "P";
			}
			else if (Map[Y][X] == 1)
			{
				cout << "#";
			}
			else if (Map[Y][X] == 0)
			{
				cout << " ";
			}
			else if (Map[Y][X] == 3)
			{
				cout << "3";
			}
			else if (Map[Y][X] == 9)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}


void test()
{
	Position PlayPosition = { 1,1 };
	stack<Position> History;

	bool IsRuning = true;

	bool IsFirstPosition = false;

	while (IsRuning)
	{

		for (int Y = 1; Y < 9; Y++)
		{
			for (int X = 1; X < 9; X++)
			{
				Sleep(100);
				system("cls");

				if (Map[Y][X + 1] == 1)
				{
					PlayPosition.Y++;
					PlayPosition.X = 1;
				}
				else
				{
					PlayPosition.X++;
				}

				DrawView(PlayPosition, Map);

				if (X != 8 && Map[Y][X + 1] == 1)
				{
					cout << "도형의 첫 점의 위치 : " << "(" << PlayPosition.Y << ", " << PlayPosition.X + 1 << ")" << endl;
					
				

					while (IsFirstPosition)
					{
						PlayPosition.X++;
						History.push(PlayPosition);

						Sleep(100);
						system("cls");

						if (Map[PlayPosition.Y][PlayPosition.X + 1] == 1) // 오른쪽 길인지 체크
						{
							PlayPosition.X++;
							History.push(PlayPosition);
							Map[PlayPosition.Y][PlayPosition.X] = 3;
						}
						else if (Map[PlayPosition.Y + 1][PlayPosition.X] == 1) //아래쪽 길 체크
						{
							PlayPosition.Y++; // 이동 
							History.push(PlayPosition); //이동한 정보 저장
							Map[PlayPosition.Y][PlayPosition.X] = 3; // 이동전 위치 표시 
						}
						else if (Map[PlayPosition.Y][PlayPosition.X - 1] == 1) //왼쪽 길 체크
						{
							PlayPosition.X--; // 이동 
							History.push(PlayPosition); //이동한 정보 저장
							Map[PlayPosition.Y][PlayPosition.X] = 3; // 이동전 위치 표시 
						}
						else if (Map[PlayPosition.Y - 1][PlayPosition.X] == 1) //위쪽 길 체크
						{
							PlayPosition.Y--; // 이동 
							History.push(PlayPosition); //이동한 정보 저장
							Map[PlayPosition.Y][PlayPosition.X] = 3; // 이동전 위치 표시 
						}
					
						DrawView(PlayPosition, Map);

					}

					

				}
			}

		}

		cout << "도형의ddddddddddd" << endl;
	}
}

int main()
{
	test();


    return 0;
}