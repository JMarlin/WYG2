#include "context.h"
#include "desktop.h"
#include "calculator.h"
#include "../fake_lib/fake_os.h"

//================| Entry Point |================//

//Our desktop object needs to be sharable by our main function
//as well as our mouse event callback
Desktop* desktop;

//The callback that our mouse device will trigger on mouse updates
void main_mouse_callback(uint16_t mouse_x, uint16_t mouse_y, uint8_t buttons) {

    Desktop_process_mouse(desktop, mouse_x, mouse_y, buttons);
}

//Button handler for creating a new calculator
void spawn_calculator(Window* button_window, int x, int y) {

    static int calc_count = 0;

    //Create and install a calculator
    Calculator* temp_calc = Calculator_new();
    Window_insert_child((Window*)desktop, (Window*)temp_calc);
    Window_move((Window*)temp_calc, 0, 0);
}

void hide_active(Window* button_window, int x, int y) {

    Window_hide((Window*)List_get_at(desktop->window.children, desktop->window.children->count - 1));
}

void show_all(Window* button_window, int x, int y) {

    int i;

    for(i = 0; i < desktop->window.children->count; i++)
        Window_show((Window*)List_get_at(desktop->window.children, i));
}

//Create and draw a few rectangles and exit
int main(int argc, char* argv[]) {

    //Fill this in with the info particular to your project
    Context* context = Context_new(0, 0, 0);
    context->buffer = fake_os_getActiveVesaBuffer(&context->width, &context->height);

    //Create the desktop 
    desktop = Desktop_new(context);

    //Create a simple launcher window 
    Button* launch_button = Button_new(10, 10, 150, 30);
    Window_set_title((Window*)launch_button, "New Calculator");
    launch_button->window.mouseclick_function = spawn_calculator;
    Window_insert_child((Window*)desktop, (Window*)launch_button);

    Button* hide_button = Button_new(10, 50, 150, 30);
    Window_set_title((Window*)hide_button, "Hide Active");
    hide_button->window.mouseclick_function = hide_active;
    Window_insert_child((Window*)desktop, (Window*)hide_button);

    Button* show_button = Button_new(10, 90, 150, 30);
    Window_set_title((Window*)show_button, "Show All");
    show_button->window.mouseclick_function = show_all;
    Window_insert_child((Window*)desktop, (Window*)show_button);

    //Initial draw
    Window_paint((Window*)desktop, (List*)0, 1);

    //Install our handler of mouse events
    fake_os_installMouseCallback(main_mouse_callback);

    //Polling alternative:
    //    while(1) {
    //
    //        fake_os_waitForMouseUpdate(&mouse_x, &mouse_y, &buttons);
    //        Desktop_process_mouse(desktop, mouse_x, mouse_y, buttons);
    //    }

    return 0; 
}
