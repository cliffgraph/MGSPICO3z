@echo off
python extract_0c00.py "disks/FRAY_D0.dsk" MUDRV/FRAY D0
python extract_0c00.py "disks/FRAY_D1.dsk" MUDRV/FRAY D1
python extract_0c00.py "disks/FRAY_G0.dsk" MUDRV/FRAY G0
python extract_0c00.py "disks/FRAY_G1.dsk" MUDRV/FRAY G1
python extract_binary.py "disks/FRAY_D0.dsk" 0x3A00 0x200 MUDRV/FRAY/FRAY.KIK
pause

