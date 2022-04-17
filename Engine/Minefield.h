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
		

	public:
		void Spawn(); 
		bool HasMine(); 
		State HasState(); 
		void Draw2(const Vei2& vec, Graphics gfx) const;
		State state = State::hidden;
	};

public: 
	void Draw(Graphics& gfx) const; 
	void OnRevealClick();
	Tile& TileAt( const Vei2& gridPos);
	const Tile& TileAt(const Vei2& gridPos) const;
	void SpawnMine(); 
	Graphics gfx; 
	

private: 
	static constexpr int nMines = 10;
	static constexpr int width = 20;
	static constexpr int height = 16;
	Tile fd[width * height];



};

