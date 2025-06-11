#!/bin/bash
modprobe option
modprobe usbserial
modprobe qmi_wwan
modprobe cdc_wdm

echo 2dee 4d41 > /sys/bus/usb-serial/drivers/option/new_id

dmesg | grep -i tty
sleep 2

echo -e "AT\r" > /dev/ttyACM0
cat /dev/ttyACM0 &


# Detect modem via ModemManager
mmcli -L

# Connect via APN (replace 'internet' with your APN)
mmcli -m 0 --simple-connect="apn=internet"

# Optionally, bring interface up via NetworkManager
nmcli dev status
nmcli con add type gsm ifname ttyUSB0 con-name slm310 apn internet
nmcli con up slm310