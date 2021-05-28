

template <typename T>
void SAFE_DELETE(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = NULL;
	}
}

struct OBJDELETE
{
	template <typename T>
	inline void operator () (T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = NULL;
		}
	}
};

#define DECLARE_SINGLETON(type)\
	static type** GetInstance(void)\
	{\
		static type* pInstance = new type;\
		if (pInstance == NULL)\
			pInstance = new type;\
		return& pInstance;\
	}\
	static void DestroyInstance(void)\
	{\
		type** ppInstance = GetInstance();\
		if (*ppInstance != NULL)\
			{\
				delete *ppInstance;\
				ppInstance = NULL;\
			}\
	}

#define PURE = 0

#define GET_SINGLE(type)(*type::GetInstance())
#define DESTROY_SINGLE(type)(*type::GetInstance())->DestroyInstance()

#define ERR_MSG(str) cout << str;


class CKeyMgr;
#define PUSH_KEY(key) GET_SINGLE(CKeyMgr)->GetKey() & key ? true : false
#define UP_KEY(key) GET_SINGLE(CKeyMgr)->GetKey() & key ? false :true