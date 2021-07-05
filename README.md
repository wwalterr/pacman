# Pacman

Control your Pac-man against ghosts.

## About

The classic Pac-man game with Dijkstra path finder.

## Executables

[Linux](./pacman)

## Built with

- [C++](https://en.cppreference.com/w/)
- [Allegro 5](https://liballeg.org/)

## Installation

Use the APT package manager to install general dependencies.

```bash
sudo apt install -y build-essential cmake xorg-dev libgl1-mesa-dev libglu-dev libpng-dev libz-dev libcurl4-gnutls-dev libfreetype6-dev libjpeg-dev libvorbis-dev libopenal-dev libphysfs-dev libgtk2.0-dev libasound-dev libflac-dev libdumb1-dev exuberant-ctags pngcrush
```

Use the APT package manager to add the Allegro 5 PPA and install it.

```bash
sudo add-apt-repository ppa:allegro/5.2
```

```bash
sudo apt install liballegro5-dev liballegro-acodec5-dev liballegro-audio5-dev liballegro-dialog5-dev liballegro-image5-dev liballegro-physfs5-dev liballegro-ttf5-dev liballegro-video5-dev
```

## Usage

Create a build.

```bash
make
```

Execute the build.

```bash
make run
```

## Debug

Use the GDB debugger to debug the build.

```bash
gdb pacman  # Load executable
```

```bash
(gdb) run  # Execute the executable
```

```bash
(gdb) backtrace  # Summary how the execution
```

```bash
(gdb) kill  # Stop the executable
```

## Contributing

Pull requests are welcome. Please, consider the following.

1. Make sure you code have quality, a.k.a standards
2. Make sure your code is secure
3. Make sure your code has no performance issues
4. Make sure your code is documented, if necessary
5. Describe the changes that were done

> No issue or PR template required, but be informative

## License

[MIT](./LICENSE.md)
