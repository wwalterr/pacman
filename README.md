
#### [Pacman](https://github.com/Sphinxs/Pacman)

![Pacman](https://i.imgur.com/13lwVrC.png)

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/7b4cabacd3d54d49895199a748e15184)](https://www.codacy.com/app/Sphinxs/Pacman?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Sphinxs/Pacman&amp;utm_campaign=Badge_Grade)

This game was developed in [C++](http://www.cplusplus.com) with [Allegro 5.2](https://www.allegro.cc/manual/5/), [here](https://github.com/Sphinxs/Scripts/blob/master/Allegro.sh) you can find a script to install Allegro 5.2 and bellow you can find the steps to run the game

```shell
    git clone https://github.com/Sphinxs/Pacman.git

    cd Pacman

    make
```

##### Img

How to fix *libpng warning : iccp : known incorrect Srgb profile*

`pngcrush -ow -rem allb -reduce file.png`

#### Fix

0. Jumping

1. Resize Window / Full Screen

2. Window position dynamically ( Api Linux 'n Windows )

3. Better design ( Inspiration [here](http://joshkelle.com/projects/pacman.html) 'n [here](https://dribbble.com/shots/4008559-Let-s-Play-Label) )

4. Key Up and Key Down doesn't work

5. Animation

6. Lock `* display` ( [Lock Region](https://www.allegro.cc/manual/5/ALLEGRO_LOCKED_REGION) )