#include "screen.h"

// make a pointer to the screen buffer
// video buffer starts at 0xB8000 
u16int *screen_buf = (u16int *)0xB8000;

// store cursor's x and y position
u8int pos_x = 0;
u8int pos_y = 0;

// storing the default color attribute
// default color attribute is white on black
// color attribute is 8 bit with higher 4 bits representing
// background color and lower 4 bits color of char
u8int color_attr = 0x0F;

// send cursor's location to VGA board
void set_cursor()
{
    // calculate cursors current location
    // here we have set a mode of 80 x 24
    // i.e a mode of 24 line having 80 char
    // so we calculate the position accordingly
    //  ----> x direction
    //  |
    //  |
    // \/ y direction 
    u16int location = pos_y * 80 + pos_x;
    // we send high and low cursor byte at 0x3D4, but
    // first we need to tell VGA board we are sending
    // it the high or low byte
    outb( 0x3D4 , 14 ); // setting VGA board for high byte
    outb( 0x3D5 , location >> 8 ); // sending high byte
    outb( 0x3D4 , 15 ); // setting VGA board for low byte
    outb( 0x3D5 , location ); // sending low byte
}

// scroll by 1 line if at last line
void scroll()
{
    // we scroll by writing 80 blank (space) on the last line
    // a char is represented in 16 bits, with upper 8 bits representing 
    // color attributes and lower 8 bits representing ascii value of
    // the char to be displayed
    // we generate value for blank 
    u16int space = 0x20 | (color_attr << 8 ); 
    // check if we are at the last line ( 25 ), otherwise no need to scroll
    if (pos_y >=25)
    {
        // we move char written currently in buffer, up by 80 places
        int i; // to hold position
        for (i=0;i<24*80;i++)
        {
            screen_buf[i] = screen_buf[i+80];
        }
        // fill the last line with space/blank
        for (i=24*80;i<25*80;i++)
        {
            screen_buf[i] = space;
        }
        // set cursor position to last line
        pos_y = 24;
    }
}

// print a char out to screen
void put(char c)
{
    // here we need to handel all cases regarding the char being
    // back space - > 0x80, newline, tab or a normal printable char
    //
    // a char is represented in 16 bits, with upper 8 bits representing 
    // color attributes and lower 8 bits representing ascii value of
    // the char to be displayed
    
    // check for backspace
    if ( c == 0x80 )
    {
        // if we are not at first position in line move cursor 1 space back
        // else do nothing
        if ( pos_x )
        {
            pos_x--;
        }
    }
    // else if char is a tab
    else if ( c == 0x09 )
    {
        // increase cursor's position in multiples of 8
        // we take tab to be of 8 spaces
        u8int val = pos_x / 8; // get current int position
        pos_x = pos_x * 8 + 8; // increase by 8
    }
    // else if char is \r
    else if ( c == '\r' )
    {
        // we set cursor's x position to 0
        pos_x = 0;
    }
    // else if char is '\n'
    else if ( c == '\n' )
    {
        // we move to the next line first position
        pos_x = 0;
        pos_y++;
    }
    // all other printable characters
    else if ( c >= ' ' )
    {
        // all printable char are present above space/blank 
        // here we set the give car at current position and move
        // one place ahead
        u16int *position;
        position = screen_buf + ( pos_y * 80 + pos_x ); // get screen position
        *position = c | ( color_attr << 8 ); // store char at position
        pos_x++; // move one place
    }

    // we need to check if we reached end of line 
    if ( pos_x >= 80 )
    {
        // if at end of line we need to move to next line first position
        pos_x = 0;
        pos_y++;
    }

    // scroll the text
    scroll();
    // set cursor position
    set_cursor();
}

// clear the screen
void clear()
{
    // we write balnk/space to the whole video buffer and reset 
    // cursor position, clearing the screen
    int i;
    // get value for space, with default color attributes
    u16int space = 0x20 | color_attr<<8;
    // fill whole buffer with spaces
    for (i=0;i<25*80;i++)
    {
        screen_buf[i] = space;
    }
    // reset cursor position
    pos_x = 0;
    pos_y=  0;
    set_cursor();
}

// prints a NULL terminated string on the screen
void puts(char * c)
{
    // moves through c one by one until NULL ( \0 ) and keeps on printing
    // char out to screen
    int i=0;
    while (c[i])
    {
        put(c[i++]);
    }
}

// set the default color attribute
void set_color(u8int color_f, u8int color_b)
{
    // set the color attribute by taking 2 saperate values for
    // forground and background
    // color attribute is 8 bit with higher 4 bits representing
    // background color and lower 4 bits color of char
    color_attr = color_f | ( color_b << 4 );
}

// restors default color attribute
void restore_color()
{
    // resets the to default of white text on black background
    // call set color
    set_color(15,0);
}
