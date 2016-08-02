#ifndef _ENGINE_SINGLETON_H
#define _ENGINE_SINGLETON_H

template<class T>
class Singleton
{
protected:
	static T* m_Instance;
public:
	virtual Singleton() { }

	inline static T* Get()
	{
		if (!m_Instance)
		{
			m_Instance = new T;
		}
		return m_Instance;
	}

	inline static void Delete()
	{
		if (m_Instance)
		{
			delete m_Instance;
			m_Instance = nullptr;
		}
	}
};

// Declare our static variable..
template<class T>
T* Singleton<T>::m_Instance = 0;

#endif