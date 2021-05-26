#include "ObjMgr.h"
#include "Obj.h"
#include "Cursor.h"
#include "CObjFactory.h"


CObjMgr::CObjMgr(void)
{
}


CObjMgr::~CObjMgr(void)
{
	
}

void CObjMgr::InitTile()
{
	for(int y = 0 ; y < TileCntY ; y++)
	{
		for(int x = 0 ; x < TileCntY ; x++)
		{
			TILE* Tile = new TILE;

			Tile->iX = x * TileSizeX;
			Tile->iY = y * TileSizeY;
			Tile->iCX = TileSizeX;
			Tile->iCY = TileSizeY;
			Tile->str[0] = "¦£¦¡¦¤";
			Tile->str[1] = "¦¢  ¦¢";
			Tile->str[2] = "¦¦¦¡¦¥";
			Tile->iIndex = (y * TileCntX + x);
			Tile->iCost = ( TileCntY * TileCntX ) - (y * TileCntX + x);
			Tile->iOption = 0;

			m_TileList.push_back(Tile);
		}
	}
}

void CObjMgr::InitCursor()
{
	m_pCursor = CObjFactory<CCursor>::CreateObj();
}
