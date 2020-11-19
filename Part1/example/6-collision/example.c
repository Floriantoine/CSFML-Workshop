#include<SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Keyboard.h>


int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL);
    sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255));
    sfVector2f bigSize = {2, 2};
    sfVector2f smallSize = {1, 1};

    sfTexture *texture = sfTexture_createFromFile("./goomba.png", NULL);
    sfSprite *sprite = sfSprite_create();


    if (texture == NULL || sprite == NULL)
        return 1;

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    sfVector2i mousePos;

    while (sfRenderWindow_isOpen(window))
    {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);

        sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255));

        sfFloatRect boundingBox = sfSprite_getGlobalBounds(sprite);
        mousePos = sfMouse_getPositionRenderWindow(window);
        sfFloatRect mouseBox = {mousePos.x, mousePos.y, 1, 1};

        if (sfFloatRect_intersects(&mouseBox, &boundingBox, NULL)) {
            sfSprite_setScale(sprite, bigSize);
        } else
        {
            sfSprite_setScale(sprite, smallSize);
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    return 0;
}