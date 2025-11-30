@echo off

:DISK1
set DISKNAME=disks/THE_TOWER_OF_CABIN_1.dsk
set DESTDIR=MUDRV/CABIN_1
python extract_cabin_bgm.py %DISKNAME% 0x00019000 "00019600" %DESTDIR%/NO1_001.mud
python extract_cabin_bgm.py %DISKNAME% 0x00019800 "00019600" %DESTDIR%/NO1_003.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001AC00 "00019600" %DESTDIR%/NO1_005.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001B200 "00019600" %DESTDIR%/NO1_007.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001B600 "00019600" %DESTDIR%/NO1_009.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001BE00 "00019600" %DESTDIR%/NO1_011.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001CA00 "00019600" %DESTDIR%/NO1_013.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001DE00 "0001EE00" %DESTDIR%/NO1_015.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001F000 "00020200" %DESTDIR%/NO1_017.mud
python extract_cabin_bgm.py %DISKNAME% 0x00020400 "00020200" %DESTDIR%/NO1_019.mud
python extract_cabin_bgm.py %DISKNAME% 0x00021000 "00019600" %DESTDIR%/NO1_021.mud
python extract_cabin_bgm.py %DISKNAME% 0x00021C00 "0001EE00" %DESTDIR%/NO1_023.mud
python extract_cabin_bgm.py %DISKNAME% 0x00022000 "0001EE00" %DESTDIR%/NO1_025.mud
python extract_cabin_bgm.py %DISKNAME% 0x00023200 "00019600" %DESTDIR%/NO1_027.mud
python extract_cabin_bgm.py %DISKNAME% 0x00024000 "00019600" %DESTDIR%/NO1_029.mud
python extract_cabin_bgm.py %DISKNAME% 0x00025400 "00019600" %DESTDIR%/NO1_031.mud
python extract_cabin_bgm.py %DISKNAME% 0x00026200 "00019600" %DESTDIR%/NO1_033.mud
python extract_cabin_bgm.py %DISKNAME% 0x00027200 "00019600" %DESTDIR%/NO1_035.mud
python extract_cabin_bgm.py %DISKNAME% 0x00028000 "00019600" %DESTDIR%/NO1_037.mud
python extract_cabin_bgm.py %DISKNAME% 0x00028600 "00019600" %DESTDIR%/NO1_039.mud
python extract_cabin_bgm.py %DISKNAME% 0x00029200 "00019600" %DESTDIR%/NO1_041.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002A400 "00019600" %DESTDIR%/NO1_043.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002AC00 "00019600" %DESTDIR%/NO1_045.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002C000 "00020200" %DESTDIR%/NO1_047.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002C800 "00020200" %DESTDIR%/NO1_049.mud
rem python extract_cabin_bgm.py %DISKNAME% 0x0001DE00 "0001EE00" %DESTDIR%/NO1_051.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002D600 "00020200" %DESTDIR%/NO1_054.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002E400 "00020200" %DESTDIR%/NO1_056.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002F200 "00019600" %DESTDIR%/NO1_058.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002FE00 "00019600" %DESTDIR%/NO1_060.mud
python extract_cabin_bgm.py %DISKNAME% 0x00030600 "00019600" %DESTDIR%/NO1_062.mud
python extract_cabin_bgm.py %DISKNAME% 0x00031200 "00019600" %DESTDIR%/NO1_064.mud

python extract_cabin_bgm.py %DISKNAME% 0x00019400 "00019600" %DESTDIR%/NO1_002.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001A200 "00019600" %DESTDIR%/NO1_004.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001B000 "00019600" %DESTDIR%/NO1_006.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001B400 "00019600" %DESTDIR%/NO1_008.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001BC00 "00019600" %DESTDIR%/NO1_010.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001C400 "00019600" %DESTDIR%/NO1_012.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001D400 "00019600" %DESTDIR%/NO1_014.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001E800 "0001EE00" %DESTDIR%/NO1_016.mud
python extract_cabin_bgm.py %DISKNAME% 0x0001FC00 "00020200" %DESTDIR%/NO1_018.mud
python extract_cabin_bgm.py %DISKNAME% 0x00020C00 "00020200" %DESTDIR%/NO1_020.mud
python extract_cabin_bgm.py %DISKNAME% 0x00021600 "00019600" %DESTDIR%/NO1_022.mud
python extract_cabin_bgm.py %DISKNAME% 0x00021E00 "0001EE00" %DESTDIR%/NO1_024.mud
python extract_cabin_bgm.py %DISKNAME% 0x00022C00 "0001EE00" %DESTDIR%/NO1_026.mud
python extract_cabin_bgm.py %DISKNAME% 0x00023A00 "00019600" %DESTDIR%/NO1_028.mud
python extract_cabin_bgm.py %DISKNAME% 0x00024A00 "00019600" %DESTDIR%/NO1_030.mud
python extract_cabin_bgm.py %DISKNAME% 0x00025E00 "00019600" %DESTDIR%/NO1_032.mud
python extract_cabin_bgm.py %DISKNAME% 0x00026C00 "00019600" %DESTDIR%/NO1_034.mud
python extract_cabin_bgm.py %DISKNAME% 0x00027C00 "00019600" %DESTDIR%/NO1_036.mud
python extract_cabin_bgm.py %DISKNAME% 0x00028400 "00019600" %DESTDIR%/NO1_038.mud
python extract_cabin_bgm.py %DISKNAME% 0x00028E00 "00019600" %DESTDIR%/NO1_040.mud
python extract_cabin_bgm.py %DISKNAME% 0x00029E00 "00019600" %DESTDIR%/NO1_042.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002A800 "00019600" %DESTDIR%/NO1_044.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002B600 "00019600" %DESTDIR%/NO1_046.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002C600 "00020200" %DESTDIR%/NO1_048.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002D200 "00020200" %DESTDIR%/NO1_050.mud
rem python extract_cabin_bgm.py %DISKNAME% 0x0001E800 "0001EE00" %DESTDIR%/NO1_052.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002E000 "00020200" %DESTDIR%/NO1_055.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002EE00 "00020200" %DESTDIR%/NO1_057.mud
python extract_cabin_bgm.py %DISKNAME% 0x0002FA00 "00019600" %DESTDIR%/NO1_059.mud
python extract_cabin_bgm.py %DISKNAME% 0x00030400 "00019600" %DESTDIR%/NO1_061.mud
python extract_cabin_bgm.py %DISKNAME% 0x00030E00 "00019600" %DESTDIR%/NO1_063.mud
python extract_cabin_bgm.py %DISKNAME% 0x00032000 "00019600" %DESTDIR%/NO1_065.mud
//
python extract_binary.py %DISKNAME% 0x19600 0x200 %DESTDIR%/00019600.KI2
python extract_binary.py %DISKNAME% 0x1EE00 0x200 %DESTDIR%/0001EE00.KI2
python extract_binary.py %DISKNAME% 0x20200 0x200 %DESTDIR%/00020200.KI2


:DISK2
set DISKNAME=disks/THE_TOWER_OF_CABIN_2.dsk
set DESTDIR=MUDRV/CABIN_2
python extract_cabin_bgm.py %DISKNAME% 0x00067000 "00067C00" %DESTDIR%/NO2_001.mud
python extract_cabin_bgm.py %DISKNAME% 0x00067E00 "00067C00" %DESTDIR%/NO2_003.mud
python extract_cabin_bgm.py %DISKNAME% 0x00069200 "00067C00" %DESTDIR%/NO2_005.mud
python extract_cabin_bgm.py %DISKNAME% 0x00069A00 "00067C00" %DESTDIR%/NO2_007.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006AE00 "00067C00" %DESTDIR%/NO2_009.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006BE00 "00067C00" %DESTDIR%/NO2_011.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006C200 "0006CA00" %DESTDIR%/NO2_013.mud
rem python extract_cabin_bgm.py %DISKNAME% 0x0006C200 "0006CA00" %DESTDIR%/NO2_015.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006CC00 "00067C00" %DESTDIR%/NO2_018.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006D200 "0006CA00" %DESTDIR%/NO2_020.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006E000 "00067C00" %DESTDIR%/NO2_022.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006E800 "00067C00" %DESTDIR%/NO2_024.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006F600 "00070400" %DESTDIR%/NO2_026.mud
rem python extract_cabin_bgm.py %DISKNAME% 0x0006C200 "0006CA00" %DESTDIR%/NO2_028.mud
python extract_cabin_bgm.py %DISKNAME% 0x00070600 "0006CA00" %DESTDIR%/NO2_031.mud
python extract_cabin_bgm.py %DISKNAME% 0x00071000 "00067C00" %DESTDIR%/NO2_033.mud
python extract_cabin_bgm.py %DISKNAME% 0x00071A00 "00067C00" %DESTDIR%/NO2_035.mud
python extract_cabin_bgm.py %DISKNAME% 0x00072C00 "00067C00" %DESTDIR%/NO2_037.mud
rem python extract_cabin_bgm.py %DISKNAME% 0x00071000 "00067C00" %DESTDIR%/NO2_039.mud
python extract_cabin_bgm.py %DISKNAME% 0x00073400 "00067C00" %DESTDIR%/NO2_042.mud
python extract_cabin_bgm.py %DISKNAME% 0x00074800 "00067C00" %DESTDIR%/NO2_044.mud
python extract_cabin_bgm.py %DISKNAME% 0x00075800 "00070400" %DESTDIR%/NO2_046.mud
python extract_cabin_bgm.py %DISKNAME% 0x00076600 "00067C00" %DESTDIR%/NO2_048.mud

python extract_cabin_bgm.py %DISKNAME% 0x00067800 ""         %DESTDIR%/NO2_002.mud
python extract_cabin_bgm.py %DISKNAME% 0x00068A00 ""         %DESTDIR%/NO2_004.mud
python extract_cabin_bgm.py %DISKNAME% 0x00069800 ""         %DESTDIR%/NO2_006.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006A800 ""         %DESTDIR%/NO2_008.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006B800 ""         %DESTDIR%/NO2_010.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006C000 ""         %DESTDIR%/NO2_012.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006C800 ""         %DESTDIR%/NO2_014.mud
rem python extract_cabin_bgm.py %DISKNAME% 0x0006C800 ""         %DESTDIR%/NO2_016.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006D000 ""         %DESTDIR%/NO2_019.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006DC00 ""         %DESTDIR%/NO2_021.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006E600 ""         %DESTDIR%/NO2_023.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006F200 ""         %DESTDIR%/NO2_025.mud
python extract_cabin_bgm.py %DISKNAME% 0x0006FE00 ""         %DESTDIR%/NO2_027.mud
rem python extract_cabin_bgm.py %DISKNAME% 0x0006C800 ""         %DESTDIR%/NO2_029.mud
python extract_cabin_bgm.py %DISKNAME% 0x00070C00 ""         %DESTDIR%/NO2_032.mud
python extract_cabin_bgm.py %DISKNAME% 0x00071600 ""         %DESTDIR%/NO2_034.mud
python extract_cabin_bgm.py %DISKNAME% 0x00072600 ""         %DESTDIR%/NO2_036.mud
python extract_cabin_bgm.py %DISKNAME% 0x00073200 ""         %DESTDIR%/NO2_038.mud
rem python extract_cabin_bgm.py %DISKNAME% 0x00071600 ""         %DESTDIR%/NO2_040.mud
python extract_cabin_bgm.py %DISKNAME% 0x00074200 ""         %DESTDIR%/NO2_043.mud
python extract_cabin_bgm.py %DISKNAME% 0x00075400 ""         %DESTDIR%/NO2_045.mud
python extract_cabin_bgm.py %DISKNAME% 0x00076200 ""         %DESTDIR%/NO2_047.mud
python extract_cabin_bgm.py %DISKNAME% 0x00077200 ""         %DESTDIR%/NO2_049.mud

python extract_binary.py %DISKNAME% 0x67C00 0x200 %DESTDIR%/00067C00.KI2
python extract_binary.py %DISKNAME% 0x6CA10 0x200 %DESTDIR%/0006CA10.KI2
python extract_binary.py %DISKNAME% 0x70400 0x200 %DESTDIR%/00070400.KI2

:DISK3
set DISKNAME=disks/THE_TOWER_OF_CABIN_3.dsk
set DESTDIR=MUDRV/CABIN_3
python extract_cabin_bgm.py %DISKNAME% 0x00070800 "00071A00" %DESTDIR%/NO3_001.mud
python extract_cabin_bgm.py %DISKNAME% 0x00071400 "00071A00" %DESTDIR%/NO3_002.mud
python extract_cabin_bgm.py %DISKNAME% 0x00071C00 "00071A00" %DESTDIR%/NO3_003.mud
python extract_cabin_bgm.py %DISKNAME% 0x00072400 "00071A00" %DESTDIR%/NO3_004.mud
python extract_cabin_bgm.py %DISKNAME% 0x00072800 "00071A00" %DESTDIR%/NO3_005.mud
python extract_cabin_bgm.py %DISKNAME% 0x00073000 "00071A00" %DESTDIR%/NO3_006.mud

python extract_binary.py %DISKNAME% 0x71A00 0x200 %DESTDIR%/00071A00.KI2
python extract_binary.py %DISKNAME% 0x73600 0x200 %DESTDIR%/00073600.KI2


:DISK3_PLUS
set DISKNAME=disks/THE_TOWER_OF_CABIN_3.dsk
set DESTDIR=MUDRV/CABIN_3P
python extract_0c00.py %DISKNAME% %DESTDIR% NO3P
python extract_binary.py %DISKNAME% 0x71A10 0x200 %DESTDIR%/00071A00.KIK



pause
