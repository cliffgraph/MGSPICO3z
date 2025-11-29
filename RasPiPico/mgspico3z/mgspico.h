#pragma once
#include <stdint.h>

enum class RPxxxxCLOCK : uint8_t {CLK125MHZ, CLK240MHZ};
enum class MUSICTYPE : uint8_t	{MGS=0, KIN5=1, NDP=2, VGM=3, TGF=4, MAX_NUM=5};
enum class SCCMODULE : uint8_t {IKASCC=0, HRASCC=1};
enum class HARZ80CLOCK : uint8_t {HARZ3M58HZ=0, HARZ7M16HZ=1};

