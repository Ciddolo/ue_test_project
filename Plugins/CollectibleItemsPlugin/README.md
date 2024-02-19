# Collectible Item Plugin

> Simple plugin to collect items.

## Setup

The only thing needed is the BP_CollectibleItemManager (or CPP_CollectibleItemManager) who must be put in the scene.
In the blueprint version there is a simple UI who show the current score.
All the subclasses of CPP_CollectibleItem can be put in scene as well.

## CPP_CollectibleItemManager

CPP_CollectibleItemManager have some events, functions and properties for get score info and set new points:

### ScoreChanged

> Event who fire when score change.

### void AddPoints(int Points)

> Simple function for adding points.

### int GetCurrentScore()

> Simple function who return the current score.

### void ResetCurrentScore()

> Simple function who reset the current score.

### bool PrintDebug

> Check for print debug message in editor.