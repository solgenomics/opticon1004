/************************************************************************/
/*                                                                     	*/
/*  Linker Script File													*/
/*                                                                     	*/
/************************************************************************/

MEMORY
{
	ROM (rx)  : ORIGIN = 0x60000000, LENGTH = 0x00400000
	RAM (rw)  : ORIGIN = 0x62000000, LENGTH = 0x00020000 		
}

SECTIONS 
{
  /* Start of the OS */
	MAGIC_WORD 0x60100000:		
	{
		*(AP_HEAD)
	} > ROM

	APP_START 0x60100100:		
	{
		_appstart = . ;
		*(AP_START)
		_eappstart = . ;
	} > ROM

  /* Main program code */
	PROGRAM _eappstart :
	{
		*(.text .text.*)           
		*(.gnu.linkonce.t.*)
		*(.glue_7)
		*(.glue_7t)
		*(.gcc_except_table)
		*(.rodata)                 
		*(.rodata*)
		*(.gnu.linkonce.r.*)
	} > ROM
	. = ALIGN(4);
	
	_program_end = . ;
 
  	.data 0x62000000 : AT (_program_end)			/* Start of data section, used for initialized data */
 	{												/* We place a copy of the data section directlty after */ 
		_data = .;									/* the end of the ROM code. We can use this to init this section after a restart */
		*(.data)
		*(.data.*)
		*(.gnu.linkonce.d*)
		. = ALIGN(4);
		_edata = . ;								
	} > RAM
	
	_ram_end = .; 
	_code_end = _ram_end - _data + _program_end;

	.bss _edata (NOLOAD) :					  		/* .bss section which is used for uninitialized data */
	{												/* Variables in this section get initialized to zero upon program start */
    	_bss = . ;
    	*(.bss)
		*(.gnu.linkonce.b*)
    	*(COMMON)
    	. = ALIGN(4);
		_ebss = . ;
	} > RAM
}


