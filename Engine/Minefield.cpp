#include "Minefield.h"
#include <random>

void Minefield::Draw(Graphics& gfx)const
{
	
	for (int x = 0; x < width; x++) {

		for (int y = 0; y < height; y++) {
			
			Vei2 temp = Vei2{ x, y };

			TileAt(temp).Draw2(temp*SpriteCodex::tileSize, gfx); 

		}
	}

	
	
}

Minefield::Tile& Minefield::TileAt( const Vei2& gridPos)
{
	return fd[gridPos.y * width + gridPos.x]; 
}

const Minefield::Tile& Minefield::TileAt(const Vei2& gridPos) const
{
	return fd[gridPos.y * width + gridPos.x];
}





void Minefield::SpawnMine()
{
	
	std::random_device rd; 
	std::mt19937 rng(rd()); 
	std::uniform_int_distribution <int> xDist(0, width - 1); 
	std::uniform_int_distribution <> yDist(0, height - 1);

	for (int i = 0; nMines - i > 0; i++) {
		Vei2 spawn; 
		do {
			spawn = { xDist(rng), yDist(rng) };
			
		} while (TileAt(spawn).HasMine()); 

		TileAt(spawn).Spawn();
	}

}

void Minefield::Tile::Spawn()
{
	hasMine = true; 
}

bool Minefield::Tile::HasMine()
{
	return hasMine;
}

void Minefield::Tile::Draw2(const Vei2 &vec, Graphics gfx)const
{
	switch (state) {
	case State::hidden: 
		SpriteCodex::DrawTileButton(vec, gfx);
		break; 
	case State::flagged: 
		SpriteCodex::DrawTileButton(vec, gfx);
		SpriteCodex::DrawTileFlag(vec, gfx); 
		break;
	case State::revealed: 
		
		if (!hasMine) {
			SpriteCodex::DrawTile0(vec, gfx);
		} 

		else {
			SpriteCodex::DrawTileBomb(vec, gfx);
		}
		break; 


	}
				


	
}

