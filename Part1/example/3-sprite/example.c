#include<SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Keyboard.h>


int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL);
    sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255));

    sfTexture *texture = sfTexture_createFromFile("./goomba.png", NULL); //Create a texture based on a file
    sfSprite *sprite = sfSprite_create(); // Create a Sprite
    sfVector2f newPos = {500, 500};


    if (texture == NULL || sprite == NULL) // check if the Texture and the sprite are loaded
        return 1;

    sfSprite_setTexture(sprite, texture, sfFalse); // apply texture to sprite
    sfRenderWindow_drawSprite(window, sprite, NULL); // draw the sprite on the screen
    sfRenderWindow_display(window); // update the screen

    while (sfRenderWindow_isOpen(window))
    {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            sfSprite_setPosition(sprite, newPos); // Updated the position of the sprite

            sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255)); // clear the screen otherwise the old sprite remains displayed
            sfRenderWindow_drawSprite(window, sprite, NULL); // draw the sprite on the screen
            sfRenderWindow_display(window); // update the screen
        }


    }
    return 0;
}