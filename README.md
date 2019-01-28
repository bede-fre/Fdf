# FDF

A simple 3D height-map renderer.


## Features :

* Height control
* Top and bottom colors choices as arguments
* Color gradient between bottom and top color
* Camera controls (translations, rotations, zoom)


## Download format :

```git clone https://github.com/bede-fre/Fdf.git```

## Compilation :

Enter in the dowloaded folder ```cd fdf/``` and compile an executable with command ```make``` after that run the program with or without color arguments ```./fdf map color_bottom color_top```

### Example :

```./fdf test_maps/42.fdf 0xFF0000 0x00FF00```

## Commands :

- W : Up
- S : Down
- D : Right
- A : Left
- Q : Left rotation
- E : Right rotation
- X : Enable/disable auto-rotation
- Z : Dezoom
- C : Zoom
- R : Up height
- F : Down height
- SPACE : Reset initial position
- ESC : Quit program

## Screenshots :

![screenshot](/screens/Pyramide.png?raw=true)

![screenshot](/screens/France.png?raw=true)
