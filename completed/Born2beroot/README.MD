Login: jechekao
Password: Vrockpokey1!

# Patition
### View partition:
lsblk
### LVM (Local Volume Management)
manage partitions and can incrypt them

# USERS
### check users
cat /etc/passwd
## add 
sudo useradd jechekao -> fast lazy one without home directory
sudo adduser jechekao -> full add
### add or modify password
sudo passwd jechekao
### change shell
sudo usermod jechekao --shell /bin/bash (or what ever shell you want)
### change username
sudo usermod -l jechekao newname
### creat a home directory to user 
sudo useradd -m jechekao
### user power privlage specification
sudo visudo
modify: jechekaoui  ALL=(ALL:ALL) ALL
### delete user
sudo userdel jechekao
### login as an other user
sudo su - ironman (without sudo if you know the password)
## password politics
sudo nano /etc/login.defs
PASS_MIN_DAYS 2 (max days before changing password again)
PASS_MAX_DAYS 30 (max days before password expires)
PASS_WARN_AGE 7 (how many day to worn before expires)

## change password politics to existing users
sudo chage jechekao (and follow) (verify by adding -l before username)
or
sudo chage -M 30 -m 2 -W 7 -d 2022-03-12 jechekao
-M (maxdays) -m (mindays) -W(worndays) -d(last changed day)
PS. verify for each user (sudo chage -l jechekao)

## password quality (pwquality)
sudo nano /etc/pam.d/common-password
- add to password requisite pam_pwquality.so retry=3 : 
minlen=10 shadow difok=7 usercheck=1 maxrepeat=3 ucredit=-1 dcredit=-1 ucredit=-1 maxrepeat=3 enforce_for_root
- add to pam_unix.so obscure sha512
shadow
__________
minlen = (min lenth of password)
difok = (at least 7 characters are not in the old password) (doesn't work for root because when change root password, it doesnt ask for old one)
usercheck = (1 = active 0 = not active, to verify if password contain username)
maxrepeat = (how many time a character can repeat consecutivly)
ucredit = (how many upercase)
dcredit = (how many digits)
enforce_for_root (enforce it for root)
_____________
or 
automatically from shell:
sudo chage user_name -> follow the options
_____________
### see options:
sudo chage -l user_name
# Groups
### creat a group
sudo groupadd user42
### del a group
sudo groupdel user42
### add someone to group
sudo usermod -aG user42 jechekao
sudo usermod -aG sudo jechekao
ps. -aG means "addgroup"
### del someone from group
sudo gpasswd -d jechekao user42
### verificaiton:
- what groups you're in?
groups
- what groups a user belong to
groups jechekao
- all info about a user
id jechekao
- who's in a group?
getent group user42
- list groups
less /etc/group
or
getent group
_______________
# script
### location 
/bin/monitoring.sh
### cron
to execute the script every 10min:
sudo crontab -e -u root
modify this line
*/10 * * * * bash /home/jechekao/bin/monitoring.sh | wall

# apparmor
### status 
sudo aa-status

# sudo (root access)
### give a user or groupe sudo privilage
sudo visudo
### how many sudo commande run
cat /var/log/sudo/log | grep 'COMMAND' | wc -l
# ufw  (uncomplicatedfirewall )
### setup 
sudo nano /etc/ssh/sshd_config

Port 4242
PermitRootLogin no

### status
sudo ufw status
sudo systemctl status ufw

### remove rule
sudo ufw delete allow 8080/tcp
or  
sudo ufw delete deny 8080/tcp
# ssh (secureshell)
### status 
sudo systemctl status ssh
### host ip adress
hostname -I
### host mac 
cat /sys/class/net/*/address
### allow ssh with ufw
sudo ufw allow 4242/tcp

# hostname and partition
### find host name
hostname
### change hostname
sudo nano /etc/hostname
or 
sudo hostnamectl set_hostname machine1
and
from /etc/hosts change 127.0.0.1 machine1
sudo reboot



# script
### location
bash /home/jechekao/bin/monitoring.sh
automation using crontab (from chronos)
login as root and: crontab -l

## check cron 
sudo crontab -e -u root

### stop cron
# sources
### Grep
https://www.cyberciti.biz/faq/debian-ubuntu-linux-grep-command-tutorial-examples/
###  awk
https://www.howtogeek.com/562941/how-to-use-the-awk-command-on-linux/
### 

# mariadb
-> created a database named "data"
to verify the database: SHOW DATABASES;
created a user: MariaDB [(none)]> CREATE USER 'jalal'@'localhost' IDENTIFIED BY 'Vrockpokey1!';
La structure de formulation pour donner des droits sur une base de donnée à un utilisateur ce lit comme ceci: GRANT type_of_permission ON database_name.table_name TO 'username'@'localhost';
GRANT ALL PRIVILEGES ON data.* to 'jalal'@'localhost';
and
FLUSH PRIVILEGES;

# php
The following NEW packages will be installed:
  libsodium23 php php-cli php-common php-fpm php-mysql php7.3 php7.3-cli
  php7.3-common php7.3-fpm php7.3-json php7.3-mysql php7.3-opcache
  php7.3-readline
0 upgraded, 14 newly installed, 0 to remove and 0 not upgraded.

# wordpress
http://10.12.232.44/wordpress/wp-admin/

# plex server
http://10.12.232.44:32400/web/


