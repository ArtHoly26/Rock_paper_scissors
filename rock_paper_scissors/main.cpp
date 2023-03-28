#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

class Game
{
public:
	void HumanChoise();
	void RandAIChoise();
	void Result();
	void GetScore1();
	void GetScore2();
	void Comparison();
	bool GameOver();
	void Null1();
	void SaveResult();
	void ReadResult();

private:
	int Score1=0;
	int Score2=0;
	int choiseHuman;
	int choiseAI;
	string choiseHum;
	string choiseAIM;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Game player;
	int mainChoise;
	bool mainFlag = false;
	bool exit = false;
	cout << "Добро пожаловать в игру камень, ножницы, бумага!" << endl;
	system("pause");
	system("cls");
	do
	{
		cout << "Главное меню:" << endl
			<< "1 - Новая игра" << endl
			<< "2 - Рекорды " << endl
			<< "3 - Выход" << endl;
		cin >> mainChoise;
		system("pause");
		system("cls");
		switch (mainChoise)
		{
		case 1:
			do
			{
				int caseChoise;
				player.HumanChoise();
				player.RandAIChoise();
				player.Result();
				player.Comparison();
				player.GetScore1();
				player.GetScore2();
				system("pause");
				system("cls");
				cout << "1 - Продолжить" << endl
					<<  "2 - Сохранить итоговый счет и выйти" << endl
					<<  "3 - Выход" << endl;
				cin >>caseChoise;
				if (caseChoise == 1) exit = false;
				if (caseChoise == 2)
				{
					exit = true;
					player.SaveResult();
				}
				if (caseChoise == 3) exit = true;
				system("pause");
				system("cls");

			} while (!exit);

			player.Null1();
			break;

		case 2:
			player.ReadResult();
			system("pause");
			system("cls");
			break;
		case 3:
			mainFlag = true;
			system("pause");
			system("cls");
			break;

		default: cout << "Нажмите кнопку, чтоб вернуться в меню!!! " << endl;
			     system("pause");
			     system("cls");
			     break;
		}

	} while (!mainFlag);
}

void Game:: HumanChoise()
{
	bool localFlag = false;
	do
	{
		cout << "Ваш выбор:" << endl
			<< "1 - Ножницы" << endl
			<< "2 - Камень" << endl
			<< "3 - Бумага" << endl;
		cin >> choiseHuman;
		
		system("pause");
		system("cls");
		if (choiseHuman == 1 || choiseHuman == 2 || choiseHuman == 3) localFlag = true;
		if (choiseHuman == 1) choiseHum = "Ножницы";
		if (choiseHuman == 2) choiseHum = "Камень";
		if (choiseHuman == 3) choiseHum = "Бумага";
	} while (!localFlag);
}
void Game:: RandAIChoise()
{
	srand(time(NULL));
	int max = 3;
	int min = 1;
	this->choiseAI = rand() % 3 + 1;

	if (choiseAI == 1) choiseAIM = "Ножницы";
	if (choiseAI == 2) choiseAIM = "Камень";
	if (choiseAI == 3) choiseAIM = "Бумага";
}
void Game:: Result()
{
	cout << "Вы выбрали: " << choiseHum << "-> Компьютер выбрал: " << choiseAIM << endl;
}
void Game:: GetScore1()
{
	cout << this->Score1 << endl;
}
void Game:: GetScore2()
{
	cout << this->Score2 << endl;
}
void Game:: Comparison()
{
	if (choiseAI == 1 && choiseHuman == 1) cout << "Ничья" << endl;
	if (choiseAI == 2 && choiseHuman == 2) cout << "Ничья" << endl;
	if (choiseAI == 3 && choiseHuman == 3) cout << "Ничья" << endl;
	if (choiseAI == 1 && choiseHuman == 2)
	{
		cout << "Вы выиграли" << endl;
		Score1++;
	}
	if (choiseAI == 1 && choiseHuman == 3)
	{
		cout << "Вы проиграли" << endl;
		Score2++;
	}
	if (choiseAI == 2 && choiseHuman == 3)
	{
		cout << "Вы выиграли" << endl;
		Score1++;
	}
	if (choiseAI == 2 && choiseHuman == 1)
	{
		cout << "Вы проиграли" << endl;
		Score2++;
	}
	if (choiseAI == 3 && choiseHuman == 2)
	{
		cout << "Вы проиграли" << endl;
		Score2++;
	}
	if (choiseAI == 3 && choiseHuman == 1)
	{
		cout << "Вы выиграли" << endl;
		Score1++;
	}

	
}
void Game:: Null1()
{
	this->Score1 = 0;
	this->Score2 = 0;
}
void Game:: SaveResult()
{
	string path = "Record.txt";
	ofstream save;
	save.open(path, ofstream::app);

	if (!save.is_open()) cout << "Ошибка записи!" << endl;

	else
	{
		save << Score1<<"-"<< Score2<<endl;
	}
	save.close();
}
void Game:: ReadResult()
{
	string msg;
	string path = "Record.txt";
	ifstream read;
	read.open(path);

	if (!read.is_open()) cout << "Ошибка записи!" << endl;

	else
	{
		while (!read.eof())
		{
			msg = "";
			getline(read, msg);
			cout << msg << endl;
		}
	}
	read.close();

}
