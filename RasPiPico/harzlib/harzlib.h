#pragma once
/**
 * Copyright (c) 2024 Harumakkin.
 * SPDX-License-Identifier: MIT
 */
// https://spdx.org/licenses/

#include "stdint.h"


extern const uint8_t _binary_harzbios_bin_start[];
extern const uint8_t _binary_harzbios_bin_end[];
extern const uint8_t _binary_harzplay_bin_start[];
extern const uint8_t _binary_harzplay_bin_end[];


// 参考：普通のやつらの下を行け: objcopy で実行ファイルにデータを埋め込
// http://0xcc.net/blog/archives/000076.html