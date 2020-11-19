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

            if (event.type == sfEvtMouseMoved) { // event type sfEvtMouseMoved, so easy :p
                int r = ( event.mouseMove.x * 255 ) / 1920;
                int g = ( event.mouseMove.y * 255 ) / 1080;
                sfRenderWindow_clear(window, sfColor_fromRGB(r, g, 100));
            }
            sfRenderWindow_display(window);
        }
    }
    return 0;
}