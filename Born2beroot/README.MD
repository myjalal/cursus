
kdump: (installing kexec, kdump and crash)

- to install:
sudo apt-get install kdump-tools crash kexec-tools makedumpfile `uname -r`-dbg -y

- verify the version of the kernel installed:
uname -r

- Modify kexec-tools option:
go to /etc/default/kexec
modify LOAD_KEXEC=

- Modify kdump-tools option:
go to /etc/default/kdump-tools
modify USE_KDUMP=
activate KDUMP_SYSCTL="kernel.panic_on_oops=1" so that kdump 
- 
