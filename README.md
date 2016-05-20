# cfos
Simple operatin system with c
# Requirements
Operating system for working : Ubuntu
Cross compiler download from here : https://www.kernel.org/pub/tools/crosstool/files/bin/i686/4.6.3/i686-gcc-4.6.3-nolibc_i386-linux.tar.gz
After downloaded, rename the folder to gcc-cross or something you like, make sure you have added full path of /gcc-cross/i386-linux/bin into $PATH variable of environment by terminal command : export PATH=... (google for usage)
You must have installed gcc on ubuntu to use ar packager. just install gcc via apt-get
Player : Install qemu-system-x86 via apt-get
That's all
# Build and run
Just type ./run.sh in terminal and enter