#include "DoubleBuffer.h"



CDoubleBuffer* CDoubleBuffer::m_Inst = NULL;
int CDoubleBuffer::m_iBufferIndex = 0;
HANDLE CDoubleBuffer::m_HBuffer[2];


CDoubleBuffer::CDoubleBuffer(void)
{
}


CDoubleBuffer::~CDoubleBuffer(void)
{
	
}

// 버퍼 생성
void CDoubleBuffer::CreateBuffer(const int& _width, const int& _height)
{
	CONSOLE_CURSOR_INFO DeCursor;            // 콘솔창 깜박이는 커서
	COORD size = { _width, _height };     // 버퍼 크기를 저장하는 구조체
	SMALL_RECT rect;                    // 창 크기를 저장하는 구조체

	rect.Top = 0;
	rect.Left = 0;
	rect.Right = _width;
	rect.Bottom = _height;

	// 1번 버퍼 생성

	m_HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[0], size);  // 버퍼 크기 설정
	SetConsoleWindowInfo(m_HBuffer[0], TRUE, &rect); // 창 크기 설정


	// 2번 버퍼 생성
	m_HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_HBuffer[1], size);  // 버퍼 크기 설정
	SetConsoleWindowInfo(m_HBuffer[1], TRUE, &rect); // 창 크기 설정

	DeCursor.dwSize = 1;
	DeCursor.bVisible = FALSE;

	SetConsoleCursorInfo(m_HBuffer[0], &DeCursor); // 1번 버퍼에 깜박이는 커서 지움
	SetConsoleCursorInfo(m_HBuffer[1], &DeCursor); // 2번 버퍼에 깜박이는 커서 지움
}

// 버퍼 쓰기
void CDoubleBuffer::WriteBuffer(int _ix, int _iy, char* string, int _setcolor)
{
	DWORD dw;                           // 좌표 저장 구조체
	COORD CursorPosition;    // 좌표 설정

	CursorPosition.X = _ix;
	CursorPosition.Y = _iy;

	// 좌표 이동
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);
	// 색깔 변경
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], _setcolor);
	// 버퍼에 쓰기
	WriteFile(m_HBuffer[m_iBufferIndex], string, strlen(string), &dw, NULL);
	// 색 초기화
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], COLOR_REALWHITE);
}

void CDoubleBuffer::WriteBuffer(int _ix, int _iy, int string, int _setcolor)
{
	DWORD dw;                           // 좌표 저장 구조체
	COORD CursorPosition;    // 좌표 설정
	char str[512] = {'\0'};

	_itoa_s(string,str,8,10);

	CursorPosition.X = _ix;
	CursorPosition.Y = _iy;

	// 좌표 이동
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);

	// 색깔 변경
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], _setcolor);

	// 버퍼에 쓰기
	WriteFile(m_HBuffer[m_iBufferIndex], str, strlen(str), &dw, NULL);

	// 색 초기화
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], COLOR_REALWHITE);
}

void CDoubleBuffer::WriteBuffer(int _ix, int _iy, char* cstring, int string, char* _cstring, int _setcolor)
{
	DWORD dw;                           // 좌표 저장 구조체
	COORD CursorPosition;    // 좌표 설정
	char str[512] = {'\0'};

	_itoa_s(string,str,8,10);

	CursorPosition.X = _ix;
	CursorPosition.Y = _iy;

	// 좌표 이동
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);
	// 색깔 변경
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], _setcolor);
	// 버퍼에 쓰기
	WriteFile(m_HBuffer[m_iBufferIndex], cstring, strlen(cstring), &dw, NULL);
	WriteFile(m_HBuffer[m_iBufferIndex], str, strlen(str), &dw, NULL);
	WriteFile(m_HBuffer[m_iBufferIndex], _cstring, strlen(_cstring), &dw, NULL);
	// 색 초기화
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], COLOR_REALWHITE);
}


void CDoubleBuffer::WriteBuffer(int _ix, int _iy, char* cstring, int istring, char* _cstring, int _istring, char* _cpstring, int _setcolor)
{
	DWORD dw;                           // 좌표 저장 구조체
	COORD CursorPosition;    // 좌표 설정
	char str[512] = {'\0'};
	char _str[512] = {'\0'};
	_itoa_s(istring,str,8,10);
	_itoa_s(_istring,_str,8,10);

	CursorPosition.X = _ix;
	CursorPosition.Y = _iy;

	// 좌표 이동
	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);
	// 색깔 변경
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], _setcolor);
	// 버퍼에 쓰기
	WriteFile(m_HBuffer[m_iBufferIndex], cstring, strlen(cstring), &dw, NULL);
	WriteFile(m_HBuffer[m_iBufferIndex], str, strlen(str), &dw, NULL);
	WriteFile(m_HBuffer[m_iBufferIndex], _cstring, strlen(_cstring), &dw, NULL);
	WriteFile(m_HBuffer[m_iBufferIndex], _str, strlen(_str), &dw, NULL);
	WriteFile(m_HBuffer[m_iBufferIndex], _cpstring, strlen(_cpstring), &dw, NULL);
	// 색 초기화
	SetConsoleTextAttribute(m_HBuffer[m_iBufferIndex], COLOR_REALWHITE);
}

//void CDoubleBuffer::BackGroundBuffer(int _ix, int _iy, char* string)
//{
//	DWORD dw;                           // 좌표 저장 구조체
//	COORD CursorPosition;    // 좌표 설정
//
//	CursorPosition.X = _ix;
//	CursorPosition.Y = _iy;
//
//	// 좌표 이동
//	SetConsoleCursorPosition(m_HBuffer[m_iBufferIndex], CursorPosition);
//
//	// 버퍼에 쓰기
//	WriteFile(m_HBuffer[m_iBufferIndex], string, strlen(string), &dw, NULL);
//}


// 버퍼 전환
void CDoubleBuffer::FlippingBuffer()
{
	//Sleep(30);		// 시간 함수를 대체할 버퍼 전환 속도

	// 버퍼 활성화. 버퍼의 내용을 한번에 출력
	SetConsoleActiveScreenBuffer(m_HBuffer[m_iBufferIndex]);
	m_iBufferIndex = !m_iBufferIndex; // 다음 버퍼 선택
}

// 버퍼 지우기
void CDoubleBuffer::ClearBuffer()
{
	COORD Coor = { 0, 0 };  // 아래 함수를 위한 구조체
	DWORD dw;               // 아래 함수를 위한 구조체

	// 해당 버퍼의 Coor 좌표부터 ' '값을 채워서 지워진 것처럼 만들기
	FillConsoleOutputCharacter(m_HBuffer[m_iBufferIndex], ' ', WINCX * WINCY, Coor, &dw);
}

// 버퍼 해제
void CDoubleBuffer::DestroyBuffer()
{
	MyCloseHandle(m_HBuffer[0]);    // 1번 버퍼 해제
	MyCloseHandle(m_HBuffer[1]);    // 2번 버퍼 해제
	// (HANDLE이 지정한 정수값은 그대로. 해당 정수에 대한 HANDLE 커널만 삭제)

	::Safe_Delete(m_Inst);
}
// 안전하게 CloseHandle을 처리하기 위해 MyCloseHandle 만듬
bool CDoubleBuffer::MyCloseHandle(HANDLE& hFile)
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

