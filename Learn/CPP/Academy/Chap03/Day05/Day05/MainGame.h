#pragma once
#include "Obj.h" 
class CObj;
class CMainGame
{
protected:
	//int m_iNum;
private:
	CObj * m_pPlayer;
public : 
	/*virtual void NewFunction();
	void secondFunction();
	virtual void purevirtual() = 0;*/

	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	CMainGame();
	virtual ~CMainGame();
};

