
#### Pacman

This game was developed in [C++](http://www.cplusplus.com) with [Allegro 5.2](https://www.allegro.cc/manual/5/), [here](https://github.com/Sphinxs/Scripts/blob/master/Allegro.sh) you can find a script to install Allegro 5.2 and bellow you can find the steps to run the game

```shell
    git clone https://github.com/Sphinxs/Pacman.git

    cd Pacman

    make
```

##### Img

How to fix *libpng warning : iccp : known incorrect Srgb profile*

`pngcrush -ow -rem allb -reduce file.png`