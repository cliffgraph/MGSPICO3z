#pragma once
/**
 * HARZ80 (RaspberryPiPico firmware)
 * Copyright (c) 2024 Harumakkin.
 * SPDX-License-Identifier: MIT
 */
// https://spdx.org/licenses/

#include "global.h"
#include "if_harz80.h"
#include "def_gpio.h"

class CHarz80Ctrl
{
public:
	CHarz80Ctrl();
	virtual ~CHarz80Ctrl();
public:
	void Setup();
	void WritePsram(const uint32_t addr, const uint8_t dt8);
	uint8_t ReadPsram(const uint32_t addr);
	void OutputIo(const harz80::ioaddr_t addr, const uint8_t dt8);
	uint8_t InputIo(const harz80::ioaddr_t addr);
	void WriteMem1(const harz80::memaddr_t addr, const uint8_t dt8);
	uint8_t ReadMem1(const harz80::memaddr_t addr);
	void WriteBlockMem(const harz80::memaddr_t addr, const uint8_t *pDt, const size_t sz);

	const uint8_t *ReadStatus(uint8_t *pRcvBuff, const int RcvLen);
	void ResetCpu();
	void SetBusak(const int n);
	void SetCCmd(const uint8_t ccmd);
	void SetClkMode(const uint8_t dt8);
	void SetCCmdData(const uint8_t dt8);

	// for direct access to sound chip
	void OutOPLL(const uint8_t regNo, const uint8_t dt8);
	void OutPSG(const uint8_t regNo, const uint8_t dt8);
	void OutSCC(const harz80::memaddr_t addr, const uint8_t d8);
};
