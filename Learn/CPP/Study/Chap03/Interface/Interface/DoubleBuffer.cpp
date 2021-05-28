#include "DoubleBuffer.h"

DoubleBuffer* DoubleBuffer::m_Inst = NULL;
int DoubleBuffer::m_iBufferIndex = 0;
HANDLE	DoubleBuffer::m_HBuffer[2];


DoubleBuffer::DoubleBuffer()
{
}

DoubleBuffer::~DoubleBuffer()
{
}


// 버퍼 생성
void DoubleBuffer::CreateBuffer(const int& _width, const int& _height)
{
	CONSOLE_CURSOR_INFO DeCursor;            // 콘솔창 깜박이는 커서
	COORD size = { _width, _height };     // 버퍼 크기를 저장하는 구조체
	SMALL_RECT rect;                    // 창 크기를 저장하는 구조체

	rect.Top = 0;
	rect.Left = 0;
	rect.Right = _width;
	rect.Bottom = _height;

	// 1번 버퍼 생성

	m_HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[0], size);  // 버퍼 크기 설정
	SetConsoleWindowInfo(m_HBuffer[0], TRUE, &rect); // 창 크기 설정


													 // 2번 버퍼 생성
	m_HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[1], size);  // 버퍼 크기 설정
	SetConsoleWindowInfo(m_HBuffer[1], TRUE, &rect); // 창 크기 설정

	DeCursor.dwSize = 1;
	DeCursor.bVisible = FALSE;

	SetConsoleCursorInfo(m_HBuffer[0], &DeCursor); // 1번 버퍼에 깜박이는 커서 지움
	SetConsoleCursorInfo(m_HBuffer[1], &DeCursor); // 2번 버퍼에 깜박이는 커서 지움
}

// 버퍼 쓰기
void DoubleBuffer::WriteBuffer(int _ix, int _iy, char* _string, int _color)
{
	DWORD dw;                           // 좌표 저장 구조체
	COORD CursorPosition;    // 좌표 설정

	CursorPosition.X = _ix;
	CursorPosition.Y = _iy;

	// 좌표 이동
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);
	SetTextColor(_color);

	// 버퍼에 쓰기
	WriteFile(m_HBuffer[m_iBufferIndex], _string, strlen(_string), &dw, NULL);
}

// 버퍼 전환
void DoubleBuffer::FlippingBuffer()
{
	// 버퍼 활성화. 버퍼의 내용을 한번에 출력
	SetConsoleActiveScreenBuffer(m_HBuffer[m_iBufferIndex]);
	m_iBufferIndex = !m_iBufferIndex; // 다음 버퍼 선택
}

// 버퍼 지우기
void DoubleBuffer::ClearBuffer()
{
	COORD Coor = { 0, 0 };  // 아래 함수를 위한 구조체
	DWORD dw;               // 아래 함수를 위한 구조체
	SetTextColor(흰색);
	// 해당 버퍼의 Coor 좌표부터 ' '값을 채워서 지워진 것처럼 만들기
	FillConsoleOutputCharacter(m_HBuffer[m_iBufferIndex], ' ', WINCX * WINCY, Coor, &dw);
}

// 버퍼 해제
void DoubleBuffer::DestroyBuffer()
{
	MyCloseHandle(m_HBuffer[0]);    // 1번 버퍼 해제
	MyCloseHandle(m_HBuffer[1]);    // 2번 버퍼 해제
									// (HANDLE이 지정한 정수값은 그대로. 해당 정수에 대한 HANDLE 커널만 삭제)

	delete m_Inst;
	m_Inst = NULL;
}

// 안전하게 CloseHandle을 처리하기 위해 MyCloseHandle 만듬
bool DoubleBuffer::MyCloseHandle(HANDLE& hFile)
{
	if (INVALID_HANDLE_VALUE != hFile)
	{
		__try
		{
			return (0 != ::CloseHandle(hFile));
		}
		__finally
		{
			hFile = INVALID_HANDLE_VALUE;
		}
	}
	return false;
}


void DoubleBuffer::SetCursorHandle()
{
	HANDLE HCursor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Info;
	Info.dwSize = 100;
	Info.bVisible = FALSE;
	SetConsoleCursorInfo(HCursor, &Info);
}

void DoubleBuffer::SetTextColor(int _index)
{
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], _index);
}

// 함수 소개.
//atoi(_string) == 문자열을 정수로 바꿔줌
//itoa( (문자열로 바꿀 정수값), (char[])Buffer, (진수)) == 정수를 문자열로 바꿔줌
