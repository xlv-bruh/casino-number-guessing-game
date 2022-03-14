#include <iostream>
#include <ctime>
using namespace std;
bool gameover = false;

void Check(int nr)
{
	system("cls");
	int const size = 10;
	int arr[size];

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			if (arr[i] == arr[j] && i != j)
			{
				int temp = rand() % 50;
				while (arr[j] == temp)
				{
					temp = rand() % 50;
				}
				arr[j] = temp;
			}
		}
	}

	cout << "pick an nr from list below" << endl;

	for(int i = 0; i < size; i++)
	{
		cout<<"\t" << arr[i];
	}
	cout << endl;
	cin >> nr;

	int rand_nr = rand() % 10;

	char sym;
	if (arr[rand_nr] == nr)
	{
		cout << "Powerful! you win 50$";
	}
	else {
		cout << "The random nr was " << arr[rand_nr] <<endl<< "You lose, enter '+' if u want to try again, or '-' if u want to exit: ";
		cin >> sym;
		if(sym == '-')
		{
			gameover = true;
		}
	}
}

int main()
{
	int balance;
	int nr = 0;

	cout << "Enter ur balance: ";		cin >> balance;

	
		while (!gameover)
		{
			if (balance >= 30) {
				Check(nr);
				balance -= 30;
			}
			else {
				cout << endl;
				cout << "non-stock balance." << endl << "Need at least 30$." << " Your balance consist: " << balance << endl;
				gameover = true;
			}
			
		}


	return 0;
}
