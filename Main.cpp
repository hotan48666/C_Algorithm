#include <iostream>
#include <stack>
#include <windows.h>

using namespace std;

// DFS + ��Ʈ��ŷ
// 
// 0. 1,1 ���� 8,8 �������� ��� ���ϱ� 
// 1. �����ʺ��� �ð�������� ������ 
// 2. �������� �� üũ 
// 3. ���ٰ� ���ٸ� �� �߻��� ���� ���� ����� �� 
// 4. �� ������ ���ÿ� �׾Ƶ�(ó���� �������� ���´�. ���������� ó���� ���´�.)
// 5. �����ʴ� �濡�� �ٽ� ���� 
// 6. �� �������� �� 

//��ǥ ����ü ���� 
struct Position
{
	int X;
	int Y;
};

void DFSView(Position Player,char Map[][10])
{
	// ���� Ȯ���ϱ� 
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
		{1,0,1,1,1,1,0,0,0,1}, // ��
		{1,0,0,0,1,1,0,1,1,1}, // ^
		{1,1,1,0,0,0,0,1,1,1}, // 1
		{1,1,1,1,1,1,0,1,0,1}, // 1
		{1,0,0,0,0,0,0,0,0,1}, // 1
		{1,0,1,1,0,1,0,1,1,1}, // 1
		{1,0,1,1,1,1,0,0,1,1}, // 1
		{1,0,1,0,0,0,0,0,0,1}, // 1
		{1,1,1,1,1,1,1,1,1,1}, // 1
	};  //---------------> X �� 
	// ��½� Map[Y][X] 


	stack<Position> History; //������ ��� ���� 

	Position Player = { 1,1 }; // �÷��̾� ���� 
	History.push(Player); // ó�� ����
	Map[Player.Y][Player.X] = 3; // ������ �� ǥ�� 

	//�켱 �̵� �׽�Ʈ �����ʺ��� �ð���� 
	//Player.X++; // 1. ������
	//Player.Y++; // 2. �Ʒ� 
	//Player.X--; // 3. ����
	//Player.Y--; // 4. ��

	while (!(Player.Y == 8 && Player.X == 8))
	{

		Sleep(300);
		system("cls");

		//���� ������ ���� �ȴ�. ���� �ƴϸ� ���� �ִ�. �� üũ
		if (Map[Player.Y][Player.X + 1] == 0) // ������ ������ üũ
		{
			Player.X++; // �̵� 
			History.push(Player); //�̵��� ���� ����
			Map[Player.Y][Player.X] = 3; // �̵��� ��ġ ǥ�� 
		}
		else if (Map[Player.Y + 1][Player.X] == 0) //�Ʒ��� �� üũ
		{
			Player.Y++; // �̵� 
			History.push(Player); //�̵��� ���� ����
			Map[Player.Y][Player.X] = 3; // �̵��� ��ġ ǥ�� 
		}
		else if (Map[Player.Y][Player.X - 1] == 0) //���� �� üũ
		{
			Player.X--; // �̵� 
			History.push(Player); //�̵��� ���� ����
			Map[Player.Y][Player.X] = 3; // �̵��� ��ġ ǥ�� 
		}
		else if (Map[Player.Y - 1][Player.X] == 0) //���� �� üũ
		{
			Player.Y--; // �̵� 
			History.push(Player); //�̵��� ���� ����
			Map[Player.Y][Player.X] = 3; // �̵��� ��ġ ǥ�� 
		}
		else // ��� ������ ���� �ƴ� ���, �� ,3,1 �ΰ�� 
		{
			History.pop(); // �̵��� ���� ������ �� ���� 
			Map[Player.Y][Player.X] = 9; // �ش� ��ġ �� ǥ�÷� ����

			if (History.empty())
			{
				cout << "���� ���׿�." << endl;
				break;
			}

			Player = History.top(); // ���� ������ �� ����ġ�� �÷��̾� ����, �� Ʈ��ŷ
		}

		DFSView(Player, Map);
	}

	cout << "������ �÷��̾� ��ġ : " << "(" << Player.X << ", " << Player.Y << ")" << endl;
}

int main()
{
	DFS();

	return 0;
}