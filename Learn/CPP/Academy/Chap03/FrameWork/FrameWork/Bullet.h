#pragma once
#include "Obj.h"
#include "Define.h"

class CBullet : public CObj
{
private:
	BULLET m_Bullet;
	char*  m_BulletSize[BULLETSIZE];
	DWORD  m_dwState;
public:
	virtual void Initialize(int _idata);
	virtual int Porgress(bool _check);
	virtual void Render();
	virtual void Release();
public:
	void PlayerSizeCheck(int _num0, int _num1, int _num2, int _iy, int _icx);
	void Motion();
public:
	BULLET GetBullet()
	{
		return m_Bullet;
	}
public:
	CBullet(void);
	virtual ~CBullet(void);
};

