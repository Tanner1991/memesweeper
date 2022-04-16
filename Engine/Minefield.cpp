#include "Minefield.h"
#include <random>

void Minefield::Draw(Graphics& gfx, Vei2& loc)
{

}


Minefield::Tile& Minefield::AtTile( Vei2& loc)
{
	return fd[loc.y * width + loc.x]; 
}

void Minefield::Tile::SpawnMine(int numberOfMines)
{
	
	std::random_device rd; 
	std::mt19937 rng(rd()); 
	std::uniform_real_distribution <int> xDist(0, width - 1); 
	std::uniform_real_distribution <int> yDist(0, height - 1);

	for (int i = 0; numberOfMines - i > 0; i++) {
		Vei2 temp; 
		do {
			temp = { xDist(rng), yDist(rng) };
			
		}
		while(AtTile(temp). )

	}

}

bool Minefield::Tile::HasMine()
{
	return hasMine;
}
