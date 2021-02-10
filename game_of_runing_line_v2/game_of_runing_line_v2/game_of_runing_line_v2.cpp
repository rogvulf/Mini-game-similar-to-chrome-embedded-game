#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <string>

using namespace std;

const int right_border = 80;
const int left_border = 0;			
const int top_border = 0;
const int bottom_border = 24;

class part_of_line
{
	int x,
		y;
	char symbol;
public:
	part_of_line();
	~part_of_line();
	int GetX();
	int GetY();
	void SetX(int X);
	void SetY(int Y);
	char GetSymbol();
	void SetSymbol(char Symbol);

};

class player
{
	int x,
		y;
	char symbol;
public:
	player();
	player(int, int, char);
	~player();
	int GetX();
	int GetY();
	void SetX(int X);
	void SetY(int Y);
	char GetSymbol();
	void SetSymbol(char Symbol);
	void jump(bool&, int&);
};

class obstacle
{
	int x,
		y;
	char symbol;
public:
	obstacle();
	obstacle(int, int, char);
	~obstacle();
	int GetX();
	int GetY();
	void SetX(int X);
	void SetY(int Y);
	char GetSymbol();
	void SetSymbol(char Symbol);
	void Behavior(obstacle& , obstacle** , bool fall=0 );
};

//template <typename T>
class List
{
	class Node
	{
	public:
		int Current;
		Node* PNext;
		Node* PPrev;
	};
	Node* Head;
	int size;
public:
	List();
	List(int, Node* = nullptr);
	~List();
	void PushBack()
	{
		this->Head->
	}
	void PopFront();
	void Clear();
};



void displaying(part_of_line[], part_of_line[], obstacle, player);

char death_output(obstacle Obstacle, player Player);

void gameplay(part_of_line[], part_of_line[], obstacle**, player*, bool&, int&);

void game_over(bool&, obstacle**);

void initialization(part_of_line[], part_of_line[]);

int _tmain(int argc, _TCHAR* argv[])
{
	//List<player> sample_1;      ///good flexibility
	//List<obstacle> sample_2;    // and variability
	srand(time(NULL));
	part_of_line Line[right_border];
	part_of_line Line2[right_border];
	player Player(14, 3, 1);
	obstacle* Obstacle = new obstacle(); 	
	bool isjumped{},
		 fall{};
	int iteration{},
		incrementation{},
		period{};
	system("pause");
	cout << Obstacle->GetX() << endl;
	delete Obstacle;
	cout << Obstacle->GetX() << endl;
	Obstacle = new obstacle;
	system("pause");
	initialization(Line, Line2);

	while (true)
	{		
		if (!fall)
		gameplay(Line, Line2, &Obstacle, &Player, isjumped, iteration);
		else if (fall)
		game_over(fall, &Obstacle);
		if (death_output(*Obstacle, Player))
			fall = 1;
		if (fall)
			this_thread::sleep_for(chrono::milliseconds(500));
			system("cls");
	}
	return 0;
}

part_of_line::part_of_line()
{

}
part_of_line::~part_of_line()
{

}

int part_of_line::GetX()
{
	return this->x;
}
int part_of_line::GetY()
{
	return this->y;
}
void part_of_line::SetX(int X)
{
	this->x = X;
}
void part_of_line::SetY(int Y)
{
	this->y = Y;
}
char part_of_line::GetSymbol()
{
	return this->symbol;
}
void part_of_line::SetSymbol(char Symbol)
{
	this->symbol = Symbol;
}

void initialization(part_of_line Line[], part_of_line Line2[])
{
	for (int counter{}; counter < right_border; counter++)
	{
		Line[counter].SetX(counter);
		Line[counter].SetY(1);
		Line[counter].SetSymbol(95);

		Line2[counter].SetX(counter);
		Line2[counter].SetY(4);
		Line2[counter].SetSymbol(95);
	}
}

void gameplay(part_of_line Line[], part_of_line Line2[], obstacle** Obstacle, player* Player, bool& isjumped, int& iteration)
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		isjumped = 1;
	}
	Player->jump(isjumped, iteration);
	(*Obstacle)->Behavior(**Obstacle, &(*Obstacle));
	displaying(Line, Line2, **Obstacle, *Player);
}

void game_over(bool& fall,  obstacle** Obstacle)
{
	(*Obstacle)->Behavior(**Obstacle, &(*Obstacle), fall);	
	cout << "You loose a game, please try again. "<<endl;
	fall = false;
	system("pause");
}

char death_output(obstacle Obstacle, player Player)
{
	for (int counter{}; counter < right_border; counter++)
		if (Obstacle.GetX() == Player.GetX() &&
			Obstacle.GetY() == Player.GetY())
			return 'x';
	return NULL;
}

char embedded_loops(part_of_line Line[], part_of_line Line2[], obstacle Obstacle, player Player, int x, int y)
{
	if (Player.GetX() == x && Player.GetY() == y)
		return Player.GetSymbol();
	for (int counter{}; counter < right_border; counter++)
	{
		if (Line[counter].GetX() == x && Line[counter].GetY() == y)
			return Line[counter].GetSymbol();
		else if (Line2[counter].GetX() == x && Line2[counter].GetY() == y)
			return Line2[counter].GetSymbol();
	}
	if (Obstacle.GetX() == x && Obstacle.GetY() == y)
		return Obstacle.GetSymbol();
	return ' ';
}

void displaying(part_of_line Line[], part_of_line Line2[], obstacle Obstacle, player Player)
{
	for (int y{}; y < bottom_border; y++)
	{
		for (int x{}; x < right_border; x++)
		{
			if (x == Obstacle.GetX() && y == Obstacle.GetY() &&
				x == Player.GetX() && y == Player.GetY())
			{
				if (death_output(Obstacle, Player))
					cout << death_output(Obstacle, Player);
			}			
			else
				cout << embedded_loops(Line, Line2, Obstacle, Player, x, y);
		}
	}
	
}

player::player()
{

}
player::player(int X, int Y, char Symbol)
{
	this->x = X;
	this->y = Y;
	this->symbol = Symbol;
}
player::~player()
{

}

int player::GetX()
{
	return this->x;
}
int player::GetY()
{
	return this->y;
}
void player::SetX(int X)
{
	this->x = X;
}
void player::SetY(int Y)
{
	this->y = Y;
}
char player::GetSymbol()
{
	return this->symbol;
}
void player::SetSymbol(char Symbol)
{
	this->symbol = Symbol;
}

void player::jump(bool& isjumped, int& iteration)
{
	if (isjumped && !iteration)
	{
		cout << char(7);
		this->y-=2;  
	}
	if (isjumped && iteration<8)
	{
		iteration++;
	}
	if (isjumped  && iteration>7)
	{
		isjumped = 0;
		this->y+=2;
		iteration = 0;
	}
}

obstacle::obstacle()
{
	this->x = 80;
	this->y = 3;
	this->symbol = rand() % 255;
}
obstacle::obstacle(int X, int Y, char Symbol)
{
	this->x = X;
	this->y = Y;
	this->symbol = Symbol;
}
obstacle::~obstacle()
{
	
}

int obstacle::GetX()
{
	return this->x;
}
int obstacle::GetY()
{
	return this->y;
}
void obstacle::SetX(int X)
{
	this->x = X;
}
void obstacle::SetY(int Y)
{
	this->y = Y;
}
char obstacle::GetSymbol()
{
	return this->symbol;
}
void obstacle::SetSymbol(char Symbol)
{
	this->symbol = Symbol;
}

void obstacle::Behavior(obstacle& Obstacle, obstacle** P_obstacle, bool fall)
{
	if (Obstacle.GetX() > 0)
		Obstacle.SetX(Obstacle.GetX() - 1);
	if (0 == Obstacle.GetX() || fall)
	{
		delete& Obstacle;
		*P_obstacle = new obstacle();
	}
}