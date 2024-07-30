#include <SFML/Graphics.hpp>
#include <iostream>


#define LUNGIME 8
#define PionNEGRU 1
#define PionALB -1
#define TurnNEGRU 2
#define TurnALB -2
#define CalALB -3
#define CalNEGRU 3
#define NebunNEGRU 4
#define NebunALB -4
#define ReginaALB -5
#define ReginaNEGRU 5
#define RegeNEGRU 6
#define RegeALB -6

using namespace sf;

struct poz
{
	int x, y;
}oldPoz, regeleAlb, regeleNegru, transformA, transformN, hyperjampPionNegru;

int  size = 100, move = 0, x, y;
/*int board[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2,};*/
int board[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, -6, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1, -1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2,};
 
 int board_marker[8][8] =
{ 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,};
int board_copy[8][8] =
{ 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,};
 int board_marker_or[8][8] =
{ 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,};

int turnAlbDreapta = 0, turnAlbStanga = 0, regeAlb = 0;
int turnNegruDreapta = 0, turnNegruStanga = 0, regeNegru = 0;

int mutare = 0; // 0 muta albul, 1 muta negru

int sahAlb = 0, sahNegru = 0;

int transformareAlb = 0, transformareNegru = 0;


int PionA(int ox, int oy, int nx, int ny)// ??????? ???????? ????? ?????
{
	if (oldPoz.y == 6)// ??????? ???? ?? B
	{
		if ((ny == oy - 1 && nx == ox && board[oy-1][ox]==0)||(ny==oy-2 && nx==ox && board[oy - 1][ox] == 0 && board[oy - 2][ox]==0))
		{
			return 1;
		}
	}
	else if(ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0)
	{
		return 1;
	}
	if (board[oy - 1][ox - 1] > 0)
	{
		if (ny == oy - 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy - 1][ox + 1] > 0)
	{
		if (ny == oy - 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	if ((hyperjampPionNegru.y == oy) && (hyperjampPionNegru.x == ox-1))
	{
		if (ny == oy - 1 && nx == ox - 1)
		{
			return 1;
		}
		  
	}
	if ((hyperjampPionNegru.y == oy) && (hyperjampPionNegru.x == ox+1))
	{
		if (ny == oy - 1 && nx == ox + 1)
		{
			return 1;
		}
		  
	}
	
	
	return 0;
}

	
int PionN(int ox, int oy, int nx, int ny)

{
	hyperjampPionNegru.x = -1;
	hyperjampPionNegru.y = -1;
	if (oldPoz.y == 1)
	{
		if ((ny == oy + 1 && nx == ox && board[oy+1][ox]==0) || (ny == oy + 2 && nx == ox && board[oy + 1][ox] == 0 && board[oy + 2][ox] == 0))
		{
			if (ny == oy + 2 && nx == ox && board[oy + 1][ox] == 0 && board[oy + 2][ox] == 0)
			{	
			hyperjampPionNegru.x = nx;
			hyperjampPionNegru.y = ny;
			}
			return 1;
		}
	}
	else if (ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0)
	{
		return 1;
	}
	if (board[oy + 1][ox - 1] < 0)
	{
		if (ny == oy + 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] < 0)
	{
		if (ny == oy + 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	
	
	return 0;
}

int TurnA(int ox, int oy, int nx, int ny)
{
	for (int i = ox-1; i >= 0; i--) // spre stanga ??????
	{
		if (board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus ????? 
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0 )
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta ???????
	{
		if (board[oy][i]>=0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos ???? [???]
	{
		if (board[i][ox]>=0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	
	
	
	return 0;
}

int TurnN(int ox, int oy, int nx, int ny)
{
	hyperjampPionNegru.x = -1;
	hyperjampPionNegru.y = -1;
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta
	{
		if (board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int NebunA(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int NebunN(int ox, int oy, int nx, int ny)
{
	hyperjampPionNegru.x = -1;
	hyperjampPionNegru.y = -1;
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int ReginaA(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta
	{
		if (board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int ReginaN(int ox, int oy, int nx, int ny)
{	
	hyperjampPionNegru.x = -1;
	hyperjampPionNegru.y = -1;
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta
	{
		if (board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int CalA(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 <LUNGIME && ny == oy - 2 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		return 1; // dreapta sus
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && ny==oy-1 && nx==ox+2 && board[ny][nx]>=0)
	{
		return 1; // dreapta 1
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && ny == oy + 1 && nx == ox + 2 && board[ny][nx] >= 0)
	{
		return 1; // dreapta 2
	}
	if (oy+2<LUNGIME && ox+1<LUNGIME && ny==oy+2 && nx==ox+1 && board[ny][nx]>=0)
	{
		return 1; // jos 1
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		return 1; //jos 2
	}
	if (oy+1<LUNGIME && ox-2>=0 && ny==oy+1 && nx==ox-2 && board[ny][nx]>=0 )
	{
		return 1; // stanga 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] >= 0)
	{
		return 1;
	}
	return 0;
}

int CalN(int ox, int oy, int nx, int ny)
{
	hyperjampPionNegru.x = -1;
	hyperjampPionNegru.y = -1;
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 < LUNGIME && ny == oy - 2 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		return 1; // dreapta sus
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && ny == oy - 1 && nx == ox + 2 && board[ny][nx] <= 0)
	{
		return 1; // dreapta 1
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && ny == oy + 1 && nx == ox + 2 && board[ny][nx] <= 0)
	{
		return 1; // dreapta 2
	}
	if (oy + 2 < LUNGIME && ox + 1 < LUNGIME && ny == oy + 2 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		return 1; // jos 1
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		return 1; //jos 2
	}
	if (oy + 1 < LUNGIME && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] <= 0)
	{
		return 1; // stanga 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] <= 0)
	{
		return 1;
	}
	return 0;
}


int PionASah(int posx, int posy, int regex, int regey)
{
	//std::cout << "ox=" << posx << " oy=" << posy << " regex=" << regex << " regey=" << regey << "\n\n\n";
	if (board[posy - 1][posx - 1] >= 0)
	{
		if (posy-1 == regey && posx - 1 == regex)
		{
			return 1;
		}
	}
	if (board[posy - 1][posx + 1] >= 0)
	{
		//std::cout << "da";
		if (posy - 1 == regey && posx + 1==regex)
		{
			return 1;
		}
	}
	return 0;
}

int TurnASah(int ox, int oy, int regex, int regey)
{
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] >= 0 && (regex== i && regey == oy))
		{
			return 1;
		}
		else if(board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if(board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LUNGIME; i++) // spre dreapta
	{
		if (board[oy][i] >= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if(board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <LUNGIME; i++) // jos
	{
		if (board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if(board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int NebunASah(int ox, int oy, int regex, int regey)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int ReginaASah(int ox, int oy, int regex, int regey)
{
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] >= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if(board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if(board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LUNGIME; i++) // spre dreapta
	{
		if (board[oy][i] >= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <LUNGIME; i++) // jos
	{
		if (board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if(board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < LUNGIME; i++)  // spre dreapta jos
	{
		if (board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int CalASah(int ox, int oy, int regex, int regey)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && regey == oy - 2 && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 < LUNGIME && regey == oy - 2 && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1; // dreapta sus
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && regey == oy - 1 && regex == ox + 2 && board[regey][regex] >= 0)
	{
		return 1; // dreapta 1
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && regey == oy + 1 && regex == ox + 2 && board[regey][regex] >= 0)
	{
		return 1; // dreapta 2
	}
	if (oy + 2 < LUNGIME && ox + 1 < LUNGIME && regey == oy + 2 && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1; // jos 1
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && regey == oy + 2 && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1; //jos 2
	}
	if (oy + 1 < LUNGIME && ox - 2 >= 0 && regey == oy + 1 && regex == ox - 2 && board[regey][regex] >= 0)
	{
		return 1; // stanga 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && regey == oy - 1 && regex == ox - 2 && board[regey][regex] >= 0)
	{
		return 1;
	}
	return 0;
}

int RegeASah(int ox, int oy, int regex, int regey)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && regey == oy - 1 && regex == ox - 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && regex == ox && regey == oy - 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && regex == ox + 1 && regey == oy - 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox + 1 < LUNGIME && regey == oy && regex == ox + 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox + 1 < LUNGIME && oy + 1 < LUNGIME && regey == oy + 1 && regex == ox + 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy + 1 < LUNGIME && regey == oy + 1 && regex == ox && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LUNGIME && regex == ox - 1 && regey == oy + 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && regey == oy && regex == ox - 1 && board[regey][regex] <= 0)
	{
		return 1;
	}
	return 0;
}


int PionNSah(int ox, int oy, int regex, int regey)
{
	if (board[oy + 1][ox - 1] <= 0)
	{
		if (regey == oy + 1 && regex == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] <= 0)
	{
		if (regey == oy + 1 && regex == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int TurnNSah(int ox, int oy, int regex, int regey)
{
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] <= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LUNGIME; i++) // spre dreapta
	{
		if (board[oy][i] <= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LUNGIME; i++) // jos
	{
		if (board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int NebunNSah(int ox, int oy, int regex, int regey)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int ReginaNSah(int ox, int oy, int regex, int regey)
{
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (board[oy][i] <= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LUNGIME; i++) // spre dreapta
	{
		if (board[oy][i] <= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LUNGIME; i++) // jos
	{
		if (board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < LUNGIME; i++)  // spre dreapta jos
	{
		if (board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}


int CalNSah(int ox, int oy, int regex, int regey)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && regey == oy - 2 && regex == ox - 1 && board[regey][regex] <= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 < LUNGIME && regey == oy - 2 && regex == ox + 1 && board[regey][regex] <= 0)
	{
		return 1; // dreapta sus
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && regey == oy - 1 && regex == ox + 2 && board[regey][regex] <= 0)
	{
		return 1; // dreapta 1
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && regey == oy + 1 && regex == ox + 2 && board[regey][regex] <= 0)
	{
		return 1; // dreapta 2
	}
	if (oy + 2 < LUNGIME && ox + 1 < LUNGIME && regey == oy + 2 && regex == ox + 1 && board[regey][regex] <= 0)
	{
		return 1; // jos 1
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && regey == oy + 2 && regex == ox - 1 && board[regey][regex] <= 0)
	{
		return 1; //jos 2
	}
	if (oy + 1 < LUNGIME && ox - 2 >= 0 && regey == oy + 1 && regex == ox - 2 && board[regey][regex] <= 0)
	{
		return 1; // stanga 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && regey == oy - 1 && regex == ox - 2 && board[regey][regex] <= 0)
	{
		return 1;
	}
	return 0;
}

int RegeNSah(int ox, int oy, int regex, int regey)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && regey == oy - 1 && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && regex == ox && regey == oy - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && regex == ox + 1 && regey == oy - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LUNGIME && regey == oy && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LUNGIME && oy + 1 < LUNGIME && regey == oy + 1 && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy + 1 < LUNGIME && regey == oy + 1 && regex == ox && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LUNGIME && regex == ox - 1 && regey == oy + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && regey == oy && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	return 0;
}



int RegeNegruSahCheck(int posRegex, int posRegey)// ???????? ?? ??? ??????
{
	int ok = 0;// ????????? ? ????????? 0
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			if (board[i][j] < 0)
			{
				if (board[i][j] == PionALB)
				{
					ok=PionASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == TurnALB)
				{
					ok=TurnASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == CalALB)
				{
					ok=CalASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == NebunALB)
				{
					ok=NebunASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == ReginaALB)
				{
					ok=ReginaASah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == RegeALB)
				{
					ok=RegeASah(j, i, posRegex, posRegey);
				}
				if (ok == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int RegeN(int ox, int oy, int nx, int ny)
{
	hyperjampPionNegru.x = -1;
	hyperjampPionNegru.y = -1;
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  // stanga sus
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy-1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox, oy-1);
		if (ok == 1)
		{
			return 1; // sus
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && nx == ox + 1 && ny == oy - 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox+ 1, oy- 1);
		if (ok == 1)
		{
			return 1; // dreapta sus
		}
	}
	if (ox + 1 < LUNGIME && ny == oy && nx == ox+1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox+1, oy);
		if (ok == 1)
		{
			return 1; // dreapta
		}
	}
	if (ox + 1 < LUNGIME && oy + 1 < LUNGIME && ny == oy + 1 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; // dreapta jos
		}
	}
	if (oy + 1 < LUNGIME && ny == oy+1 && nx == ox && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox, oy+1);
		if (ok == 1)
		{
			return 1; // jos
		}
	}
	if (ox - 1 >=0 && oy + 1 <LUNGIME && nx == ox - 1 && ny == oy + 1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox-1, oy+ 1);
		if (ok == 1)
		{
			return 1; // stanga jos
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox-1 && board[ny][nx] <= 0)
	{
		int ok = RegeNegruSahCheck(ox-1, oy);
		if (ok == 1)
		{
			return 1; // stanga
		}
	}
	// rocada in dreapta
	if (turnNegruDreapta==0 && regeNegru==0 && board[0][5]==0 && board[0][6]==0 && ny==0 && nx==6)
	{
		int ok = RegeNegruSahCheck(4, 0);
		if (ok == 1)
		{
			ok = RegeNegruSahCheck(5, 0);
			if (ok == 1)
			{
				ok = RegeNegruSahCheck(6, 0);
				if (ok == 1)
				{
					regeNegru = 1;
					turnNegruDreapta = 1;
					board[0][7] = 0;
					board[0][5] = TurnNEGRU;
					return 1;
				}
			}
		}
	}
	if (turnNegruStanga == 0 && regeNegru == 0 && board[0][3] == 0 && board[0][2] == 0 && board[0][1] == 0 && ny == 0 && nx == 2)
	{
		int ok = RegeNegruSahCheck(4, 0);
		if (ok == 1)
		{
			ok = RegeNegruSahCheck(3, 0);
			if (ok == 1)
			{
				ok = RegeNegruSahCheck(2, 0);
				if (ok == 1)
				{
					ok = RegeNegruSahCheck(1, 0);
					if (ok == 1)
					{
						regeNegru = 1;
						turnNegruStanga = 1;
						board[0][0] = 0;
						board[0][3] = TurnNEGRU;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


int RegeAlbSahCheck(int posRegex, int posRegey)// ???????? ?? ??? ?????
{
	int ok = 0;// ????????? ??????????
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			if (board[i][j] > 0)
			{
				if (board[i][j] == PionNEGRU)
				{
					ok = PionNSah(j, i, posRegex, posRegey);// ?????? ?????
				}
				if (board[i][j] == TurnNEGRU)
				{
					ok = TurnNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == CalNEGRU)
				{
					ok = CalNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == NebunNEGRU)
				{
					ok = NebunNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == ReginaNEGRU)
				{
					ok = ReginaNSah(j, i, posRegex, posRegey);
				}
				if (board[i][j] == RegeNEGRU)
				{
					ok=RegeNSah(j, i, posRegex, posRegey);
				}
				if (ok == 1)
				{
					//	std::cout << "da" << "\n";
				
					return 0; // ??? ?????
				}
			}
		}
	}

	return 1; // ??? ???? ?????
}


int RegeA(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  // stanga sus
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox, oy - 1);
		if (ok == 1)
		{
			return 1; // sus
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && nx == ox + 1 && ny == oy - 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; // dreapta sus
		}
	}
	if (ox + 1 < LUNGIME && ny == oy && nx == ox + 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy);
		if (ok == 1)
		{
			return 1; // dreapta
		}
	}
	if (ox + 1 < LUNGIME && oy + 1 < LUNGIME && ny == oy + 1 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; // dreapta jos
		}
	}
	if (oy + 1 < LUNGIME && ny == oy + 1 && nx == ox && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox, oy + 1);
		if (ok == 1)
		{
			return 1; // jos
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LUNGIME && nx == ox - 1 && ny == oy + 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; // stanga jos
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy);
		if (ok == 1)
		{
			return 1; // stanga
		}
	}
	// rocada in dreapta
	if (regeAlb == 0 && turnAlbDreapta == 0 && board[7][5] == 0 && board[7][6] == 0 && ny==7 && nx==6)
	{
		int ok = 1;
		ok = RegeAlbSahCheck(4, 7);
		if (ok == 1)
		{
			ok = RegeAlbSahCheck(5, 7);
			if (ok == 1)
			{
				ok = RegeAlbSahCheck(6, 7);
				if (ok == 1)
				{
					board[7][7] = 0;
					board[7][5] = TurnALB;
					regeAlb = 1;
					turnAlbDreapta = 1;
					return 1;
				}
			}
		}
	}
	// rocada in stanga
	if (regeAlb == 0 && turnAlbDreapta == 0 && board[7][3] == 0 && board[7][2] == 0 && board[7][1] == 0 && ny == 7 && nx == 2)
	{
		int ok = 1;
		ok = RegeAlbSahCheck(4, 7);
		if (ok == 1)
		{
			ok = RegeAlbSahCheck(3, 7);
			if (ok == 1)
			{
				ok = RegeAlbSahCheck(2, 7);
				if (ok == 1)
				{
					ok = RegeAlbSahCheck(1, 7);
					if (ok == 1)
					{
						board[7][0] = 0;
						board[7][3] = TurnALB;
						regeAlb = 1;
						turnAlbStanga = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


void pozRegeAlb()
{
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			if (board[i][j] == RegeALB)
			{
				regeleAlb.x = j;
				regeleAlb.y = i;
				break;
			}
		}
	}
}

void pozRegeNegru()
{
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			if (board[i][j] == RegeNEGRU)
			{
				regeleNegru.y = i;
				regeleNegru.x = j;
				break;
			}
		}
	}
}


int MarkerPionA(int ox, int oy)

{	
	board_marker[oy-1][ox] = !board[oy-1][ox];
	if ((oy == 6) && !board[oy-1][ox])// ??????? ???? ?? B
	{
		board_marker[oy-2][ox] = !board[oy-2][ox];
	}
	
	if (ox >= 0 && ox <= 6 && board[oy-1][ox+1] > 0)
	{

		board_marker[oy-1][ox+1] = 1;

	}
	
	if (ox >= 1 && ox <= 7 && board[oy-1][ox-1] > 0)
	{

		board_marker[oy-1][ox-1] = 1;

	}
	
		/*if ((hyperjampPionNegru.y == oy) && (hyperjampPionNegru.x == ox-1))
		{
			board_marker[hyperjampPionNegru.x][hyperjampPionNegru.y] = true;
		}*/
		
		if ((hyperjampPionNegru.y == oy) && ((hyperjampPionNegru.x == ox-1) || (hyperjampPionNegru.x == ox+1))){
	
		  board_marker[hyperjampPionNegru.y-1][hyperjampPionNegru.x] = true;
		}
		
	// ???????? ????????? ????
		for (int i = 0; i < LUNGIME; i++)
		{
			for (int j = 0; j < LUNGIME; j++)
			{
				board_copy[j][i] = board[j][i];
			}
			
		}
	
	int ok = 0;
	pozRegeAlb();
	for (int i = 0; i < LUNGIME; i++)
		{
			for (int j = 0; j < LUNGIME; j++)
			{
				if (board_marker[j][i]) {
										
					board[j][i] = PionALB;
					ok =  RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
							
					if (!ok) {board_marker[j][i] = 0;}
						
					}
					
					// ?????????? ?????????????? ????????? ????
					for (int i = 0; i < LUNGIME; i++)
						{
							for (int j = 0; j < LUNGIME; j++)
							{
								board[j][i] = board_copy[j][i];
							}
							
						}			
				
			}
		}
	
	
	return 0;
}

int MarkerTurnA(int ox, int oy)

{	
	for (int i = ox-1; i >= 0; i--) // spre stanga ??????
	{
		if (board[oy][i] == 0)
		{
			board_marker[oy][i] = true;
		}
		else if (board[oy][i] > 0)
		{
			board_marker[oy][i] = true;
			break;
		}
		
		else break;
	}
	
	for (int i = oy - 1; i >= 0; i--) // sus ????? 
	{
		if (board[i][ox] == 0)
		{
			board_marker[i][ox] = true;
		}
		else if (board[i][ox] > 0)
		{
			board_marker[i][ox] = true;
			break;
		}
		
		else break;
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta ???????
	{
		if (board[oy][i] == 0)
		{
			board_marker[oy][i] = true;
		}
		else if (board[oy][i] > 0)
		{
			board_marker[oy][i] = true;
			break;
		}
		
		else break;
	}
	for (int i = oy + 1; i <= 7; i++) // jos ???? [???]
	{
		if (board[i][ox] == 0)
		{
			board_marker[i][ox] = true;
		}
		else if (board[i][ox] > 0)
		{
			board_marker[i][ox] = true;
			break;
		}
		
		else break;
	}
	
	return 0;
}


int MarkerNebunA(int ox, int oy)
{
	int j = ox;
	for (int i = oy - 1; i >= 0; i--) // ?????? ?????
	{
		j--;
		if (j < 0 || j > 7)
		 {break;}
		if (board[i][j] == 0)
		{
			board_marker[i][j]= true;
		}
		else if (board[i][j] > 0)
		{
			board_marker[i][j]= true;
			break;
		}
		else break;
		
	}
	j = ox;
	for (int i = oy - 1; i >= 0; i--) // ??????? ?????
	{
		j++;
		if (j < 0 || j > 7)
		 {break;}
		if (board[i][j] == 0)
		{
			board_marker[i][j]= true;
		}
		else if (board[i][j] > 0)
		{
			board_marker[i][j]= true;
			break;
		}
		else break;
		
	}	
	j = ox;
	for (int i = oy + 1; i <= 7; i++) // ?????? ????
	{
		j--;
		if (j < 0 || j > 7)
		 {break;}
		if (board[i][j] == 0)
		{
			board_marker[i][j]= true;
		}
		else if (board[i][j] > 0)
		{
			board_marker[i][j]= true;
			break;
		}
		else break;
		
	}
	j = ox;
	for (int i = oy + 1; i <= 7; i++) // ??????? ????
	{
		j++;
		if (j < 0 || j > 7)
		 {break;}
		if (board[i][j] == 0)
		{
			board_marker[i][j]= true;
		}
		else if (board[i][j] > 0)
		{
			board_marker[i][j]= true;
			break;
		}
		else break;
		
	}
}

int MarkerReginaA(int ox, int oy)

{	
	int j = ox;
	for (int i = ox-1; i >= 0; i--) // spre stanga ??????
	{
		if (board[oy][i] == 0)
		{
			board_marker[oy][i] = true;
		}
		else if (board[oy][i] > 0)
		{
			board_marker[oy][i] = true;
			break;
		}
		
		else break;
	}
	
	for (int i = oy - 1; i >= 0; i--) // sus ????? 
	{
		if (board[i][ox] == 0)
		{
			board_marker[i][ox] = true;
		}
		else if (board[i][ox] > 0)
		{
			board_marker[i][ox] = true;
			break;
		}
		
		else break;
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta ???????
	{
		if (board[oy][i] == 0)
		{
			board_marker[oy][i] = true;
		}
		else if (board[oy][i] > 0)
		{
			board_marker[oy][i] = true;
			break;
		}
		
		else break;
	}
	for (int i = oy + 1; i <= 7; i++) // jos ???? [???]
	{
		if (board[i][ox] == 0)
		{
			board_marker[i][ox] = true;
		}
		else if (board[i][ox] > 0)
		{
			board_marker[i][ox] = true;
			break;
		}
		
		else break;
	}
	
	for (int i = oy - 1; i >= 0; i--) // ?????? ?????
	{
		j--;
		if (j < 0 || j > 7)
		 {break;}
		if (board[i][j] == 0)
		{
			board_marker[i][j]= true;
		}
		else if (board[i][j] > 0)
		{
			board_marker[i][j]= true;
			break;
		}
		else break;	
	}
	j = ox;
	for (int i = oy - 1; i >= 0; i--) // ??????? ?????
	{
		j++;
		if (j < 0 || j > 7)
		 {break;}
		if (board[i][j] == 0)
		{
			board_marker[i][j]= true;
		}
		else if (board[i][j] > 0)
		{
			board_marker[i][j]= true;
			break;
		}
		else break;	
	}	
	j = ox;
	for (int i = oy + 1; i <= 7; i++) // ?????? ????
	{
		j--;
		if (j < 0 || j > 7)
		 {break;}
		if (board[i][j] == 0)
		{
			board_marker[i][j]= true;
		}
		else if (board[i][j] > 0)
		{
			board_marker[i][j]= true;
			break;
		}
		else break;	
	}
	j = ox;
	for (int i = oy + 1; i <= 7; i++) // ??????? ????
	{
		j++;
		if (j < 0 || j > 7)
		 {break;}
		if (board[i][j] == 0)
		{
			board_marker[i][j]= true;
		}
		else if (board[i][j] > 0)
		{
			board_marker[i][j]= true;
			break;
		}
		else break;
	}
	return 0;
}

void clearmarker()
{
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			board_marker[i][j] = 0;
		}
	}
}
int MarkerCalA(int ox, int oy)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && board[oy - 2][ox - 1] >= 0)
	{
		board_marker[oy - 2][ox - 1] = true; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 <LUNGIME && board[oy - 2 ][ox + 1] >= 0)
	{
		board_marker[oy - 2][ox + 1] = true;
	}
	if (oy - 1 >= 0 && ox + 2 < LUNGIME && board[oy - 1][ox + 2]>=0)
	{
		board_marker[oy - 1][ox + 2] = true;
	}
	if (oy + 1 >= 0 && ox + 2 < LUNGIME && board[oy + 1][ox + 2] >= 0)
	{
		board_marker[oy + 1][ox + 2] = true;
	}
	if (oy+2<LUNGIME && ox+1<LUNGIME && board[oy+2][ox+1]>=0)
	{
		board_marker[oy + 2][ox + 1] = true;
	}
	if (oy + 2 < LUNGIME && ox - 1 >= 0 && board[oy + 2][ox - 1] >= 0)
	{
		board_marker[oy + 2][ox - 1] = true;
	}
	if (oy+1<LUNGIME && ox-2>=0 && board[oy+1][ox-2]>=0 )
	{
		board_marker[oy + 1][ox - 2] = true;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && board[oy - 1][ox - 2] >= 0)
	{
		board_marker[oy - 1][ox - 2] = true;
	}
	return 0;
}

int MarkerRegeA(int ox, int oy)
{
	if (oy - 1 >= 0 && ox - 1 >= 0 && board[oy - 1][ox - 1] >= 0)
	{
		board_marker[oy - 1][ox - 1] = true; // stanga sus
	}
	if (oy - 1 >= 0 && ox  <LUNGIME && board[oy - 1][ox] >= 0)
	{
		board_marker[oy - 1][ox] = true;
	}
	if (oy - 1 >= 0 && ox + 1 < LUNGIME && board[oy - 1][ox + 1]>=0)
	{
		board_marker[oy - 1][ox + 1] = true;
	}
	if (oy >= 0 && ox + 1 < LUNGIME && board[oy + 1][ox + 1] >= 0)
	{
		board_marker[oy][ox + 1] = true;
	}
	if (oy+1<LUNGIME && ox+1<LUNGIME && board[oy+1][ox+1]>=0)
	{
		board_marker[oy + 1][ox + 1] = true;
	}
	if (oy + 1 < LUNGIME && ox >= 0 && board[oy + 1][ox - 1] >= 0)
	{
		board_marker[oy + 1][ox] = true;
	}
	if (oy+1<LUNGIME && ox-1>=0 && board[oy+1][ox-1]>=0 )
	{
		board_marker[oy + 1][ox - 1] = true;
	}
	if (oy >= 0 && ox - 1 >= 0 && board[oy - 1][ox - 1] >= 0)
	{
		board_marker[oy ][ox - 1] = true;
	}
	return 0;
}

void clearmarker_or()
{
	for (int i = 0; i < LUNGIME; i++)
	{
		for (int j = 0; j < LUNGIME; j++)
		{
			board_marker_or[i][j] = 0;
		}
	}
}


int main()
{
	RenderWindow window(VideoMode(800, 800), "Chess made by Silvian Achim");
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	Texture tm1, tm2;

	t1.loadFromFile("images/board.png");
	t2.loadFromFile("images/PionNegru.png");
	t3.loadFromFile("images/PionAlb.png");
	t4.loadFromFile("images/TurnNegru.png");
	t5.loadFromFile("images/TurnAlb.png");
	t6.loadFromFile("images/CalAlb.png");
	t7.loadFromFile("images/CalNegru.png");
	t8.loadFromFile("images/NebunNegru.png");
	t9.loadFromFile("images/NebunAlb.png");
	t10.loadFromFile("images/ReginaAlb.png");
	t11.loadFromFile("images/ReginaNegru.png");
	t12.loadFromFile("images/RegeNegru.png");
	t13.loadFromFile("images/RegeAlb.png");
	t14.loadFromFile("images/TransformareAlb.png");
	t15.loadFromFile("images/TransformareNegru.png");
	tm1.loadFromFile("images/pointAlb.png");
	tm2.loadFromFile("images/pointAlb_or.png");
	Sprite tabla(t1); //????
	Sprite PionNegru(t2);//?????? ?????
	Sprite PionAlb(t3);//????? ?????
	Sprite TurnNegru(t4);//?????? ?????
	Sprite TurnAlb(t5);//????? ?????
	Sprite CalAlb(t6);//?????? ????
	Sprite CalNegru(t7);//????? ????
	Sprite NebunNegru(t8);//?????? ??????
	Sprite NebunAlb(t9);//????? ??????
	Sprite ReginaAlb(t10);//?????? ?????
	Sprite ReginaNegru(t11);//????? ?????
	Sprite RegeNegru(t12);//?????? ??????
	Sprite RegeAlb(t13);//????? ??????
	Sprite Mutare;// ??????????? ?????? ?? ????? ???????? ? ?????? ?? ??????
	Sprite TransformareALB(t14);
	Sprite TransformareNEGRU(t15);
	
	Sprite Marker_green(tm1);// ??????? ??????
	Sprite Marker_orange(tm2);// ????????? ??????

	float dx = 0, dy = 0;
	int numarPiesaMutata = 0;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		 x = pos.x / size;
		 y = pos.y / size;
		Event e;// ?????????? ???????? ?? ???????
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			window.clear();
			if (e.type == Event::MouseButtonPressed)//?? ??????? ??????? ?? ?????? ????
			{
				if (e.key.code == Mouse::Left)// ????? ??????
				{
					//std::cout << "x=" << x << " y=" << y << "\n";
					//std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
					//std::cout << "board[y][x]=" << board[y][x] << "\n";
					//std::cout << "\n";
					if (transformareAlb == 1)// ????? ????? ?????? ? ???????????
					{
						if (pos.y >= transformA.y * size && pos.y <= (transformA.y + 1) * size && pos.x >= transformA.x * size && pos.x <= (transformA.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								board[transformA.y][transformA.x] = TurnALB;
								transformareAlb = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								board[transformA.y][transformA.x] = ReginaALB;
								transformareAlb = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								board[transformA.y][transformA.x] = CalALB;
								transformareAlb = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								board[transformA.y][transformA.x] = NebunALB;
								transformareAlb = 0;
							}
							if (transformareAlb == 0)
							{
								pozRegeNegru();
								int h = RegeNegruSahCheck(regeleNegru.x, regeleNegru.y);
								if (h == 0)
								{
									sahNegru = 1;
								}
							}
						}
					}
					if (transformareNegru == 1)// ?????? ????? ?????? ? ???????????
					{
						if (pos.y >= transformN.y * size && pos.y <= (transformN.y + 1) * size && pos.x >= transformN.x * size && pos.x <= (transformN.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								board[transformN.y][transformN.x] = TurnNEGRU;
								transformareNegru = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								board[transformN.y][transformN.x] = ReginaNEGRU;
								transformareNegru = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								board[transformN.y][transformN.x] = CalNEGRU;
								transformareNegru = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								board[transformN.y][transformN.x] = NebunNEGRU;
								transformareNegru = 0;
							}
							if (transformareNegru == 0)
							{
								pozRegeAlb();
								int h = RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (h == 0)
								{
									sahAlb = 1;
								}
							}
						}
					}
					if (board[y][x] != 0)// ?? ????? ?????? ??????
					{
						dx = pos.x - x * 100;
						dy = pos.y - y * 100;
						if (board[y][x] == PionNEGRU && mutare==1)
						{
							numarPiesaMutata = PionNEGRU;
							Mutare = PionNegru;
							board[y][x] = 0;
						}
						if (board[y][x] == PionALB && mutare==0)
						{
							numarPiesaMutata = PionALB;
							Mutare = PionAlb;
							board[y][x] = 0;
							
							
							MarkerPionA(x,y);
							//MarkerPionA(y,x);
							// ?????? ??????
										
						}
						if (board[y][x] == TurnNEGRU && mutare ==1)
						{
							numarPiesaMutata = TurnNEGRU;
							Mutare = TurnNegru;
							board[y][x] = 0;

						}
						if (board[y][x] == TurnALB && mutare ==0)
						{
							numarPiesaMutata = TurnALB;
							Mutare = TurnAlb;
							board[y][x] = 0;
							MarkerTurnA(x,y);

						}
						if (board[y][x] == CalALB && mutare ==0)
						{
							numarPiesaMutata = CalALB;
							Mutare = CalAlb;
							board[y][x] = 0;
							MarkerCalA(x,y);
						}
						if (board[y][x] == CalNEGRU && mutare ==1)
						{
							numarPiesaMutata = CalNEGRU;
							Mutare = CalNegru;
							board[y][x] = 0;
						}
						if (board[y][x] == NebunNEGRU && mutare ==1)
						{
							numarPiesaMutata = NebunNEGRU;
							Mutare = NebunNegru;
							board[y][x] = 0;
						}
						if (board[y][x] == NebunALB && mutare ==0)
						{
							numarPiesaMutata = NebunALB;
							Mutare = NebunAlb;
							board[y][x] = 0;
							MarkerNebunA(x,y);
						}
						if (board[y][x] == ReginaALB && mutare==0)
						{
							numarPiesaMutata = ReginaALB;
							Mutare = ReginaAlb;
							board[y][x] = 0;
							MarkerReginaA(x,y);
						}
						if (board[y][x] == ReginaNEGRU && mutare ==1)
						{
							numarPiesaMutata = ReginaNEGRU;
							Mutare = ReginaNegru;
							board[y][x] = 0;
						}
						if (board[y][x] == RegeNEGRU && mutare==1)
						{
							numarPiesaMutata = RegeNEGRU;
							Mutare = RegeNegru;
							board[y][x] = 0;
						}
						if (board[y][x] == RegeALB && mutare==0)
						{
							numarPiesaMutata = RegeALB;
							Mutare = RegeAlb;
							board[y][x] = 0;
							MarkerRegeA(x,y);
						}
						if (board[y][x] == 0)
						{
							move = 1;
							oldPoz.x = x;
							oldPoz.y = y;
						}
					}
				}
			}
			if (e.type == Event::MouseButtonReleased)// ????? ????????? ??????, ?? ???? ???????? ??????
			{
				if (e.key.code == Mouse::Left)
				{
					int ok=2;// ????????? ? ????????? 2
					if (numarPiesaMutata == PionALB && move==1)
					{
						 ok = PionA(oldPoz.x, oldPoz.y, x, y);
						 if (ok)
						 {
						 	if ((hyperjampPionNegru.y == oldPoz.y) && ((hyperjampPionNegru.x == oldPoz.x-1) || (hyperjampPionNegru.x == oldPoz.x+1)) && (hyperjampPionNegru.x == x))
							{
								board[hyperjampPionNegru.y][hyperjampPionNegru.x] = false;
							}
						 }
					}
					if (numarPiesaMutata == PionNEGRU && move == 1)
					{
						ok = PionN(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == TurnALB && move == 1)
					{
						ok = TurnA(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && turnAlbStanga==0 && oldPoz.y == 7 && oldPoz.x == 0)
						{
							turnAlbStanga = 1;
							//std::cout << turnAlbStanga << "\n";
						}
						if (ok == 1 && turnAlbDreapta==0 && oldPoz.y == 7 && oldPoz.x == 7)
						{
							turnAlbDreapta = 1;
							//std::cout << turnAlbDreapta << "\n";
						}
					}
					if (numarPiesaMutata == TurnNEGRU && move == 1)
					{
						ok=TurnN(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && turnNegruDreapta == 0 && oldPoz.y == 0 && oldPoz.x == 7)
						{
							turnNegruDreapta = 1;
							//std::cout << turnNegruDreapta<< "\n";
						}
						if (ok == 1 && turnNegruStanga == 0 && oldPoz.y == 0 && oldPoz.x == 0)
						{
							turnNegruStanga = 1;
							//std::cout << turnNegruStanga << "\n";
						}
					}
					if (numarPiesaMutata == NebunALB && move == 1)
					{
						ok = NebunA(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == NebunNEGRU && move == 1)
					{
						ok= NebunN(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == ReginaALB && move == 1)
					{
						ok=ReginaA(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == ReginaNEGRU && move == 1)
					{
						ok=ReginaN(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == CalALB && move == 1)
					{
						ok=CalA(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == CalNEGRU && move == 1)
					{
						ok = CalN(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == RegeNEGRU && move == 1)
					{
						ok=RegeN(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && regeNegru == 0)
						{
							regeNegru = 1;
						//	std::cout << regeNegru << "\n";
						}
					}
					if (numarPiesaMutata == RegeALB && move == 1)
					{
						ok=RegeA(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && regeAlb == 0)
						{
							regeAlb = 1;
							//std::cout << "primaMutareREGEalb=" << regeAlb << "\n";
						}
					}
					if (ok == 1)
					{
						int nr = board[y][x];
						board[y][x] = numarPiesaMutata;
						if (y == 0 && numarPiesaMutata == PionALB)
						{
							transformareAlb = 1;
							transformA.x = x;
							transformA.y = y;
							board[y][x] = 0;
						}
						if (y == 7 && numarPiesaMutata == PionNEGRU)
						{
							transformareNegru = 1;
							transformN.x = x;
							transformN.y = y;
							board[y][x] = 0;
						}
						if(mutare==0) // albul a mutat si urmeaza negrul
						{
							if (sahAlb == 1)
							{
								pozRegeAlb();
								int s = RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (s == 0)
								{
									board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									board[y][x] = nr;
									
								}
								else
								{
									sahAlb = 0;
									pozRegeNegru();
									int sah = RegeNegruSahCheck(regeleNegru.x,regeleNegru.y);
									if (sah == 0)
									{
										sahNegru = 1;
									}
									mutare = 1;
								}
							}
							else
							{
								pozRegeAlb();
								int sa = RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (sa == 0)
								{
									board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									board[y][x] = nr;
								}
								else
								{
									pozRegeNegru();
									int sah = RegeNegruSahCheck(regeleNegru.x, regeleNegru.y);
									if (sah == 0)
									{
										sahNegru = 1;
									}
									mutare = 1;
								}
							}
						}
						else // negrul a mutat si urmeaza albul
						{
							if (sahNegru == 1)
							{
								pozRegeNegru();
								int s = RegeNegruSahCheck(regeleNegru.x,regeleNegru.y);
								if (s == 0)
								{
									board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									board[y][x] = nr;
								}
								else
								{
									sahNegru = 0;
									pozRegeAlb();
									int sah = RegeAlbSahCheck(regeleAlb.x,regeleAlb.y);
									if (sah == 0)
									{
										sahAlb = 1;
									}
									mutare = 0;
								}
							}
							else
							{
								pozRegeNegru();
								int sa = RegeNegruSahCheck(regeleNegru.x, regeleNegru.y);
								if (sa == 0)
								{
									board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									board[y][x] = nr;
								}
								else
								{
									pozRegeAlb();
									int sah = RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
									if (sah == 0)
									{
										sahAlb = 1;
									}
									mutare = 0;
								}
							}
						}
					}
					else if(ok==0)//??? ?? ??????
					{
						board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
					}
					
                   move = 0;
                   clearmarker(); //??????? ??????? ????? ?????????? ?????? ?? ????
				}
			}
		}
		// afisare //
		window.clear();
		window.draw(tabla);// ?????? ?????
		if (transformareAlb == 1)
		{
			TransformareALB.setPosition(transformA.x* size, transformA.y* size);
			window.draw(TransformareALB);
		}
		if (transformareNegru == 1)
		{
			TransformareNEGRU.setPosition(transformN.x* size, transformN.y* size);
			window.draw(TransformareNEGRU);
		}
		if (move == 1)
		{
			Mutare.setPosition(pos.x-dx, pos.y-dy);
			window.draw(Mutare);// ???????????? ?????????????? ??????
		}
		for (int i = 0; i < LUNGIME; i++)// ??????????? ??????? ???????? board[i][j]
		{
			for (int j = 0; j < LUNGIME; j++)
			{

				if (board[i][j] != 0)
				{
					if (board[i][j] == PionNEGRU)
					{
						PionNegru.setPosition(j * size, i * size);
						window.draw(PionNegru);
					}
					if (board[i][j] == PionALB)
					{
						PionAlb.setPosition(j * size, i * size);
						window.draw(PionAlb);
					}
					if (board[i][j] == TurnNEGRU)
					{
						TurnNegru.setPosition(j * size, i * size);
						window.draw(TurnNegru);

					}
					if (board[i][j] == TurnALB)
					{
						TurnAlb.setPosition(j * size, i * size);
						window.draw(TurnAlb);

					}
					if (board[i][j] == CalALB)
					{
						CalAlb.setPosition(j * size, i * size);
						window.draw(CalAlb);
					}
					if (board[i][j] == CalNEGRU)
					{
						CalNegru.setPosition(j * size, i * size);
						window.draw(CalNegru);
					}
					if (board[i][j] == NebunNEGRU)
					{
						NebunNegru.setPosition(j * size, i * size);
						window.draw(NebunNegru);
					}
					if (board[i][j] == NebunALB)
					{
						NebunAlb.setPosition(j * size, i * size);
						window.draw(NebunAlb);
					}
					if (board[i][j] == ReginaALB)
					{
						ReginaAlb.setPosition(j * size, i * size);
						window.draw(ReginaAlb);
					}
					if (board[i][j] == ReginaNEGRU)
					{
						ReginaNegru.setPosition(j * size, i * size);
						window.draw(ReginaNegru);
					}
					if (board[i][j] == RegeNEGRU)
					{
						RegeNegru.setPosition(j * size, i * size);
						window.draw(RegeNegru);
					}
					if (board[i][j] == RegeALB)
					{
						RegeAlb.setPosition(j * size, i * size);
						window.draw(RegeAlb);
					}
				}
			}
		}
		for (int i = 0; i < LUNGIME; i++)// ??????????? ????? ???????? board_marker[i][j]
		{
			for (int j = 0; j < LUNGIME; j++)
			{
				/*if (hyperjampPionNegru.x != -1)
				{
					board_marker[hyperjampPionNegru.x][hyperjampPionNegru.y] = 1;
				}*/
				if (board_marker[i][j] != 0)
				{
					//if (board[i][j] == 0)
					//{
						//Marker_green.setColor(sf::Color(255, 255, 255, 128));
						Marker_green.setPosition(j * size, i * size);
						
						window.draw(Marker_green);
					//}
				
				}
				
				
			}
		}
		
		clearmarker_or();
				if (hyperjampPionNegru.x != -1)
				{
					board_marker_or[hyperjampPionNegru.y][hyperjampPionNegru.x] = 1;
				}
		
		for (int i = 0; i < LUNGIME; i++)// ??????????? ????? ???????? board_marker_or[i][j]
		{
			for (int j = 0; j < LUNGIME; j++)
			{
				
				if (board_marker_or[i][j] != 0)
				{
					//if (board[i][j] == 0)
					//{
						//Marker_green.setColor(sf::Color(255, 255, 255, 128));
						Marker_orange.setPosition(j * size, i * size);
						
						window.draw(Marker_orange);
					//}
				
				}
				
				
			}
		}
		
		window.display();
	}
		return 0;
}



