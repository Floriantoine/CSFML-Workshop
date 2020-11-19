#include<SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>


int main()
{
    printf("Press Escape for Exit\n");

    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL);
    int count = 0;

    sfClock *clock = sfClock_create(); // create new clock
    sfTime time;


    while (sfRenderWindow_isOpen(window))
    {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;

        time = sfClock_getElapsedTime(clock); // sfClock_getElapsedTime
        if (sfTime_asSeconds(time) > 1) { // stransforme sf Time to seconde
            count += 1;
            sfClock_restart(clock); // restart clock
        }
    }
    sfRenderWindow_close(window);
    printf("%d seconds passed\n", count);

    return 0;
}