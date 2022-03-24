<div id="top"></div>
<img src="images/Screen%20Shot%202021-12-08%20at%203.29.06%20AM.png" align="left" alt="Logo" width="150" height="250">
<div align="center">
  <a href="https://github.com/Ticafblanc/42/1-cursus/born2beroot">
    <code><img height="80" src="https://raw.githubusercontent.com/github/explore/80688e429a7d4ef2fca1e82350fe8e3517d3494d/topics/terminal/terminal.png"></code>
  </a>

  <h3 align="center">born 2 be root</h3>

  <p align="center">
    <br />
    <a href="https://github.com/Ticafblanc/42/1-cursus/born2beroot"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Ticafblanc/42/1-cursus/born2beroot">View Demo</a>
    ·
    <a href="https://github.com/Ticafblanc/42/1-cursus/born2beroot/issues">Report Bug</a>
    ·
    <a href="https://github.com/Ticafblanc/42/1-cursus/born2beroot/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

Summary: This document is a System Administration related exercise. 

Version: 1

Chapter I Preamble

<img src="images/Screen%20Shot%202021-12-08%20at%203.28.17%20AM.png" alt="Logo" width="350" height="280">

 Chapter II Introduction
 
This project aims to introduce you to the wonderful world of virtualization.

You will create your first machine in VirtualBox (or UTM if you can’t use VirtualBox) under specific instructions. Then, at the end of this project, you will be able to set up your own operating system while implementing strict rules.

 Chapter III General guidelines
 
• The use of VirtualBox (or UTM if you can’t use VirtualBox) is mandatory.
• You only have to turn in a signature.txt file at the root of your repository. You must paste in it the signature of your machine’s virtual disk. Go to Submission and peer-evaluation for more information.
  
see subject for the rest

<p align="right">(<a href="#top">back to top</a>)</p>

### Built With

* [VirtualBox](https://www.virtualbox.org)
* [Debian](https://www.debian.org)
* [VIM editor](https://www.vim.org)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

follow installation instruction 

### Prerequisites

installe virtualbox
download debian

### Installation

1 - Set VirtualBox

new => name folder => destination folder "sgoinfre/username" => Linux => Debian (64-bit) => 1024mb 
=> create a virtual hard disc now => VDI (virtual disc image) => Dynamically allocated => 8gb

Start => deian 9.13 amd64 netinst.iso

--------------------------------------------------------------------------------

2 - Set Debian

Install => french => canada => hostname "username42" => skip domaine name => chose root password => username 
=> userlogin => user password 

--------------------------------------------------------------------------------

3 - Set partition

Manuel => SCSIX (0,0,0) (sda) - 8.6 GB ATA VBOX HARDDISK => YES 

=> pri/log 8.2 GB frespace => create new partition => 500M => primary => beginning => Ext4 => /boot => done

=> pri/log 8.2 GB frespace => create new partition => MAX => logical => end => Ext4 => none=> done

--------------------------------------------------------------------------------

4 - Set encryption

configure encrypted volumes => yes => create encrypted volumes => /dev/sda5 => done => finish => yes 
=> chose encryption passphrase (Quebec42)

--------------------------------------------------------------------------------

5 - create volume grouop and logical volumes

configure the lopgical volume manager => YES => create volume group => volume group name 

create logical volume => select group volume => logical volume name => logical volume size

terminer
<img src="images/Screen%20Shot%202021-12-10%20at%202.45.37%20AM.png" align="right" alt="Logo" width="400" height="180">

--------------------------------------------------------------------------------

6 - Set logical volumes

select volume => select use as => select mount point => done setting up the partition

finish partition and write changes to disk

--------------------------------------------------------------------------------

7 - scan installation

YES => No => canada => deb.debian.org => continue

--------------------------------------------------------------------------------

8 - software selection

unselect all => continue

--------------------------------------------------------------------------------

9 - install grub software 

YES => /dev/sda

--------------------------------------------------------------------------------

10 - installation is done

start debian => select debian GNU/Linux => enter passphrase => enter login => enter password

--------------------------------------------------------------------------------

11 - check partition <img src="images/Screen%20Shot%202021-12-10%20at%205.52.01%20AM.png" align="right" alt="Logo" width="400" height="180">


- lsblk => 

--------------------------------------------------------------------------------

12 - switch to root 

- su - => root password

--------------------------------------------------------------------------------

13 - set sudo  

- switch to root => apt inatll sudo 

- cd /var/log => mkdir sudo

- cd /etc/sudoers.d => vi filename 

Defaults        passwd_tries=3

Defaults        badpass_message="<your message>"

Defaults        logfile="/var/log/sudo/filename"
  
Defaults        log_input,log_output
  
Defaults        iolog_dir="/var/log/sudo"
  
Defaults        requiretty
  
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
  
- adduser username sudo => switch to user
  
--------------------------------------------------------------------------------

14 - set SSH
  
 - sudo apt install openssh-server 
  
 - cd /etc/ssh => vi sshd_config
  
 #port 22 => port 4242
 
 #PermitRootLogin prohibit-password => PermitRootLogin no
  
- exit the VM => setting VirtualBox => network => adaptater 1 => port forwarding => add => host port 4242 => guestport 4242 => ok

 --------------------------------------------------------------------------------

15 - set UFW
  
- sudo apt install ufw
  
- sudo ufw allow 4242 => sudo ufw enable

--------------------------------------------------------------------------------

16 - set a password age
  
- cd /etc => vi login.defs
  
PASS_MAX_DAYS   99999 => 160 PASS_MAX_DAYS   30
  
PASS_MIN_DAYS   0 => PASS_MIN_DAYS   2
  
PASS_WARN_AGE   7 
  
--------------------------------------------------------------------------------

17 - set a password strength
 
- sudo apt install libpam-pwquality
  
- cd /etc/pam.d => vi common-password
  
password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root

--------------------------------------------------------------------------------

18 - set crontab
  
- sudo crontab -u root -e

m h  dom mon dow   command => */10 * * * * sh /path/to/script
  
--------------------------------------------------------------------------------

19 - intall and set lighttpd
  
- sudo apt install lighttpd
  
- sudo ufw allow 80
  
--------------------------------------------------------------------------------

20 - intall and set mariadb
  
- sudo apt install mariadb-server
  
- sudo mysql_secure_installation

Enter current password for root (enter for none): #Just press Enter (do not confuse database root with system root)

Set root password? [Y/n] n

Remove anonymous users? [Y/n] Y

Disallow root login remotely? [Y/n] Y

Remove test database and access to it? [Y/n] Y

Reload privilege tables now? [Y/n] Y
  
- sudo mariadb => MariaDB [(none)]> => CREATE DATABASE database-name => GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION => FLUSH PRIVILEGES => exit
  
--------------------------------------------------------------------------------

21 - intall php
  
- sudo apt install php-cgi php-mysql
  
--------------------------------------------------------------------------------

22 - intall and set wordpress
  
- sudo apt install w3m 

- w3m http://wordpress.org => download latest.tar.gz

- sudo tar -xyzf latest.tar.gz => sudo cp -r wordpress/* /var/www/html => sudo rm latest.tar.gz => sudo rm -rf /var/www/html/wordpress
  
- cd /var/www/html => sudo cp wp-config-sample.php wp-config.php => sudo wp-config.php
  
define( 'DB_NAME', 'database_name_here' );^M
define( 'DB_USER', 'username_here' );^M
define( 'DB_PASSWORD', 'password_here' );^M
  
- sudo lighty-enable-mod fastcgi
  
- sudo lighty-enable-mod fastcgi-php
  
- sudo service lighttpd force-reload
  
--------------------------------------------------------------------------------

23 - intall and set ftp (sftp)
  
- sudo apt install vsftpd
  
- sudo ufw allow 21
  
- cd /etc => vi vsftpd.conf
  
write_enable=YES
  
- sudo mkdir /home/<username>/ftp
  
- sudo mkdir /home/<username>/ftp/files
  
- udo chown nobody:nogroup /home/<username>/ftp
  
- sudo chmod a-w /home/<username>/ftp
<p align="right">(<a href="#top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

virtual machine to use for creating or testing a program in a specific environment
  
line commande fior use it
  
1 - su - or username = change for root or user session
  
2 - dpkg = manage debian pakage (dpkg -l | grep package = for check if package is already install)
  
3 - adduser(or useradd) addgroup(or groupadd) usermod = manage user config (adduser username = for create a new user/ adduser username namegroupe = for add to group)
  
4 - getent = displays supported database entries(getent group namegroup = for check user to group or getent passwd username = for check if user already created)
  
5 - reboot = with sudo privilege reboot vm engin
  
6 - systemctl = manage the init systeme (systemctl status ssh = for check the ssh statu)
  
7 - ufw = manage iptable with sudo access ( ufw status = for check firewall statu or ufw enable = for active the firewall or ufw delete "number" = for delete )
  
8 - hostname = retrieves the domain or host name (hostname -I = ip adress)

9 - ip = check the ip information (ip adress = ip adress)
  
10 - ssh = command to connect local server (ssh username@ipadress -p 4242 = to connect, sudo service --status-all)
  
10 - chage = display password information (chage -l username = list of password status)
  
11 - groups = display groups information 
  
12 - crontab = set to run command at fixed time (crontab -u root -e = set crontab or crontab -u root -l = display sitting)
  
13 - mariadb = command data base (mariadb -u username -p = connect database)

14 - groups = check group

  
<p align="right">(<a href="#top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [x] install VirtualBox
- [x] download debian
- [X] install debian on VirtualBox
- [X] install and set sudo
- [X] set user and group
- [X] install and set ssh
- [X] install and set UFW
- [X] set a strong password policy
- [X] create bash script monitoring.sh
- [X] set to run script evry 10 minutes (crontab)
- [X] install and set lighttpd
- [X] install and set mariadb
- [X] install php
- [X] set web sit on wp-admin.php
- [X] push and correction ==> 125/100

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Matthis DoQuocBao - [![LinkedIn][linkedin-shield]][linkedin-url] - matthisdqb@icloud.com

Project Link: [https://github.com/Ticafblanc/42/1-cursus/born2beroot](https://github.com/Ticafblanc/42/1-cursus/born2beroot)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [hanshazairi](https://github.com/hanshazairi/42-born2beroot)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Ticafblanc/42/1-cursus/born2beroot.svg?style=for-the-badge
[contributors-url]: https://github.com/Ticafblanc/42/1-cursus/born2beroot/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Ticafblanc/42/1-cursus/born2beroot.svg?style=for-the-badge
[forks-url]: https://github.com/Ticafblanc/42/1-cursus/born2beroot/network/members
[stars-shield]: https://img.shields.io/github/stars/Ticafblanc/42/1-cursus/born2beroot.svg?style=for-the-badge
[stars-url]: https://github.com/Ticafblanc/42/1-cursus/born2beroot/stargazers
[issues-shield]: https://img.shields.io/github/issues/Ticafblanc/42/1-cursus/born2beroot.svg?style=for-the-badge
[issues-url]: https://github.com/Ticafblanc/42/1-cursus/born2beroot/issues
[license-shield]: https://img.shields.io/github/license/Ticafblanc/42/1-cursus/born2beroot.svg?style=for-the-badge
[license-url]: https://github.com/Ticafblanc/42/1-cursus/born2beroot/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/matthis-doquocbao-a4a381192?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3Bqur1a8wNS0OuvMWTRXIihA%3D%3D
<!--[product-screenshot]: images/Screen Shot.png-->
