set(BinName "harzlib")

set(Z80Asm AILZ80ASM.exe)
set(Z80AsmOpt -bin -lm simple -ts 4 -f)

add_custom_command(
	OUTPUT harzbios.bin
	DEPENDS harzbios.z80
	COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND ${Z80Asm} -i harzbios.z80 -o ${CMAKE_CURRENT_BINARY_DIR}/harzbios.bin -lst ${CMAKE_CURRENT_BINARY_DIR}/harzbios.lst ${Z80AsmOpt}
)
add_custom_command(
	OUTPUT harzplay.bin
	DEPENDS harzplay.z80
	COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND ${Z80Asm} -i harzplay.z80 -o ${CMAKE_CURRENT_BINARY_DIR}/harzplay.bin -lst ${CMAKE_CURRENT_BINARY_DIR}/harzplay.lst ${Z80AsmOpt}
)

set(ObjCpy arm-none-eabi-objcopy.exe)
set(ObjCpyOpt -v -I binary -O elf32-littlearm --rename-section .data=.rodata --set-section-flags .rodata=alloc,load,readonly )

add_custom_command(
	OUTPUT harzbios.o
	DEPENDS harzbios.bin
	COMMAND ${ObjCpy} ${ObjCpyOpt} harzbios.bin ${CMAKE_CURRENT_BINARY_DIR}/harzbios.o
)
add_custom_command(
	OUTPUT harzplay.o
	DEPENDS harzplay.bin
	COMMAND ${ObjCpy} ${ObjCpyOpt} harzplay.bin ${CMAKE_CURRENT_BINARY_DIR}/harzplay.o
)

add_library(
	${BinName}
	STATIC
	harzlib.cpp
	harzbios.o
	harzplay.o
)

target_include_directories(
	${BinName}
	PUBLIC
	${PROJECT_SOURCE_DIR}/harzlib
)
