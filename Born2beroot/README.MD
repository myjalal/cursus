Login: jechekao
Password: Vrockpokey1!
# USERS
## add 
sudo useradd jechekao -> fast lazy one without home directory
sudo adduser jechekao -> full add
### add or modify password
sudo paswd jechekao
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

# sudo


# ufw


# ssh
### host ip adress
hostname -I
### host mac 
cat /sys/class/net/*/address

# hostname and partition
### find host name
hostname
### change hostname
sudo nano /etc/hostname
sudo reboot



# script
### location
bash /home/jechekao/bin/monitoring.sh
automation using crontab (from chronos)
login as root and: crontab -l

# sources
### Grep
https://www.cyberciti.biz/faq/debian-ubuntu-linux-grep-command-tutorial-examples/
###  awk
https://www.howtogeek.com/562941/how-to-use-the-awk-command-on-linux/
### 
