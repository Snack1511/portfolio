#pragma once
#include "Include.h"
class CDoubleBuffer
{
private:
	static CDoubleBuffer* m_Inst;

private:
	static int m_iBufferIndex; // 버퍼 Index
	static HANDLE m_HBuffer[2]; // 버퍼 Handle

public:
	static CDoubleBuffer* GetInst()
	{
		if (m_Inst != nullptr)
		{
			m_Inst = new CDoubleBuffer;
		}

		return m_Inst;
	}

public:
	void CreateBuffer(const int& _width = 120, const int& _heigh = 80); // 버퍼 생성
	void WriteBuffer(int x, int y, char *string);
	void WriteBuffer(int _ix, int _iy, int _index);
	void FlippingBuffer(); // 버퍼 전환
	void ClearBuffer();    // 버퍼 지우기
	void DestroyBuffer();  // 버퍼 해제
	void SetCursorHandle(); // 커서 컨트롤
	bool SafeCloseHandle(HANDLE& hFile); // 안전하게 Handle 처리
public:
	CDoubleBuffer();
	~CDoubleBuffer();
};
