#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>

int timeBeforeReset = 30;
int mounted = 1;

sfBool checktime(sfClock *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    if (sfTime_asMilliseconds(time) > timeBeforeReset) {
        sfClock_restart(clock);
        return sfTrue;
    }
    return sfFalse;
}

void changeValue(int *r, int *g, int *b)
{

    if ((mounted == 1 && *r < 255) || (mounted == -1 && *r > 0))
        *r += mounted;
    else if ((mounted == 1 && *g < 255) || (mounted == -1 && *g > 0))
        *g += mounted;
    else if ((mounted == 1 && *b < 255) || (mounted == -1 && *b > 0))
        *b += mounted;
    else {
        mounted *= -1;
    }
}

int main()
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window =
        sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL);
    sfRenderWindow_clear(window, sfColor_fromRGB(255, 255, 255));

    sfClock *clock = sfClock_create();
    int r = 0;
    int g = 0;
    int b = 0;

    while (sfRenderWindow_isOpen(window)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyUp) && timeBeforeReset < 1000)
            timeBeforeReset += 1;
        if (sfKeyboard_isKeyPressed(sfKeyDown) && timeBeforeReset > 0)
            timeBeforeReset -= 1;
        if (sfKeyboard_isKeyPressed(sfKeyR))
            timeBeforeReset = 30;

        if (checktime(clock) == sfTrue) {
            changeValue(&r, &g, &b);
            sfRenderWindow_clear(window, sfColor_fromRGB(r, g, b));
            sfRenderWindow_display(window);
        }
    }
    return 0;
}