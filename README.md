## [Pacman](https://github.com/Sphinxs/Pacman)

:fish_cake: Pacman in C++ using Allegro 5

### About

Pacman, is an arcade game considered one of the classics of the medium, and an icon of 1980s popular culture. This game was developed in the OO class by [Sphinxs](https://github.com/Sphinxs).

### Setup

Install Allegro 5 dependencies:

```shell
sudo apt install -y git build-essential cmake xorg-dev libgl1-mesa-dev libglu-dev libpng-dev libz-dev libcurl4-gnutls-dev libfreetype6-dev libjpeg-dev libvorbis-dev libopenal-dev libphysfs-dev libgtk2.0-dev libasound-dev libflac-dev libdumb1-dev exuberant-ctags dvi2ps dvipdfmx latex2html pandoc liballegro-dialog5-dev
```

Add Allegro 5 PPA to your distro:

```shell
add-apt-repository ppa:allegro/5.2
```

If your distro don't accept PPA try to add the source [url](https://launchpad.net/~allegro/+archive/ubuntu/5.2) (*Technical details about this PPA*):

```shell
echo deb http://ppa.launchpad.net/allegro/5.2/ubuntu bionic main "\n"deb-src http://ppa.launchpad.net/allegro/5.2/ubuntu bionic main >> /etc/apt/sources.list
```

Install the lib:

```shell
sudo apt update && sudo apt install liballegro5-dev
```

If you receive the error, try to add the required key:

```shell
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys key_here # Modify the 'key_here'
```

> The game was tested in Ubuntu Budgie 18.04, Linux Mint 19.1 and Deepin 15.04

### Run

To run you can run the `makefile`, first compile the game:

```shell
make
```

And start:

```
make run
```

### Debug

If you want to contribute to the game and need to debug, use the [gdb](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf) to find the errors and resolve them. Basic usage:

```shell
gdb pacman # Load the game in debug mode

run # Starts the game

backtrace # Summary of how the game is running

kill # Stop the game
```