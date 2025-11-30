/**
 * HARZ80 (RaspberryPiPico firmware)
 * Copyright (c) 2024 Harumakkin.
 * SPDX-License-Identifier: MIT
 */
// https://spdx.org/licenses/

#include "for_debug.h"
#include <stdint.h>
#include <stdio.h>				// printf
#include <memory.h>
#include <pico/stdlib.h>
#include <hardware/clocks.h>	 // set_sys_clock_khz()
#include "CHarz80Ctrl.h"

inline uint16_t SwapHL16(const uint16_t v)
{
	return ((v>>8)&0xff)|((v&0xff)<<8);
}

CHarz80Ctrl::CHarz80Ctrl()
{
	// do nothing
	return;
}

CHarz80Ctrl::~CHarz80Ctrl()
{
	// do nothing
	return;
}

void CHarz80Ctrl::Setup()
{
#ifdef FOR_DEBUG
	uint spd = spi_init( HARZ80_SPI_DEV, (uint)6600000 ); 	
	printf("SPI speed=%d\n", spd);
#else
	spi_init( HARZ80_SPI_DEV, (uint)6600000 );
#endif
	gpio_set_function( HARZ80_SPI_PIN_TX, GPIO_FUNC_SPI );
    gpio_set_function( HARZ80_SPI_PIN_RX, GPIO_FUNC_SPI );
    gpio_set_function( HARZ80_SPI_PIN_SCK, GPIO_FUNC_SPI );
	gpio_disable_pulls(HARZ80_SPI_PIN_TX);
    gpio_disable_pulls(HARZ80_SPI_PIN_RX);
    gpio_disable_pulls(HARZ80_SPI_PIN_SCK);

	/* CS# */
    gpio_init( HARZ80_SPI_PIN_CS_n );
    gpio_set_dir( HARZ80_SPI_PIN_CS_n, GPIO_OUT);
	//
    gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	busy_wait_ms(10);
	return;
}

void CHarz80Ctrl::WritePsram(const uint32_t addr, const uint8_t dt8)
{
	static const int LEN=5;
	uint8_t sx[LEN];
	sx[0] = harz80::TXCMD_PSRAM_WR_8;
	sx[1] = (addr >> 16) & 0xff;
	sx[2] = (addr >> 8 ) & 0xff;
	sx[3] = (addr >> 0 ) & 0xff;
	sx[4] = dt8;

	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, sx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return;
}

uint8_t CHarz80Ctrl::ReadPsram(const uint32_t addr)
{
	static const int LEN=4+1;
	uint8_t srx[LEN];

	srx[0] = harz80::TXCMD_PSRAM_RD_8;
	srx[1] = (addr >> 16) & 0xff;
	srx[2] = (addr >> 8 ) & 0xff;
	srx[3] = (addr >> 0 ) & 0xff;
	srx[4] = 0x00;

	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_read_blocking (HARZ80_SPI_DEV, srx, srx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return srx[4];
}

void CHarz80Ctrl::OutputIo(const harz80::ioaddr_t addr, const uint8_t dt8)
{
	static const int LEN=3;
	uint8_t sx[LEN];
	sx[0] = harz80::TXCMD_Z80IO_WR;
	sx[1] = (addr >> 0) & 0xff;
	sx[2] = dt8;

	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, sx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return;
}

uint8_t CHarz80Ctrl::InputIo(const harz80::ioaddr_t addr)
{
	static const int LEN=3;
	uint8_t srx[LEN];

	srx[0] = harz80::TXCMD_Z80IO_RD;
	srx[1] = (addr >> 0) & 0xff;
	srx[2] = 0x00;

	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_read_blocking (HARZ80_SPI_DEV, srx, srx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return srx[2];
}

void CHarz80Ctrl::WriteMem1(const harz80::memaddr_t addr, const uint8_t dt8)
{
	static const int LEN=4;
	uint8_t sx[LEN];
	sx[0] = harz80::TXCMD_Z80MEM_WR_1;
	sx[1] = (addr >> 8) & 0xff;
	sx[2] = (addr >> 0) & 0xff;
	sx[3] = dt8;

	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, sx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */

	return;
}

uint8_t CHarz80Ctrl::ReadMem1(const harz80::memaddr_t addr)
{
	static const int LEN=3+1;
	uint8_t srx[LEN];

	srx[0] = harz80::TXCMD_Z80MEM_RD_1;
	srx[1] = (addr >> 8) & 0xff;
	srx[2] = (addr >> 0) & 0xff;
	srx[3] = 0x00;

	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_read_blocking (HARZ80_SPI_DEV, srx, srx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return srx[3];
}

void CHarz80Ctrl::WriteBlockMem(const harz80::memaddr_t addr, const uint8_t *pDt, const size_t sz)
{
	for( size_t t = 0; t < sz; ++t) {
		const uint32_t a = (uint32_t)(addr) + (uint32_t)t;
		WriteMem1(a, pDt[t]);
	}
	return;
}

const uint8_t *CHarz80Ctrl::ReadStatus(uint8_t *pRcvBuff, const int num)
{
	static const int LEN=1;
	uint8_t srx[LEN];
	
	srx[0] = harz80::TXCMD_HARZ_GETSTS;
	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, srx, LEN);
	spi_read_blocking (HARZ80_SPI_DEV, 0x00, pRcvBuff, num);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return pRcvBuff;
}

void CHarz80Ctrl::ResetCpu()
{
	static const int LEN=1;
	uint8_t srx[LEN];
	srx[0] = harz80::TXCMD_HARZ_RESET;
	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, srx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	//
	busy_wait_us(2);	// 3.58MHzの6-cyc(1.6[us]) 以上Waitすること
	return;
}

void CHarz80Ctrl::SetBusak(const int n)
{
	static const int LEN=1;
	uint8_t srx[LEN];
	srx[0] = (n==0) ? harz80::TXCMD_HARZ_STOP : harz80::TXCMD_HARZ_RUN;
	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, srx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return;
}

void CHarz80Ctrl::SetCCmd(const uint8_t ccmd)
{
	static const int LEN=2;
	uint8_t srx[LEN] = {harz80::TXCMD_HARZ_SETCMD, ccmd};
	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, srx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return;
}

void CHarz80Ctrl::SetCCmdData(const uint8_t dt8)
{
	static const int LEN=2;
	uint8_t srx[LEN] = {harz80::TXCMD_HARZ_SETCMDDATA, dt8};
	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, srx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return;
}

/* dt8: 0=3.58Mhz、0!=7.16MHz
*/
void CHarz80Ctrl::SetClkMode(const uint8_t dt8)
{
	static const int LEN=2;
	uint8_t sx[LEN];
	sx[0] = harz80::TXCMD_HARZ_CLKMODE;
	sx[1] = dt8;

	gpio_put( HARZ80_SPI_PIN_CS_n, 0 );	/* Set CS# low */
	spi_write_blocking (HARZ80_SPI_DEV, sx, LEN);
	gpio_put( HARZ80_SPI_PIN_CS_n, 1 );	/* Set CS# high */
	return;
}

void CHarz80Ctrl::OutOPLL(const uint8_t regNo, const uint8_t dt8)
{
	OutputIo(0x7C, regNo);
	busy_wait_us(4);
	OutputIo(0x7D, dt8);
	busy_wait_us(24);
	return;
}

void CHarz80Ctrl::OutPSG(const uint8_t regNo, const uint8_t dt8)
{
	OutputIo(0xA0, regNo);
	busy_wait_us(1);
	OutputIo(0xA1, dt8);
	busy_wait_us(1);
	return;
}

void CHarz80Ctrl::OutSCC(const harz80::memaddr_t addr, const uint8_t dt8)
{
	WriteMem1(addr, dt8);
	busy_wait_us(1);
	return;
}
