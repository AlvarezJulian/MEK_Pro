	AREA    Bootloader_Section, DATA, READONLY
; Includes the binary file ../Drivers/Vendor/Board/SE21070/F750SerialPort_EDTBoot21070_v10001_231220.bin from the current source folder
        INCBIN  ../Drivers/Vendor/Board/SE21070/Loader/F750SerialPort_EDTBoot21070_v10001_231220.bin
        END