#include "keyboard.h"
#include "serial.h"
#include "irq.h"
#include "display.h"


unsigned char keycode[128] =
{
	0, 27, '1', '2', '3', '4', '5', '6', '7', '8',
	'9', '0', '-', '=', '\b',
	'\t',
	'q', 'w', 'e', 'r',
	't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
	0,
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
	'\'', '`', 0,
	'\\', 'z', 'x', 'c', 'v', 'b', 'n',
	'm', ',', '.', '/', 0,
	'*',
	0,
	' ',
	0,
	0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0,
	0,
	0,
	0,
	0,
	0,
	'-',
	0,
	0,
	0,
	'+',
	0,
	0,
	0,
	0,
	0,
	0, 0, 0,
	0,
	0,
	0,
};


void (*key_handler)(unsigned char key) = 0;

//keyboard's callback

void register_keyboard_handler(void (*key_handle)(unsigned char key)) {
    key_handler = key_handle;
}

static int keycount = 0;
//this is the default function invoked whenever keyboard interrupt occurs
void x86_32_irq_keyboard(registers_t *regs) {

    //the handler will process the keycode only if there is some program has registered a handler.
    //otherwise it will not waste time processing it
    if(key_handler) {
        //probe port 0x60 to obtain the keycode
        SCAN_CODE_t code = inb(KEYBOARD_SERIAL_PORT);

        if(!(code & 0x80)) {
			key_handler(keycode[code]);
		}
    }

}

void unregister_keyboard_handler() {
    key_handler = 0;  
}

void keyboard_init() {
    //registers a handler
    irq_install_handler(1, x86_32_irq_keyboard);
}