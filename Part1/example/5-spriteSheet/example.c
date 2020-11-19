#include<SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>

int NumberOfFrame = 5;

void initRect(sfTexture *texture, sfIntRect *target)
{
    target->top = 0;
    target->left = 0;
    target->height = sfTexture_getSize(texture).y;
    target->width = sfTexture_getSize(texture).x / NumberOfFrame;
}

void nextStep(int *currentStep, sfIntRect *rect, sfSprite *sprite)
{
    if (*currentStep >= NumberOfFrame) {
        *currentStep = 0;
        rect->left = 0;
    }
    if (*currentStep < NumberOfFrame) {
        rect->left = rect->width * *currentStep;
        *currentStep += 1;
    }
    sfSprite_setTextureRect(sprite, *rect);
}

int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL);
    sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255));
    sfRenderWindow_setFramerateLimit(window, 60);

    sfTexture *texture = sfTexture_createFromFile("./turtle.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfClock *clock = sfClock_create();
    sfTime time;
    sfIntRect rect;
    int currentStep = 0;

    if (texture == NULL || sprite == NULL)
        return 1;
    initRect(texture, &rect);

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);

    while (sfRenderWindow_isOpen(window))
    {

        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);

        time = sfClock_getElapsedTime(clock);
        if (sfTime_asMilliseconds(time) > 300) {
            sfClock_restart(clock);

            sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255));
            nextStep(&currentStep, &rect, sprite);
            sfRenderWindow_drawSprite(window, sprite, NULL);
            sfRenderWindow_display(window);
        }
    }
    return 0;
}