# kitten_paw
Keymap for my Kitten Paw keyboard controller.

I got a Kitten Paw replacement keyboard controller from Bathroom Epiphanies at http://bathroomepiphanies.com/controllers/.
After using Fredriks fork of the tmk keyboard firmware, I learned that I can simply copy my keymap to the original tmk firmware and compile it successfully. This repo is supposed to be used as a submodule to the tmk firmware.

Clone the tmk firmware, add this repo as a submodule, then change into the kitten_paw_20160418 folder and build:
```
$ cat ~/bin/flash_keyboard
make -f Makefile.lufa clean
make -f Makefile.lufa
echo Put the keyboard in programming mode (LSFT + RSFT + PAUSE)
sleep 10

sudo dfu-programmer atmega32u2 erase --force
sudo dfu-programmer atmega32u2 flash kitten_paw_20160418_lufa.hex
sudo dfu-programmer atmega32u2 start
```
