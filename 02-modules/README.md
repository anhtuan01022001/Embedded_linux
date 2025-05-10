## install modules
- make
- sudo insmod /home/your_username/your_project_name/your_module_name.ko
- dmesg | tail -10

## uninstall modules

- sudo rmmod your_module_name
- make clean
- dmesg | tail -10