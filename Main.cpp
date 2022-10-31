#include <iostream>
#include <stack>
#include <windows.h>

using namespace std;

// DFS + 백트래킹
// 
// 0. 1,1 에서 8,8 까지가는 경로 구하기 
// 1. 오른쪽부터 시계방향으로 움직임 
// 2. 가지않은 길 체크 
// 3. 가다가 막다른 길 발생시 가지 않은 길까지 백 
// 4. 백 정보는 스택에 쌓아둠(처음께 마지막에 나온다. 마지막길이 처음에 나온다.)
// 5. 가지않는 길에서 다시 시작 
// 6. 골 까지가면 끝 

//좌표 구조체 정보 
struct Position
{
	int X;
	int Y;
};

void DFSView(Position Player,char Map[][10])
{
	// 정보 확인하기 
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (Player.Y == Y && Player.X == X)
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

void DFS()
{
	char Map[10][10] = {
		{1,1,1,1,1,1,1,1,1,1}, // Y
		{1,0,1,1,1,1,0,0,0,1}, // 축
		{1,0,0,0,1,1,0,1,1,1}, // ^
		{1,1,1,0,0,0,0,1,1,1}, // 1
		{1,1,1,1,1,1,0,1,0,1}, // 1
		{1,0,0,0,0,0,0,0,0,1}, // 1
		{1,0,1,1,0,1,0,1,1,1}, // 1
		{1,0,1,1,1,1,0,0,1,1}, // 1
		{1,0,1,0,0,0,0,0,0,1}, // 1
		{1,1,1,1,1,1,1,1,1,1}, // 1
	};  //---------------> X 축 
	// 출력시 Map[Y][X] 


	stack<Position> History; //지나온 기록 정보 

	Position Player = { 1,1 }; // 플레이어 정보 
	History.push(Player); // 처음 저장
	Map[Player.Y][Player.X] = 3; // 지나온 길 표시 

	//우선 이동 테스트 오른쪽부터 시계방향 
	//Player.X++; // 1. 오른쪽
	//Player.Y++; // 2. 아래 
	//Player.X--; // 3. 왼쪽
	//Player.Y--; // 4. 위

	while (!(Player.Y == 8 && Player.X == 8))
	{

		Sleep(300);
		system("cls");

		//갈수 있으면 가면 된다. 벽만 아니면 갈수 있다. 길 체크
		if (Map[Player.Y][Player.X + 1] == 0) // 오른쪽 길인지 체크
		{
			Player.X++; // 이동 
			History.push(Player); //이동한 정보 저장
			Map[Player.Y][Player.X] = 3; // 이동전 위치 표시 
		}
		else if (Map[Player.Y + 1][Player.X] == 0) //아래쪽 길 체크
		{
			Player.Y++; // 이동 
			History.push(Player); //이동한 정보 저장
			Map[Player.Y][Player.X] = 3; // 이동전 위치 표시 
		}
		else if (Map[Player.Y][Player.X - 1] == 0) //왼쪽 길 체크
		{
			Player.X--; // 이동 
			History.push(Player); //이동한 정보 저장
			Map[Player.Y][Player.X] = 3; // 이동전 위치 표시 
		}
		else if (Map[Player.Y - 1][Player.X] == 0) //위쪽 길 체크
		{
			Player.Y--; // 이동 
			History.push(Player); //이동한 정보 저장
			Map[Player.Y][Player.X] = 3; // 이동전 위치 표시 
		}
		else // 모든 방향이 길이 아닌 경우, 즉 ,3,1 인경우 
		{
			History.pop(); // 이동후 넣은 마지막 길 버림 
			Map[Player.Y][Player.X] = 9; // 해당 위치 백 표시로 변경

			if (History.empty())
			{
				cout << "길이 없네요." << endl;
				break;
			}

			Player = History.top(); // 버린 마지막 길 전위치로 플레이어 보냄, 백 트래킹
		}

		DFSView(Player, Map);
	}

	cout << "마지막 플레이어 위치 : " << "(" << Player.X << ", " << Player.Y << ")" << endl;
}

int main()
{
	DFS();

	return 0;
}