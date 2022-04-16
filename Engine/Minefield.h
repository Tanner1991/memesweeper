#pragma once
#include "SpriteCodex.h"
#include "Graphics.h"
#include "Vei2.h"
class Minefield
{
private:
	class Tile
	{
	private: 
		enum class State {hidden, flagged, revealed};
		bool hasMine = false; 
		State state =  State::hidden; 

	public:
		void SpawnMine(int numberOfMines); 
		bool HasMine(); 
	};

public: 
	void Draw(Graphics& gfx, Vei2& loc); 
	void OnRevealClick();
	Tile& AtTile(Vei2& loc);
	

private: 
	static constexpr int nMines = 10;
	static constexpr int width = 20;
	static constexpr int height = 16;
public:
	Tile fd[width * height];



};

