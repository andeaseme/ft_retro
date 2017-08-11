# ft_retro
![screenshot](/ft_retro_demo.gif)
## Description
Shoot 'em up terminal game in the style of Gradius and Raiden.  It's a simple yet difficult fast paced game.  Collect power ups to keep up with the increasing number of enemys. 

Developed in C++ with ncurses library.  
## Compile and Play
```
make
./game
```
Controls:

    space: toggle auto-fire
    w: up
    a: left
    s: down
    d: right
    Alternatively arrow keys may be used
    
## Gameplay
Pick up power ups and avoid everything else.

The player, enemies, and bullets are displayed as single ascii characters.

Friendly:

    A - The ship you pilot
    ^ - Your bullets
    $ - Power ups to increase rate of fire and bullet count
    
Enemies:

    W - Basic flyby
    Y - Fires tracking bullets
    * - Bullets fired by Y
    Z - Gets you from the side
