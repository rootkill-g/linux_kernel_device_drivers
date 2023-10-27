/*
 * File		: 	hello_kernel.c
 * Details	: 	Hello World Module
 * Author	:	rootkill
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("rootkill <rootkill.dedsec@gmail.com>");
MODULE_DESCRIPTION("Hello World Lodable Kernel Module");
MODULE_VERSION("1:1.0");

/*
 * Module Init Function
 */
static int __init hello_kernel_init(void)
{
  	pr_info("Hello Kernel. This is a LKM!");
	pr_info("This is just for demonstration purpose.");
	return 0;
}

/*
 * Module Exit Function
 */
static void __exit hello_kernel_exit(void)
{
  	pr_info("See you soon!");
  	pr_info("Hello Kernel Module Exited Successfully!");
}

/*
 * Calling the init and exit functions
 */
module_init(hello_kernel_init);
module_exit(hello_kernel_exit);
