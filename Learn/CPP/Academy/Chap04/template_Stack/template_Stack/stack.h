#pragma once
const int MAX_COUNT = 100;

template<typename T1>
class stack
{
private:
	int m_Count;
	T1 m_aData[MAX_COUNT];
public:
	stack()
	{
		Clear();
	}
	//초기화
	void Clear()
	{
		m_Count = 0;
	}
	//스택에 저장된 갯수
	int Count()
	{
		return m_Count;
	}
	//저장된 데이터가 있는가 없는가?
	bool IsEmpty()
	{
		if (m_Count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		return 0 == m_Count ? true : false;
	}

	//데이터를 저장
	T1 Push(float data)
	{
		//저장할 개수가 넘는지 안넘는지
		if (m_Count >= 100)
		{
			return false;
		}

		m_aData[m_Count] = data;
		++m_Count;
		return true;
	}

	//반환후 삭제
	T1 Pop()
	{
		if (m_Count < 1)
		{
			return 0.0;
		}

		--m_Count;
		return m_aData[m_Count];

	}

	//반환만
	T1 Check(int index)
	{
		if (index < 1)
		{
			return 0.0;
		}

		return m_aData[index];
	}

};

