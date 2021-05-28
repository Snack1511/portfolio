#pragma once
#include"Include.h"

class Vector
{
private:
	int *pNum;
	int iCount;
public:
	Vector() 
	{
		Clear();
	}
	~Vector();
	void Clear() 
	{
		pNum = nullptr;
		iCount = 0;
	}
	void Push(int num) 
	{
		if (pNum == nullptr)
		{
			pNum = new int;
			pNum[0] = num;
			iCount++;
			cout << "Push : " << num << endl;
			return;
		}
		int *pTmp = pNum;

		iCount++;
		pNum = new int[iCount];
		for (int i = 0; i < iCount - 1; i++) 
		{
			pNum[i] = pTmp[i];
		}
		pNum[iCount - 1] = num;

		delete pTmp;
		pTmp = nullptr;
		cout << "Push : "<< num << endl;
	}

	void Pop() 
	{
		if (iCount == 0) 
		{
			return;
		}
		int *pTmp = pNum;
		iCount--;
		pNum = new int[iCount];
		for (int i = 0; i < iCount; i++) 
		{
			pNum[i] = pTmp[i];
		}
		int tmpVal = pTmp[iCount];

		delete pTmp;
		pTmp = nullptr;

		cout << "Pop : "<< tmpVal << endl;
	}
	void Insert(int idx, int num) 
	{
		int _idx = idx;
		if (idx == iCount) 
		{
			Push(num);
		}
		if (iCount < idx) 
		{
			return;
		}

		int *pTmp = pNum;

		iCount++;
		pNum = new int[iCount];

		for (int i = 0; i < idx; i++) 
		{
			pNum[i] = pTmp[i];
		}

		pNum[idx] = num;

		for (idx; idx < iCount - 1; idx++)
		{
			pNum[idx+1] = pTmp[idx];
		}

		delete pTmp;
		pTmp = nullptr;
		
		cout << "Insert : " << _idx  << "  "<< num << endl;
		//iCount--;
	}
	
	void Remove(int idx) 
	{
		if (iCount == 0 || iCount < idx) 
		{
			return;
		}
		int *pTmp = pNum;
		
		iCount--;
		pNum = new int[iCount];

		for (int i = 0; i < idx; i++)
		{
			pNum[i] = pTmp[i];
		}

		int delVal = pTmp[idx];

		for (idx; idx < iCount - 1; idx++)
		{
			pNum[idx] = pTmp[idx + 1];
		}

		delete pTmp;
		pTmp = nullptr;

		cout << "Remove : " << delVal << endl;

	}

	void PrintAll() 
	{
			for (int i = 0; i < iCount; i++) 
			{
				cout << pNum[i] << endl;
			}
	}


};

