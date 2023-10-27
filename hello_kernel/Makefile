CONFIG_MODULE_SIG=n

obj-m += hello_kernel.o

ifdef ARCH
	KDIR = /home/rootkill/rootkill/lkmd/hello_kernel/lib/modules/6.5.6/build
else
	KDIR = /lib/modules/$(shell uname -r)/build
endif

all:
	make -C $(KDIR) M=$(shell pwd) modules

clean:
	make -C $(KDIR) M=$(shell pwd) clean
