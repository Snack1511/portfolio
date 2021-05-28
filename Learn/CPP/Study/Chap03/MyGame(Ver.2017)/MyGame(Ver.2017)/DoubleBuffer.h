#pragma once
#include"Include.h"
#include"Define.h"
class DoubleBuffer
{
private:
	static DoubleBuffer * m_Inst;
private:
	static int			m_iBufferIndex;//버퍼 인덱스
	static HANDLE		m_HBuffer[2];//HANDLE
	/*핸들은 구체적인 어떤 대상을 구분하기 위해 붙여진 유일한 번호
	  운영체제가 부여하는 중복되지 않는 정수값
	  기존에는 object나 structure등의 포인터를 직접 다뤘으나 포인터 값의 처리, 위험성 때문에
	  객체를 지칭하는 포인터를 쓰지 않고 번호를 쓴 것*/
public :
	static DoubleBuffer*GetInst() 
	{
		if (m_Inst == NULL)
		{
			m_Inst = new DoubleBuffer;
		}
		return m_Inst;
	}
public :
	void CreateBuffer(const int& _width, const int& _height);			//버퍼생성
	void WriteBuffer(int _ix, int _iy, char *_string, int _color = 흰색);	//버퍼쓰기
	void WriteBuffer(int _ix, int _iy, int _index, int _color = 흰색);
	void Flippingbuffer();												//버퍼 전환
	void ClearBuffer();													//버퍼 지우기
	void DestroyBuffer();												//버퍼해제

	bool MyCloseHandle(HANDLE& hFile);									//안전하게 CloseHandle 처리

	void SetCursorHandle();
	void SetTextColor(int _index);
public:
	DoubleBuffer();
	~DoubleBuffer();
};

