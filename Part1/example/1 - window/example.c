#include<SFML/Graphics.h>
#include <SFML/Window/Keyboard.h>


int main()
{
    sfVideoMode mode = {1920, 1080, 32}; // set mode
    sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL); // create window
    sfRenderWindow_clear(window, sfColor_fromRGB(120, 200, 10)); // clear window
    sfRenderWindow_display(window); // Print window

    while (sfRenderWindow_isOpen(window)) // check if window is open
    {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
    }
    sfRenderWindow_close(window); //close window
    return 0;
}