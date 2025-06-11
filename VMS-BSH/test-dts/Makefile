# Makefile

# Biến cho kernel module
KERNEL_MODULE := main
obj-m += $(KERNEL_MODULE).o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

# Biến cho user space program
USER_PROG := chr_dev
USER_SRC := $(USER_PROG).c
USER_OUT := $(USER_PROG)

# Mục tiêu mặc định
all: kernel user

# Biên dịch kernel module
kernel:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# Biên dịch user space program
user:
	gcc -o $(USER_OUT) $(USER_SRC)

# Dọn dẹp
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -f *.o *.mod *.mod.c *.symvers *.order
	rm -f $(USER_OUT)

.PHONY: all kernel user clean