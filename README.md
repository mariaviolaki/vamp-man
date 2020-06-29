# Vamp-Man

This small 2D arcade game, made with C++ and SDL2, is the Capstone Project for Udacity's [C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

The user plays as a vampire whose goal is to get to every blood drop without hitting a garlic. The arrows on the keyboard are used to move the player around the maze. Depending whether the user reached their goal or not, a "You Win!" or "Game Over!" message appears on the screen before the game exits.

## Project Dependencies

* cmake >= 3.13:
    * [Instructions by CMake](https://cmake.org/install/)
* make >= 4.1 (for Linux & Mac), 3.81 (for Windows)
    * For Linux users, make is often installed by default
    * For Windows, [visit GnuWin32 for instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
    * For Mac, [install Xcode command line tools](https://developer.apple.com/xcode/features/)
* gcc/g++ >= 5.5:
    * For Linux users, gcc/g++ is often installed by default
    * For Windows, [visit MinGW for instructions](http://www.mingw.org/)
    * For Mac, [install Xcode command line tools](https://developer.apple.com/xcode/features/)
* pkg-config >= 0.29.1:
    * [Instructions by pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/)
* SDL >= 2.0:
    * [Instructions by the SDL Wiki](https://wiki.libsdl.org/Installation)
    * [Instructions by Lazy Foo' Productions](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php)
* SDL2_image >= 2.0:
    * [Instructions by SDL](https://www.libsdl.org/projects/SDL_image/)
    * [Instructions by Lazy Foo' Productions](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php)

## How to Build the Project

1. Clone this repository
2. Inside the top level directory, create a new folder named 'build': `mkdir build && cd build`
3. Compile the project: `cmake .. && make`
4. Run the executable: `./VampMan`

## Project Details

This game runs on an SDL window and was not built upon the code of another repository. The file structure, regarding the code, is clearly divided into two directories: One containing the header files, and one with the corresponding source code.

The project includes features such as the following:
* Handling user input (e.g. Lines 59-74 in `Game.cpp`)
* Overloaded functions (e.g. Lines 14-16 in `RenderManager.h`)
* Methods overriding virtual functions from the parent class (e.g. Lines 13-14 in `Player.h` and Lines 20-22 in `Character.h`)
* Smart pointers (e.g. Lines 40-47 in `Game.h`)
* Encapsulating behavior (e.g. Lines 11-26 in `Blood.h`)
* Other features, such as switch statements (e.g. Lines 26 - 45 in `Player.cpp`), range-based for loops (e.g. Lines 24 - 36 in `CollisionManager.cpp`), dynamic memory allocation (e.g. Lines 73 - 79 in `Map.cpp`), as well as a clear organization of the code into funtions, and use of classes, which can be seen throughout the project.
