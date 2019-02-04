#include "display.h"


char * print_letter(unsigned char scancode) {
    switch (scancode) {
        case 0x0:
            return ("ERROR");
            break;
        case 0x1:
            return ("ESC");
            break;
        case 0x2:
            return ("1");
            break;
        case 0x3:
            return ("2");
            break;
        case 0x4:
            return ("3");
            break;
        case 0x5:
            return ("4");
            break;
        case 0x6:
            return ("5");
            break;
        case 0x7:
            return ("6");
            break;
        case 0x8:
            return ("7");
            break;
        case 0x9:
            return ("8");
            break;
        case 0x0A:
            return ("9");
            break;
        case 0x0B:
            return ("0");
            break;
        case 0x0C:
            return ("-");
            break;
        case 0x0D:
            return ("+");
            break;
        case 0x0E:
            return ("Backspace");
            break;
        case 0x0F:
            return ("Tab");
            break;
        case 0x10:
            return ("Q");
            break;
        case 0x11:
            return ("W");
            break;
        case 0x12:
            return ("E");
            break;
        case 0x13:
            return ("R");
            break;
        case 0x14:
            return ("T");
            break;
        case 0x15:
            return ("Y");
            break;
        case 0x16:
            return ("U");
            break;
        case 0x17:
            return ("I");
            break;
        case 0x18:
            return ("O");
            break;
        case 0x19:
            return ("P");
            break;
		case 0x1A:
			return ("[");
			break;
		case 0x1B:
			return ("]");
			break;
		case 0x1C:
			return ("ENTER");
			break;
		case 0x1D:
			return ("LCtrl");
			break;
		case 0x1E:
			return ("A");
			break;
		case 0x1F:
			return ("S");
			break;
        case 0x20:
            return ("D");
            break;
        case 0x21:
            return ("F");
            break;
        case 0x22:
            return ("G");
            break;
        case 0x23:
            return ("H");
            break;
        case 0x24:
            return ("J");
            break;
        case 0x25:
            return ("K");
            break;
        case 0x26:
            return ("L");
            break;
        case 0x27:
            return (";");
            break;
        case 0x28:
            return ("'");
            break;
        case 0x29:
            return ("`");
            break;
		case 0x2A:
			return ("LShift");
			break;
		case 0x2B:
			return ("\\");
			break;
		case 0x2C:
			return ("Z");
			break;
		case 0x2D:
			return ("X");
			break;
		case 0x2E:
			return ("C");
			break;
		case 0x2F:
			return ("V");
			break;
        case 0x30:
            return ("B");
            break;
        case 0x31:
            return ("N");
            break;
        case 0x32:
            return ("M");
            break;
        case 0x33:
            return (",");
            break;
        case 0x34:
            return (".");
            break;
        case 0x35:
            return ("/");
            break;
        case 0x36:
            return ("Rshift");
            break;
        case 0x37:
            return ("Keypad *");
            break;
        case 0x38:
            return ("LAlt");
            break;
        case 0x39:
            return ("Spc");
            break;
        default:
            /* 'keuyp' event corresponds to the 'keydown' + 0x80 
             * it may still be a scancode we haven't implemented yet, or
             * maybe a control/escape sequence */
            if (scancode <= 0x7f) {
                write("Unknown key down\n");
            } else if (scancode <= 0x39 + 0x80) {
                print_letter(scancode - 0x80);
            } else write("Unknown key up\n");
            break;
    }
}