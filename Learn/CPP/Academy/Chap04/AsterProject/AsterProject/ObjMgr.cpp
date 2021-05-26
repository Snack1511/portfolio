#include "ObjMgr.h"



void CObjMgr::InitTile()
{
	for (int y = 0; y < TileCntY; y++) 
	{
		for (int x = 0; x < TileCntX; x++) 
		{
			TILE* Tile = new TILE;

			Tile->iX = x*TileSizeX;
			Tile->iY = y*TileSizeY;
			Tile->iCX = TileSizeX;
			Tile->iCY = TileSizeY;
			Tile->str[0] = "¤±";
			Tile->str[1] = "Ä«";
			Tile->str[2] = "µå";
			Tile->iIndex = (y*TileCntX + x);
			Tile->iCost = (TileCntX * TileCntX) - (y*TileCntX + x);
			Tile->iOption = 0;

			mTileList.push_back(Tile);

		}
	}
}

void CObjMgr::InitCursor()
{
	
}

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
}
