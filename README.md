# ISZ_H
- Enables Hotkeys for Laptops without a Middle Click.

## Download(s):
- Download the [AutoLoader Here](https://github.com/Cracko298/ISZ_H/releases/download/v1/iszhLoad.dll).
- Download the [Hotkey App Here](https://github.com/Cracko298/ISZ_H/releases/download/v1/iszhotkeys.exe).

## Building:
### Hotkeys Application:
```
> g++ -o iszhotkeys.exe -O3 -s hotkeys.cpp -luser32
```
### ISZ_H AutoLoader:
```
> g++ -shared -o iszhLoad.dll -O3 -s iszh_loader.cpp
```
