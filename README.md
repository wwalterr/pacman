### Pacman

:fish_cake: Pacman with Dijkstra path finder written in C++ using Allegro 5

#### Setup

Install Allegro 5 dependencies:

```sh
sudo apt install -y build-essential cmake xorg-dev libgl1-mesa-dev libglu-dev libpng-dev libz-dev libcurl4-gnutls-dev libfreetype6-dev libjpeg-dev libvorbis-dev libopenal-dev libphysfs-dev libgtk2.0-dev libasound-dev libflac-dev libdumb1-dev exuberant-ctags dvi2ps dvipdfmx latex2html pandoc
```

Add Allegro 5 PPA:

```sh
add-apt-repository ppa:allegro/5.2
```

Install Allegro 5 (`apt update`):

```sh
sudo apt install liballegro5-dev liballegro-acodec5-dev liballegro-audio5-dev liballegro-dialog5-dev liballegro-image5-dev liballegro-physfs5-dev liballegro-ttf5-dev liballegro-video5-dev allegro5-doc
```

Install the image optimizer:

```sh
sudo apt install pngcrush
```

#### Run

Build the source code (compiling and linking):

```sh
make
```

Start the executable:

```
make run
```

#### Debug

Use the [GDB](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf) to debug the code.

Basic usage:

```sh
gdb pacman  # load the executable

run  # start the executable

backtrace  # summary how the executable is running

kill  # stop the executable
```