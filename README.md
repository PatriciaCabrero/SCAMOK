# SCAMOK

Scamok is a beat them up videogame, where the player is surrounded by enemies. The player must kill as many enemies as possible until he reaches the final boss.


## Architecture
OOP based architecture. The factory pattern has been used as content and level generator. The observer pattern has been used to manage the input. 

A prefab manager has been implemented to configure and load objects from a text file (containing a list with all of its components as animations, physics...).

## Libraries used

- **OGRE 3D** as graphic motor.
- **Bullet** as physics motor.
- **CEGUI** as graphic user interface system.
- **FMod** as sound motor.

All the libraries has been compiled from their sources repositories and configured for x32 and x64 (Debug and Release).

## Controls
![SCAMOK Controls](/SCAMOK/Media/GUI/imagesets/Controles.png?raw=true " ")


## Contributors
  - Patricia Cabrero Villar
  - David Pérez Cogolludo
  - David González Jiménez
  - Álvaro Rodriguez-Peral Bustos
  - Colin Ulrich Cop
  - Gonzalo Guzmám Del Río

This videogame is part of a university project developed in three months.
