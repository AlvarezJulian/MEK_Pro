/*
*****************************************************************************
**

**  File        : LinkerScript.ld
**
**  Abstract    : Linker script for STM32F750N8Hx Device with
**                64KByte FLASH, 320KByte RAM
**
**                Set heap size, stack size and stack location according
**                to application requirements.
**
**                Set memory bank area and size if external memory is used.
**
**  Target      : STMicroelectronics STM32
**
**
**  Distribution: The file is distributed as is, without any warranty
**                of any kind.
**
**  (c)Copyright Ac6.
**  You may use this file as-is or modify it according to the needs of your
**  project. Distribution of this file (unmodified or modified) is not
**  permitted. Ac6 permit registered System Workbench for MCU users the
**  rights to distribute the assembled, compiled & linked contents of this
**  file as part of an application binary file, provided that it is built
**  using the System Workbench for MCU toolchain.
**
*****************************************************************************
*/

/* Entry Point */
ENTRY(Reset_Handler)

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM); /* end of "RAM" Ram type memory */
/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size = 0x1000;      /* required amount of heap  */
_Min_Stack_Size = 0x1000; /* required amount of stack */

/* Specify the memory areas */
MEMORY
{
  ITCMRAM      (xrw)    : ORIGIN = 0x00000000,   LENGTH = 16K
  RAM          (xrw)    : ORIGIN = 0x20000000,   LENGTH = 320K
  SDRAM        (xrw)    : ORIGIN = 0xC0000000,   LENGTH = 16M
  FLASH	       (xrw)    : ORIGIN = 0x90000000,   LENGTH = 2M
  ASSETS_FLASH (r)      : ORIGIN = 0x90200000,   LENGTH = 30M
  BOOTLOADER (xrw)      : ORIGIN = 0x08000000,   LENGTH = 64k
}

TARGET(binary) /* specify the file format of binary file */
INPUT (../../Drivers/Vendor/Board/SE21070/Loader/F750SerialPort_EDTBoot21070_v10001_231220.bin) /* bootloader bin file path (relative to the output folder)*/
OUTPUT_FORMAT(default) /* restore the out file format */

/* Define output sections */
SECTIONS
{
  .bootloader :
  {
    . = ALIGN(4);
    KEEP(../../Drivers/Vendor/Board/SE21070/Loader/F750SerialPort_EDTBoot21070_v10001_231220.bin)
  } > BOOTLOADER
  /* The startup code goes first into FLASH */
  .isr_vector :
  {
    __ICFEDIT_intvec_start__ = .;
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
  } >FLASH

  /* The program code and other data goes into FLASH */
  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
    *(.eh_frame)

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */
  } >FLASH

  /* Constant data goes into FLASH */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH

  .ARM.extab   : { *(.ARM.extab* .gnu.linkonce.armextab.*) } >FLASH
  .ARM : {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
  } >FLASH

  .preinit_array     :
  {
    . = ALIGN(4);    
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    . = ALIGN(4);
  } >FLASH
  .init_array :
  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
    . = ALIGN(4);
  } >FLASH
  .fini_array :
  {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
    . = ALIGN(4);
  } >FLASH

  /* used by the startup to initialize data */
  _sidata = LOADADDR(.data);

  /* Initialized data sections goes into RAM, load LMA copy after code */
  .data : 
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */
  } >RAM AT> FLASH

  
  /* Uninitialized data section */
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss secion */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM

  /* User_heap_stack section, used to check that there is enough RAM left */
  ._user_heap_stack :
  {
    . = ALIGN(8);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >RAM

  /* Remove information from the standard libraries */
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }

  FramebufferSection (NOLOAD) :
  {
    *(TouchGFX_Framebuffer TouchGFX_Framebuffer.*)
    *(.gnu.linkonce.r.*)
    . = ALIGN(0x4);
  } >SDRAM

  FontFlashSection :
  {
    *(FontFlashSection FontFlashSection.*)
    *(.gnu.linkonce.r.*)
    . = ALIGN(0x4);
  } >ASSETS_FLASH

  TextFlashSection :
  {
    *(TextFlashSection TextFlashSection.*)
    *(.gnu.linkonce.r.*)
    . = ALIGN(0x4);
  } >ASSETS_FLASH

  ExtFlashSection :
  {
    *(ExtFlashSection ExtFlashSection.*)
    *(.gnu.linkonce.r.*)
    . = ALIGN(0x4);
  } >ASSETS_FLASH

  BmpCacheSection (NOLOAD) : { *(BmpCacheSection) } >SDRAM
  TouchGFX_Framebuffer (NOLOAD) : { *(TouchGFX_Framebuffer) } >SDRAM
  TouchGFX_Framebuffer1 (NOLOAD) : { *(TouchGFX_Framebuffer1) } >SDRAM
  TouchGFX_Framebuffer2 (NOLOAD) : { *(TouchGFX_Framebuffer2) } >SDRAM
}
