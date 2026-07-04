*This project has been created as part of the 42 curriculum by mfaivre*

# cub3d

## Description

`cub3d` is a small 3D game engine written in C with MiniLibX, inspired by the raycasting techniques used in early first-person games such as *Wolfenstein 3D*.

The program loads a map and configuration from a `.cub` file, parses textures and colors, renders a first-person view of the level, and lets the player move around the world in real time. The project focuses on recreating a 3D perspective from a 2D map using raycasting.

This project focuses on:

* parsing and validating a `.cub` configuration file,
* handling textures and color definitions,
* rendering walls with a raycasting algorithm,
* managing player movement and camera rotation,
* detecting collisions with walls,
* handling keyboard input and clean window shutdown.

In this repository, invalid configuration files are rejected before the game starts. The player can move through the map, rotate the camera, and explore the scene from a first-person point of view.

## Instructions

### Requirements

This version is set up for Linux and expects the MiniLibX sources in a `minilibx-linux/` directory at the root of the project.

Required tools and libraries:

* `cc`
* `make`
* X11 development libraries
* `zlib`
* the included `libft`
* MiniLibX for Linux in `minilibx-linux/`

Example packages on Debian/Ubuntu:

```
sudo apt-get install build-essential xorg libxext-dev zlib1g-dev libbsd-dev
```

If `minilibx-linux/` is missing, add it at the project root:

```
git clone https://github.com/42paris/minilibx-linux minilibx-linux
```

### Compilation

```
make
```

Useful cleanup targets:

```
make clean
make fclean
make re
```

### Execution

Run the program with a valid `.cub` map:

```
./cub3D maps/map.cub
```

Depending on the repository, other sample maps may also be available in the `maps/` directory.

### Controls

* `W`, `A`, `S`, `D`: move the player
* Left arrow / Right arrow: rotate the camera
* `Esc`: quit the game
* Window close button: close the game cleanly

### Map and Configuration Format

A valid `.cub` file must define:

* the north wall texture with `NO`,
* the south wall texture with `SO`,
* the west wall texture with `WE`,
* the east wall texture with `EA`,
* the floor color with `F`,
* the ceiling color with `C`,
* a map made of valid characters.

A valid map must:

* be closed and surrounded by walls,
* contain exactly one player start position,
* use only valid characters for walls, empty spaces, and the player start,
* not contain leaks or openings to the outside.

Common map symbols:

* `1`: wall
* `0`: empty floor
* `N`, `S`, `E`, `W`: player start position and orientation

## Notes

This project is mainly about parsing, rendering, and low-level graphics programming.

A valid implementation must ensure that the `.cub` file is parsed correctly, textures and colors are loaded safely, the map is validated before launch, movement respects wall collisions, and the game exits cleanly without leaks or undefined behavior.

## Resources

* MiniLibX for Linux, official repository: https://github.com/42paris/minilibx-linux
* Xlib documentation: https://www.x.org/releases/current/doc/libX11/libX11/libX11.html
* 42 MiniLibX guide: https://harm-smits.github.io/42docs/libs/minilibx
* Lode's Computer Graphics Tutorial - Raycasting: https://lodev.org/cgtutor/raycasting.html
* Wolfenstein 3D raycasting overview: https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
* 42 subject and project material provided on the intra

AI usage: AI was used only to write this `README.md`. It was not used for the project design, implementation, debugging, or testing.
