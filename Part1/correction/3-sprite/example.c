#include<SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Keyboard.h>


int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL);
    sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255));

    sfTexture *texture = sfTexture_createFromFile("./goomba.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f newScale = {2, 2};


    if (texture == NULL || sprite == NULL)
        return 1;

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);

    while (sfRenderWindow_isOpen(window))
    {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            sfSprite_setScale(sprite, newScale);

            sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255));
            sfRenderWindow_drawSprite(window, sprite, NULL);
            sfRenderWindow_display(window);
        }


    }
    return 0;
}