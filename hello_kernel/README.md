# Hello Kernel

Following the ritual of writing Hello World program, we will do so in a Kernel
Module, so let's define the structure of the directory.

```bash
	/project_root
		     \
		      /hello_kernel
				   \
				    |- hello_kernel.c
				    |- Makefile
```

Basically we create a directory: `mkdir hello_kernel` and then touch two files
inside it: `touch hello_kernel.c Makefile` and then we are all set to dive in.

## Importing the necessary header files

To write a linux kernel module we have to import the following header files in
our C program:

```c
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
```

With the help of these C libraries we can then use the functions provided by
these libraries which are essentially important to the linux kernel.

## Defining The Module Information

Every Linux Kernel Module have information about it, such as Author, Version,
Description and/or License information. We can do so using the following macros
provided by `linux/module.h`:

```c
MODULE_LICENSE("GPL");
MODULE_AUTHOR("You <You@email.com>");
MODULE_DESCRIPTION("Hello Kernel Loadable Module");
MODULE_VERSION(1:1.0);
```

Great! Let's now create the init function.

## Init function

Now the real kernel programming starts 👾

Let's define our init function (Or constructor, if you are that type) which will
be called when our module will be loaded into the kernel using `insmod`

```c
static int __init hello_kernel_init(void)
{
	pr_info("Hello Kernel!\n");
	pr_info("This is LKM!\n");
	return 0;
}

module_init(hello_kernel_init);
```

Let's take a minute and understand the defined function.

Here we can see that this is a static function which returns integer.
<br />
But what's `__init` ? Is this python?
<br />
No not at all, so this `__init` in here is a macro and is used to mark the
function as `initialization` function and with that the kernel can then use
this function on module initialization and free it when the kernel is finished
initializing the module. Then we define the function name, and then the
function's body starts. Here we are using the `pr_info` API from
`linux/kernel.h` library, which can then register itself using `module_init()`
function.

> **NOTE**
> There is also a C function in the `linux/kernel.h` header file with name
> `printk` which takes a log level macro and a string to print to kernel logs
> these macros are: KERN_INFO, KERN_ALERT, KERN_CRIT, KERN_WARNING, KERN_ERR,
> KERN_DEBUG, KERN_NOTICE and KERN_EMERG.

## Exit function

So we have a constructor, and for the balance we need a destructor as well,
which we can define as:

```c
static void __exit hello_kernel_exit(void)
{
	pr_info("Kernel module successfully unloaded!\n");
}

module_exit(hello_kernel_exit);
```

Ok so this was pretty small and after reading the `init` function definition
and explaination, this becomes straightforward in regard what the `__exit`
keyword is and what is `pr_info` is doing, and then it registers itself using
`module_exit()` function.
<br />
But why the return type of the function is void for `exit` and int for the
`init` function?
<br />
The reason is, loading a module can result in failure and can return a
non-zero value if failed, but since it is loaded, the unloading of the kernel
module is infallible and hence does not need to return anything.

> **NOTE**
> The module code is done now.
> Let's try to create a kernel module with our C code.

## Makefile

To build our C file into a loadable kernel module, we have to create a Makefile
which will along with the installed kernel on your system will generate a file
with `.ko` extension (along with many other, but our focus is the .ko file only)

So in the Makefile we touched before, we can put the following config:

```Makefile
CONFIG_MODULE_SIG=n

obj-m += hello_kernel.o

KDIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(shell pwd) modules

clean:
	make -C $(KDIR) M=$(shell pwd) clean
```

This Makefile will use another Makefile present in your current installation of
Linux, which is the directory we initialized KDIR var with.
So our Makefile is done now. Let's build our Kernel Module!

## Build

Run the command in the directory where your Makefile is:

```bash
sudo make
```

which will generate a kernel module which we can see as: `hello_kernel.ko`

## Loading the Kernel Module

Using the `insmod` utility we can load our kernel module into the kernel.
So let's do it:

```bash
sudo insmod hello_kernel.ko
```

## Verifying from Kernel Logs

To verify that your module was successfully loaded, run the command:

```bash
dmesg
```

which will print out the kernel logs to your terminal, and you can see your

```bash
Hello Kernel!
This is LKM!
```

messages. Pretty neat huh?

## Unloading the Kernel Module

To unload the kernel module, we can use the `rmmod` utility as:

```bash
sudo rmmod hello_kernel
```

which will unload the kernel module from the kernel.

## Verify from Kernel Logs

To verify that our kernel module was successfully unloaded from the kernel,
we can again use the `dmesg` utility as:

```bash
dmesg
```

and we can then see at the bottom of the dumped logs, our exit message:

```bash
Kernel module successfully unloaded!
```

## 🎉 Hurray We Have Now Created A Loadable Kernel Module!

See you in the next one!

### 👋🏻 さよなら!
![Sayonara](../assets/sayonara.png)