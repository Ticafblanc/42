<div id="top"></div>
<img src="images/Screen%20Shot%202021-12-08%20at%203.29.06%20AM.png" align="left" alt="Logo" width="180" height="280">
<br />
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

compile it all and pass an fd as a parameter

### Prerequisites

nothing

### Installation

1 - Set VirtualBox

Linux, Debian 64-bit -> 1gb -> create vdf -> VDI -> Dynamically allocated -> 8gb

Settings -> storage -> IDE -> cd -> debian-xx-x-x-amd64-netinst.iso

--------------------------------------------------------------------------------
STEP 2 - Installation
--------------------------------------------------------------------------------

Install (Not Graphical install)
Choose language (English)

Territory or area: Choose yours. For Me it's Other -> Europe ->
-> Russian Federation -> Canada (lmao) -> American English keyboard layout. Wait

Hostname: yourintralogin42 -> Domain name: leave empty ->
-> Root password: qwerty123(please no!); Re-enter. Full name: Your full name.
Real/intra/else, doesn't matter. Username: yourintralogin ->
Password: zxc1337 (bruh) -> Time zone: Your time zone or Moscow for Moscow
campus (yes). Wait.

................................................................................
substep 2.1 - partition setup

For basic part:
Partition method: Guided - use entire disk and set up encrypted LVM ->
-> SCSIX (0,0,0) (sda) - 8.6 GB ATA VBOX HARDDISK -> separate /home partition ->
-> yes. Wait.
Enter encryption passphrase twice -> 8.1G or just max ->
-> Finish partitioning and write changes to disk -> yes. Wait.

/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/|
| For bonus part:                                                              |
| Partition method: Manual -> SCSIX (0,0,0( (sda) -> 8.6 GB ATA HARDDISK ->    |
|-> yes -> pri/log 8.6 GB FREE SPACE -> Create a new partition (CRANP next) -> |
|-> 500M -> Primary -> Beginning -> Mount point -> Boot ->                     |
|-> Done setting up the partition(DSUP) -> pri/log -> CRANP -> 8.1GB or "max"->|
|-> Logical -> mount point -> Do not mount it -> DSUP ->                       |
|-> Configure encrypted volumes -> Yes -> Create encrypted volumes ->          |
|-> /dev/sda5 (press space to choose it) -> DSUTP -> Finish -> yes -> Wait.    |
|                                                                              |
| Enter encryption passphrase twice -> Configure the Logical Volume Manager -> |
|-> yes -> Create volume groupe -> LVMGroup ->                                 |
|-> press pace on /dev/mapper/sda5_crypt, continue ->                          |
|-> Create logical volume(CLV next) -> LVMGroup (LVMG next) -> root -> 2G      |
| CLV -> LVMG -> swap -> 1G                                                    |
| CLV -> LVMG -> home -> 1G                                                    |
| CLV -> LVMG -> var -> 1G                                                     |
| CLV -> LVMG -> srv -> 1G                                                     |
| CLV -> LVMG -> tmp -> 1G                                                     |
| CLV -> LVMG -> var-log -> all disk space that left -> Finish                 |
|                                                                              |
| Now u see "[!!] Partition disks" window and a lot of LVM VG LVMGroup LV ...  |
| Go to first #1 998.2 MB (under home, <volumename> #1 for next steps) ->      |
|-> Use as (UA next): -> EXT4 jfl -> Mount point: (MP next) -> /home ->        |
|-> Done setting up the partition (yep, DSUP)                                  |
| root #1 -> UA -> ext4 -> MU -> / - the root fs -> DSUP                       |
| srv #1 -> UA -> ext4 -> MU -> /srv -> DSUP                                   |
| swap #1 -> UA -> swap area -> DSUP                                           |
| tmp #1 -> UA -> ext4 -> MU -> /tmp -> DSUP                                   |
| var #1 -> UA -> ext4 -> MU -> /var -> DSUP                                   |
| var-log #1 -> UA -> ext4 -> MU -> Enter manually -> /var/log -> DSUP         |
| Scroll below -> Finish partitioning and write changes to disk -> yes         |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

Now chill, you have plenty of time to stretch your back while debian is
installing.
................................................................................

Scan another CD or DVD? -> no
Debian archive mirror country -> your nearest mirror or Russian Federation for
Moscow campus -> deb.debian.org (doesn't matter) ->
-> leave proxy info field empty and proceed.

Participate in the package usage survey? -> NO!

Soft seclection: remove SSH server & standart system utilities with space(again)
GRUB - YES! -> /dev/sda
Installlation complee -> continue

Virtual war machine is ready.

--------------------------------------------------------------------------------
STEP 3 - Configure your machine
--------------------------------------------------------------------------------

Enter your LVM encryption passphrase, log in into your user. GL HF.
Now we are going to install necessary software and configure it.

##################################################################
# I prefer Nano over Vi because of syntax highlighting.          #
# But these are the weapons of your choice. Feel free to use Vi. #
##################################################################

................................................................................
substep 3.1 - Installing sudo & adding user in groups

1) su - -> root password -> apt install sudo
2) [$ adduser <yourusername> sudo] (yep, you should be in root)
3) [$ sudo reboot], then log in again
4) [$ sudo -v] -> password
5) [$ sudo addgroup user42]
6) [$ sudo adduser yourusername user42]
7) [$ sudo apt update]
................................................................................
................................................................................
substep 3.2 - Installing SSH

1) [$ sudo apt install openssh-server]
2) [$ sudo nano /etc/ssh/sshd_config] -> change line "#Port 22" to "Port 4242" and
"#PermitRootLogin prohibit-password" to "PermitRootLogin no" -> save and exit
(i hope you know how to do it in Nano...)
3) [$ sudo nano /etc/ssh/ssh_config] -> change line "#Port 22" to "Port 4242"
4) [$ sudo service ssh status]. It's should be active.
................................................................................
................................................................................
substep 3.3 - Installing UFW

1) [$ sudo apt install ufw]
2) [$ sudo ufw enable]
3) [$ sudo ufw allow 4242]
4) [$ sudo ufw status]. It's should be active with 4242 and 4242(v6) ports allow
from anywhere
................................................................................
................................................................................
substep 3.4 - Configuring sudo

1) [$ sudo touch /etc/sudoers.d/sudoconfig]
2) [$ sudo mkdir /var/log/sudo] (for sudo log files, yes)
3) [$ sudo nano /etc/sudoers.d/sudoconfig] then write next lines in our new file:

************************************************************
* Defaults      passwd_tries=3                             *
* Defaults      badpass_message="Incorrect password"       * <- you can set your
* Defaults      log_input,log_output                       *    own message here
* Defaults      iolog_dir="/var/log/sudo"                  *
* Defaults      requiretty                                 *
* Defaults      secure_path="that/long/paths/from/subject" *
************************************************************

................................................................................
................................................................................
substep 3.5 - Setting up a strong password policy

1) [$ sudo nano /etc/login.defs]
2) replace next lines:

*************************************************
* PASS_MAX_DAYS    99999 -> PASS_MAX_DAYS    30 * <- line 160 you can easly
* PASS_MIN_DAYS    0     -> PASS_MIN_DAYS    2  *    reach it with ctrl+_ in
*************************************************    nano

PASS_WARN_AGE is 7 by defaults anyway so just ignore it.
3) [$ sudo apt install libpam-pwquality]
4) [$ sudo nano /etc/pam.d/common-password]
5) Add to the end of the "password requisite pam_pwqiality.so retry=3" line next
parameters

****************************************************************************************
* minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root *
****************************************************************************************

You should get_next_line(ha-ha):
"password requisite pam_pwqiality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root"

6) Now you have to change all your passwords according to your new password
policy
***************
* [$ passwd]      * <- change user password
* [$ sudo passwd] * <- change root password
***************
................................................................................

--------------------------------------------------------------------------------
STEP 4 - Network adapter configuration
--------------------------------------------------------------------------------

You may not be able to connect to your VM via SSH with standard settings in
VirtualBox. Theres a way to wix it!

1) Turn off your VM
2) Go to your VM settings in VirtualBox
3) Network -> Adapter 1 -> Advanced -> Port forwarding
4)Add new rule (little green button on right top side) and next parameters:

**************************************************************************
* Protocol       Host IP       Host Port       Guest IP       Guest Port *
* TCP            127.0.0.1     4242            10.0.2.15      4242       *
**************************************************************************
6) In your host (physical) machine open Terminal and run
[ssh <vmusername>@localhost -p 4242]

Now you can control your virtual machine from the host terminal.

---------------------------------------------------------------------------------
CONCLUSION
---------------------------------------------------------------------------------

And after all of this manipulations we finally came for our monitoring.sh script
All guidelines is already exists in README.md file. Theres one more thing to
install that already listed in monitroing.sh file:

**********************************
* [$ sudo apt install net-tools] *
**********************************

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Dont forget to make a clone or snapshot of your VM before evaluation !
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

virtual machine to use for creating or testing a program in a specific environment

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [x] install VirtualBox
- [x] download debian
- [X] install debian on VirtualBox
- [ ] 
- [ ]  
- [ ]  
- [ ]  

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
