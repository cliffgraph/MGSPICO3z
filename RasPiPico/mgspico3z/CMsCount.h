
#pragma once
#include <stdint.h>

class CMsCount
{
private:
	uint32_t m_Begin;
	uint32_t m_Timer;
public:
	CMsCount();
	explicit CMsCount(uint32_t t);
	virtual ~CMsCount();
public:
	void Reset(uint32_t t = 0);
	uint32_t GetTime();
	bool IsTimeOut(const bool bReset = false);
	bool IsMidway();
	void Cancel();
	bool IsValid() const;
};

