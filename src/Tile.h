#pragma once
class Tile
{
public:
	char getGraphic();
	void clearTile();

	Tile();
	~Tile();

private:
	char graphic;
};

