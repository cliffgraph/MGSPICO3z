set(BinName "mgspico3z")

add_compile_definitions(MGSPICO_3RD_Z)

add_executable(
	${BinName}
	global.cpp
	t_mmmspi.cpp
	t_si5351.cpp
	timerobj.cpp
	harz80/CHarz80Ctrl.cpp
	mgs/mgs_tools.cpp
	ff/ff.c
	ff/ffsystem.c
	ff/ffunicode.c
	ff/mmc_pico_spi.c
	tgf/CTgfPlayer.cpp
	vgm/CVgmPlayer.cpp
	oled/oledssd1306.cpp
	sdfat.cpp
	CMsCount.cpp
	MgspicoSettings.cpp
	mgspico3z.cpp
	MusFiles.cpp
	CReadFileStream.cpp
)

include_directories(
	./
	ff
	mgs
	harz80
	harzlib
	tgf
	vgm
)

target_compile_options(
	${BinName}
	PUBLIC -O2 -Wall
)

# pico_generate_pio_header(
# 	${BinName}
# 	${CMAKE_CURRENT_LIST_DIR}/mgspico.pio
# )

## enable usb output, disable uart output
pico_enable_stdio_usb(${BinName} 0)
pico_enable_stdio_uart(${BinName} 1)

target_include_directories(
		${BinName}
		PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})
		
target_link_libraries(
	${BinName}
	PRIVATE
	pico_stdlib
	pico_rand
	hardware_i2c
	hardware_spi
	harzlib
	tinyusb_host
	tinyusb_board
	pico_multicore
#	hardware_pio hardware_flash
#	host_cdc_msc_hid tinyusb_device
)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(${BinName})

# add url via pico_set_program_url
#example_auto_set_url(${BinName})

