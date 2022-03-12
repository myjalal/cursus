
# ADD USERS

sudo useradd jechekao

# user privlage specification
sudo visudo
modify: jechekaoui  ALL=(ALL:ALL) ALL

# creat a group
sudo groupadd user42

# add someone to groupe
sudo usermod -aG user42 jechekao
sudo usermod -aG sudo jechekao
ps. -aG means "addgroup"

# password politics
sudo nano /etc/login.defs
PASS_MIN_DAYS 2 (max days before changing password again)
PASS_MAX_DAYS 30 (max days before password expires)
PASS_WARN_AGE 7 (how many day to worn before expires)

# apply password politics to existing users
sudo chage jechekao (and follow) (verify by adding -l before username)
or
sudo chage -M 30 -m 2 -W 7 -d 2022-03-12 jechekao
-M (maxdays) -m (mindays) -W(worndays) -d(last changed day)
PS. verify for each user (sudo chage -l jechekao)

# password quality (pwquality)
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
enforce_for_root
 
![test image](https://raw.githubusercontent.com/myjalal/cursus/main/Born2beroot/pics/Screen%20Shot%202022-03-12%20at%206.26.34%20PM.png"test image")

