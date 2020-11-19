#include<SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Keyboard.h>
#include <stdlib.h>


int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL);
    sfRenderWindow_clear(window, sfColor_fromRGB(120, 200, 10));
    sfEvent event;

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(window);

            if (event.type == sfEvtMouseButtonPressed) { // event type sfEvtMouseButtonPressed, so easy :p
                sfRenderWindow_clear(window, sfColor_fromRGB(200, 20, 100));
            }
            sfRenderWindow_display(window);
        }
    }
    return 0;
}