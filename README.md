# LInux Kernel Modules and Drivers

Hello, if you want to understand the Linux Kernel Modules and Drivers, you've
come to the right place! I always had this itch in the back of my head to 
understand the Linux Kernel from it's depth and Kernel Modules and Drivers are
a great starting point (personally). And we'll start with Kernel Modules as 
they are dynamic in the sense of that they are modular which means that they 
can be loaded and unloaded at runtime as we wish. Hence reducing the efforts of
compiling the kernel with `menuconfig` or another way (that's another rabbit 
hole we'll be going down with later).

> **NOTE**
> Not All Device Drivers are to be necessarily to be compiled with The Linux
> Kernel but only few are to be such as CPU driver, Memory Controller and a few
> others which are atomically necessary for successful completion of bootprocess

> **IMPORTANT**
> For the purpose of it, we'll need some tools on our system, I hope you're using
> Fedora Linux too, so run the following command on your terminal :

```bash
sudo dnf install kernel-devel gcc make
```

## What are Linux Kernel Device Drivers

The computers we use have many components and these device drivers enable us to
use these devices, like the CPU, Memory Controller, Disk Controllers, System 
timers and few other components are probed on boot which makes our system 
usable. These components (device drivers) are to be compiled within the kernel 
to make the boot process a success, otherwise the device just simply won't boot
even if there is necessary harware, because if the system can't detect them, 
then the boot sequence will just dump the process with Kernel Panics. Hence not
all but these necessary hardware drivers must be compiled within the kernel to
successfully boot our device up and get going on with the kernel modules and 
device drivers (this article or guide, whatever you may think of this doc as).

## What are Loadable Kernel Modules in Linux

There are other kinds of device drivers which can be loaded ondemand such as
Drivers for displays, USBs, network hardwares and other stuff. These loadable
kernel modules can also be used to print Hello World in the Kernel Logs 😉
which will serve us right for the learning purpose for going further with linux
kernel modules and device drivers. The filesystem drivers such as EXT4, BTRFS,
ZFS, XFS, NFS, FAT, and other filesystems are LKMs (Loadable Kernel Modules) as
they are loaded after the kernel loads these filesystems and mounts them after
which the PID 1 starts.

> **NOTE** 
> Each Directory have a README file which will explain the respective
> concept and procedure to follow and build Linux Kernel Drivers and Modules. 
> See You There! 🎉
