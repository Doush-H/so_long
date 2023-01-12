# so_long
This is one of the projects in the curriculum of 42 School.

## The goal of the school
The schools concept relies on you teaching yourself by learning how to do research and ask for help of your peers when needed. There are no teachers nor lectures. The curriculum includes planty of projects that you need to finish in order to progress and finish the school. The projects increase in difficulty as you go. Main programming language used in the school is `C` and on later stages of the curriculum `C++` besides these two you also learn about other stuff like: `Docker`, `Virtual Machines`, `networking` and more.

## The goal of the project
In this project I created a 2d game using `minilibX` which is a library created by school to use in projects that require graphical interfaces. Main challenge was to read and understand the documentation of the library to figure out how to: manage windows, keaboard events, images and more. It also required more planning as it was one of the first bigger projects.

## In this project I learned about:
  - Better project management
  - MinilibX (library used for the project)
  - Reading and understanding documentation

## How to use it?
Clone the repository and move into it and run `make`. Run `so_long *map_to_run*` replace the *map_to_run* with one of the maps from maps directory. There are 3 valid maps and the rest are for error checks. If you want to create a map yourself you need to comply with the following rools:
  - map can only contain the following characters: *'1' (walls)*, *'0' (empty space thats walkable)*, *'P' (the player)*, *'E' (exit)*, *'C' (collectable)*.
  - map must be surrounded by walls (1)
  - map must be rectangular
  - There needs to be at least one exit and collectable and only one player
Rules of the game are simple: collect all the collectables and enter the exit to finish the game. You can move with the `W`, `A`, `S`, `D` keys and close the game by pressing the `ESC` key. 
