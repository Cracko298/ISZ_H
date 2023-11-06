# ISZ_H
- Enables Hotkeys for Laptops without a Middle Click.

## Download(s):
- Download the [AutoLoader Here]().
- Download the [Hotkey App Here]().

## Building:
### Hotkeys Application:
```
> g++ -o iszhotkeys.exe -O3 -s hotkeys.cpp -luser32
```
### ISZ_H AutoLoader:
```
> g++ -shared -o iszhLoad.dll -O3 -s iszh_loader.cpp
```
