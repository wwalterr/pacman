### Pacman

Pacman written in C++ using Allegro 5, plus Dijkstra path finder

> See the interface through the [Pacman](./pacman.png) image

#### Setup

<details>
<summary>Dependencies</summary>

```sh
sudo apt install -y build-essential cmake xorg-dev libgl1-mesa-dev libglu-dev libpng-dev libz-dev libcurl4-gnutls-dev libfreetype6-dev libjpeg-dev libvorbis-dev libopenal-dev libphysfs-dev libgtk2.0-dev libasound-dev libflac-dev libdumb1-dev exuberant-ctags
```

</details>

<details>
<summary>Allegro 5</summary>

<details>
<summary>PPA</summary>

```sh
sudo add-apt-repository ppa:allegro/5.2
```

</details>

<details>
<summary>Packages</summary>

```sh
sudo apt install liballegro5-dev liballegro-acodec5-dev liballegro-audio5-dev liballegro-dialog5-dev liballegro-image5-dev liballegro-physfs5-dev liballegro-ttf5-dev liballegro-video5-dev
```

</details>

</details>

<details>
<summary>Image Optimizer</summary>

```sh
sudo apt install pngcrush
```

</details>

#### Run

<details>
<summary>Compile</summary>

```sh
make
```

</details>

<details>
<summary>Execute</summary>

```
make run
```

</details>

#### Debug

Use the GDB to debug the code.

```sh
gdb pacman  # load executable
```

```sh
run  # execute the executable
```

```sh
backtrace  # summary how the executable is running
```

```sh
kill  # stop the executable
```
