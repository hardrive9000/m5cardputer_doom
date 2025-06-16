# 🕹️ Doom!
This is Doom for M5 Cardputer

Cardputer does not have PSRAM, so things get tricky

Is mostly a port of [prBoom Port to GBA](https://github.com/doomhack/GBADoom) by doomhack

HAL was taken from [M5 Official User Demo](https://github.com/m5stack/M5Cardputer-UserDemo)

Some parts collected from [Retro-Go](https://github.com/ducalex/retro-go) project

Can work with original WADs after their conversion with GbaWadUtil, also lended from doomhack.

WAD is compiled into binary itself

Built against
[ESP-IDF v4.4.6](https://docs.espressif.com/projects/esp-idf/en/v4.4.6/esp32/index.html)

Save-load works with SD card

Save-load crashes without SD card

Sometimes crashes randomly

#### Controls
 - Forward: ;
 - Backward: .
 - Left: l
 - Right: '
 - Fire: opt
 - Strafe left: ctrl
 - Strafe right: alt
 - Use: fn
 - Map: tab
 - Weapon: 1-7

#### Cheats
 - iddqd - god mode
 - idkfa - keys, weapons, armor
 - idc<x><y> - jump to level E<x>M<x> (eg. idc14 jumps to E1M4)
   
#### Done
 - User input
 - Sounds (SFX)
 - Music
 - Save & Load
 - Optimize user input
 - Cheats!

#### To do
 - Load WAD from SD card (somehow, mmap?)
 - Fix minor music issues

## 📋 Requirements

- Linux Mint 21.3 | Codename: virginia | Kernel: 5.15.0-139-generic
- ESP-IDF 4.4.6
- Qmake

## 🛠️ Compiling and Running
Fire up a terminal and run the following commands:
```bash
hardrive@cinnamon:~$ sudo apt install -y git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0

hardrive@cinnamon:~$ mkdir -p ~/esp
hardrive@cinnamon:~$ cd ~/esp
hardrive@cinnamon:~/esp$ git clone -b v4.4.6 --recursive https://github.com/espressif/esp-idf.git

hardrive@cinnamon:~/esp$ cd esp-idf/
hardrive@cinnamon:~/esp/esp-idf$ ./install.sh esp32,esp32s3
hardrive@cinnamon:~/esp/esp-idf$ . $HOME/esp/esp-idf/export.sh # Note the space between the leading dot and the path!

hardrive@cinnamon:~/esp/esp-idf$ cd ~
hardrive@cinnamon:~$ git clone https://github.com/hardrive9000/m5cardputer_doom.git
hardrive@cinnamon:~$ cd m5cardputer_doom/
hardrive@cinnamon:~/m5cardputer_doom$ idf.py build
hardrive@cinnamon:~/m5cardputer_doom$ idf.py flash -p /dev/ttyACM0
```

### WAD Util

```bash
hardrive@cinnamon:~$ sudo apt install -y qt5-qmake qtbase5-dev

hardrive@cinnamon:~$ cd m5cardputer_doom/GbaWadUtil/
hardrive@cinnamon:~/m5cardputer_doom/GbaWadUtil$ mkdir build
hardrive@cinnamon:~/m5cardputer_doom/GbaWadUtil$ cd build
hardrive@cinnamon:~/m5cardputer_doom/GbaWadUtil/build$ qmake ../GbaWadUtil.pro
hardrive@cinnamon:~/m5cardputer_doom/GbaWadUtil/build$ make

hardrive@cinnamon:~/m5cardputer_doom/GbaWadUtil/build$ cd ..
 # place doom1.wad file somewhere near here
 # gbadoom.wad is needed to cover missing assets
hardrive@cinnamon:~/m5cardputer_doom/GbaWadUtil$ ./build/GbaWadUtil -in doom1.wad -out gdoom1.wad -cfile doom1.c -pwad ./gbadoom.wad
```
