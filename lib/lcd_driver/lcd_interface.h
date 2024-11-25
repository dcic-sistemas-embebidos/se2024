#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

    void setup_lcd(void);
    void loop_lcd(char* message, int cols, int row);
    void clean_row_lcd(int row);
    void clean_lcd(void);

#endif