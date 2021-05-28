#include"basesystem.h"
#include"Player.h"



using namespace std;
int icx = 0, icy = 0;

void patternA(Player a);
void patternB(Player a);
int main() 
{
	
	Player player(5, 5);
	cout << player.GetXPosition() << "/" << player.GetYPosition() << endl;
	while (true) 
	{
		patternA(player);
		Sleep(90);
		patternB(player);
		Sleep(180);
		
	}
	return 0;
}



void patternA(Player a) 
{
	for (a.GetXPosition(); a.GetXPosition() < 50; icx++)
	{
		system("cls");
		a.SetX(a.GetXPosition() + 1);
		cout << a.GetXPosition() << "/" << a.GetYPosition() << endl;
		a.renderer();
		Sleep(30);

	}

	for (a.GetYPosition(); a.GetYPosition() < 25; icy++)
	{
		system("cls");
		a.SetY(a.GetYPosition() + 1);
		cout << a.GetXPosition() << "/" << a.GetYPosition() << endl;
		a.renderer();
		Sleep(30);
	}
	for (a.GetXPosition(); a.GetXPosition() > 5; icx--)
	{
		system("cls");
		a.SetX(a.GetXPosition() - 1);
		cout << a.GetXPosition() << "/" << a.GetYPosition() << endl;
		a.renderer();
		Sleep(30);

	}

	for (a.GetYPosition(); a.GetYPosition() > 5; icy--)
	{
		system("cls");
		a.SetY(a.GetYPosition() - 1);
		cout << a.GetXPosition() << "/" << a.GetYPosition() << endl;
		a.renderer();
		Sleep(30);
	}
}

void patternB(Player a)
{
	
	system("cls");
	srand(time(NULL));
	a.SetXY(rand() & 50 + 1, rand() & 50 + 1);
	cout << a.GetXPosition() << "/" << a.GetYPosition() << endl;
	a.renderer();


}




