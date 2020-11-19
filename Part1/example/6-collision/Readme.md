![SFML](https://www.sfml-dev.org/images/logo.png)

# Collision

[![collision Link]](https://www.sfml-dev.org/tutorials/2.1/graphics-transform-fr.php)


## sfSprite_getGlobalBounds(sfSprite)

    - Brief:
        Get the global bounding rectangle of a sprite
    - Param:
        1) Sprite Sprite object
    - Return:
        Global bounding rectangle of the entity

---

## sfFloatRect_intersects(const sfFloatRect*, const sfFloatRect*, sfFloatRect*);

    - Brief:
        Check intersection between two rectangles
    - Param:
        1) rect1    First rectangle to test
        2) rect2    Second rectangle to test
        3) intersection     Rectangle to be filled with overlapping rect (can be NULL)
    - Return:
        sfTrue if rectangles overlap

---
