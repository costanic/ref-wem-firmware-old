// ****************************************************************************
//  Workplace Environmental Monitor
//
//  This is a reference deployment application utilizing mbed cloud 1.2.
//
//  By the ARM Reference Design Team
// ****************************************************************************

#ifndef __MULTIADDRLCD_H__
#define __MULTIADDRLCD_H__

#include <TextLCD.h>

// LCD which can have I2C slave address of eith 0x4e or 0x7e
class MultiAddrLCD {
public:

    MultiAddrLCD(PinName rs, PinName r, PinName d4, PinName d5, PinName d6, PinName d7);


    /*Only supporting 16x2 LCDs, so string will be truncated at 32
      characters.*/
    int printf(const char *format, ...);
    /*Print on the given line (0 or 1)*/
    int printline(int line, const char *msg);
    int printlinef(int line, const char *format, ...);
    void setBacklight(TextLCD_Base::LCDBacklight mode);
    void setCursor(TextLCD_Base::LCDCursor mode);
    void setUDC(unsigned char c, char *udc_data);

    void locate(int column, int row);
    void putc(int c);

private:
    TextLCD _lcd1;
};

#endif