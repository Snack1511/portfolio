#pragma once
#include "Include.h"

class CDoubleBuffer
{
private:
	static CDoubleBuffer* m_Inst;

private:
	static int		m_iBufferIndex;		// 버퍼 Index
	static HANDLE	m_HBuffer[2];		// HANDLE

	// 핸들은 구체적인 어떤 대상을 구분하기 위해 붙여진 유일한 번호. 
	// 운영 체제가 부여하는 중복되지 않는 정수값.
	// 기존에는 object나 structure 등의 포인터를 직접 다뤘으나 포인터 값의 처리
	// 위험성 때문에 객체를 지칭하는데 포인터를 쓰지 않고 번호를 쓴 것이다.
public:
	static CDoubleBuffer* GetInst()
	{
		if(m_Inst != NULL)
			m_Inst = new CDoubleBuffer;

		return m_Inst;
	}

public:
	void CreateBuffer(const int& _width = 120, const int& _height = 80); // 버퍼 생성
	void WriteBuffer(int x, int y, char *string);           // 버퍼 쓰기
	void WriteBuffer(int _ix, int _iy, int _index);
	void BackGroundBuffer(int _ix, int _iy, char* string);	// BackGround 버퍼사용.
	void FlippingBuffer();                                  // 버퍼 전환
	void ClearBuffer();                                     // 버퍼 지우기
	void DestroyBuffer();                                   // 버퍼 해제
	void SetCursorHandle();
	bool MyCloseHandle(HANDLE& hFile);         // 안전하게 CloseHandle 처리
public:
	CDoubleBuffer();
	~CDoubleBuffer();

};


