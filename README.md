# Very Simple Movement Game

## Movement

WASD / Arrow key to move

## Goal

reach 10 levels to win

## Game Mechanics
```
> asteroids ('0') randomly reinitialize each level
> dont touch the wall or the asteroids 
```

## Functions
changePos function is a utility function for move function
```cpp
bool changePos(char *nmap, char *omap) {
// --
}
void moveUp(char map[][mapX]) {
  if(!changePos(/* argument */))
      endscreen();
}
```

fairly easy to understand tbh
