#pragma once
#include "SceneObj.h"

class CObj;
class CStage : public CSceneObj
{
private:
	CObj* m_pPlayer;
	CObj* m_pMonster[MONSTERMAX];
	bool  bCheck[MONSTERMAX];
	CObj* m_pBackGround;
	DWORD m_dwKey;
	DWORD m_dwCount;
	int   m_ZenCount;
	int	  m_MonsterPosX;
	int   m_MonsterPosY;
	int   m_iMonsterDieCount;
	int   m_iQuestCount;
	char* m_cBasicAttack[8];
	char* m_cSkillAttack[3];
	char* m_cHpBar100[2];
	char* m_cHpBar80[2];
	char* m_cHpBar60[2];
	char* m_cHpBar40[2];
	char* m_cHpBar20[2];
	char* m_cHpBar0[2];
	char* m_cMpBar100[2];
	char* m_cMpBar80[2];
	char* m_cMpBar60[2];
	char* m_cMpBar40[2];
	char* m_cMpBar20[2];
	char* m_cMpBar0[2];
public:
	virtual void Initialize();
	virtual void Porgress();
	virtual void Render();
	virtual void Release();
public:
	void CheckMonster();
	void KeyCheck();
public:
	CStage(void);
	virtual ~CStage(void);
};

