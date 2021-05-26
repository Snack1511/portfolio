#include "Bullet.h"


CBullet::CBullet(void)
{
}


CBullet::~CBullet(void)
{
}


void CBullet::Initialize(int _idata)
{
	//m_Bullet.str = "ÀåÇ³ !!";

	m_BulletSize[0] = "";
	m_BulletSize[1] = "";
	m_BulletSize[2] = "";

	PlayerSizeCheck(m_Info.iX + 2, m_Info.iX, m_Info.iX + 2, m_Info.iY, strlen(m_BulletSize[1]));


	m_Bullet.bCheck = true;
	m_Info.iCX = strlen(m_BulletSize[1]);
	m_Info.iCY = BULLETSIZE;
	//m_Info.iAtt = _idata * 20;
}

int CBullet::Porgress(bool _check)
{
	Motion();
	if(m_bCheck == true)
	{
		m_Info.iX -= 2;
	}if(m_bCheck == false)
	{
		m_Info.iX += 2;
	}

	if(m_Info.iX >= (WINCX - 10) || _check == false || m_Info.iX <= (WINCX - 167))
	{
		m_Bullet.bCheck = false;
		return 1;
	}
	return 0;
}

void CBullet::Render()
{
	for (int i = 0 ; i < BULLETSIZE ; i++)
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_ObjSize.iBullet_X[i], m_Info.iY + i, m_BulletSize[i], COLOR_PASTEL_BLUE);
	}	
}

void CBullet::Release()
{

}

void CBullet::Motion()
{
	if(m_bCheck == true)
	{
		m_BulletSize[0] = "¢Ä¡á¢º";
		m_BulletSize[1] = "¢Ä¡á¡á¢º";
		m_BulletSize[2] = "¢Ä¡á¢º";

		PlayerSizeCheck(m_Info.iX, m_Info.iX, m_Info.iX, m_Info.iY, strlen(m_BulletSize[1]));
	}
	
	if(m_bCheck == false)
	{
		m_BulletSize[0] =   "¢¸¡á¢Å";
		m_BulletSize[1] = "¢¸¡á¡á¢Å";
		m_BulletSize[2] =   "¢¸¡á¢Å";

		PlayerSizeCheck(m_Info.iX + 2, m_Info.iX, m_Info.iX + 2, m_Info.iY, strlen(m_BulletSize[1]));
	}
}

void CBullet::PlayerSizeCheck(int _num0, int _num1, int _num2, int _iy, int _icx)
{
	m_Info.iCX = _icx;
	m_ObjSize.iY = _iy;	

	m_ObjSize.iBullet_X[0] = _num0;
	m_ObjSize.iBullet_X[1] = _num1;
	m_ObjSize.iBullet_X[2] = _num2;
}