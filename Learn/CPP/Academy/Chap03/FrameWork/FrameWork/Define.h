#pragma once

#define ERR_MSG(x, y, str) CDoubleBuffer::GetInst()->WriteBuffer(x, y, str);


template<typename T>
inline void Safe_Delete(T& Temp)
{
	if(Temp)
	{
		delete Temp;
		Temp = NULL;
	}
}