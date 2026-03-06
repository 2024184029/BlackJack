#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int Cards;
int UserSum;
int ComSum;

int ComCard[3];
int UserCard[3];

int GetCard()
{
	int Cards = rand() % 13;

	if (Cards >= 10)
	{
		Cards = 10;
	}

	return Cards;
}

void RandomCard() 
{
	srand(time(NULL));

	for (int i = 1; i <= 3; i++)
	{
		ComCard[i] = GetCard();
		UserCard[i] = GetCard();
	}
}

void PrintWinner()
{
	ComSum = ComCard[0] + ComCard[1] + ComCard[2];
	cout << "상대가 뽑은 카드들은 ";
	cout << ComCard[0] << ", " << ComCard[1] << ", " << ComCard[2] << endl;

	UserSum = UserCard[0] + UserCard[1] + UserCard[2];
	cout << "내가 뽑은 카드들은 ";
	cout << UserCard[0] << ", " << UserCard[1] << ", " << UserCard[2] << endl;;

	cout << "상대 카드 합: " << ComSum << endl;
	cout << "내 카드 합: " << UserSum << endl;;

		if (UserSum >= 21)
		{
			// Com이 이김
			cout << "상대가 이겼습니다." << endl;
			
		}
		else if (UserSum == ComSum)
		{
			// User가 이김
			cout << "승리하셨습니다." << endl;
		}
		else if(UserSum < 21 && ComSum < 21)
		{
			if (UserSum > ComSum)
			{
				// User가 이김
				cout << "승리하셨습니다." << endl;
			}
			else
			{
				// Com이 이김
				cout << "상대가 이겼습니다." << endl;
			}
		}
}

int main() 
{
	srand(time(NULL));

	GetCard();

	RandomCard();

	PrintWinner();

	return 0;
}