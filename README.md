<div id="top"></div>

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Ticafblanc/42-cursus_libft">
    <code><img height="80" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg"></code>
  </a>

  <h3 align="center">libft</h3>

  <p align="center">
   Your very first own library!
    <br />
    <a href="https://github.com/Ticafblanc/42-cursus_libft"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Ticafblanc/42-cursus_libft">View Demo</a>
    ·
    <a href="https://github.com/Ticafblanc/42-cursus_libft/issues">Report Bug</a>
    ·
    <a href="https://github.com/Ticafblanc/42-cursus_libft/issues">Request Feature</a>
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

Summary: This project aims to code a C library regrouping usual functions that you’ll be use for all your next projects.

Version: 15

Chapter I Introduction

C programming can be very tedious when one doesn’t have access to those highly useful standard functions. This project allows you to re-write those functions, understand them, and learn to use them. This library will help you with all your future C projects.
Take the time to expand your libft throughout the year. But always, make sure to check which functions are allowed !

 Chapter II Common Instructions
 
• Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
• Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
• All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
• If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.
• Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
• To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file _bonus.{c/h}. Mandatory and bonus part evaluation is done separately.
• If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.
• We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
• Submit your work to your assigned git repository. Only the work in the git reposi- tory will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

 Chapter III Mandatory part
 
 Program name ==> libft.a
 
 Turn in files ==> *.c, libft.h, Makefile
 
 Makefile ==> Yes
 
 External functs. ==> Detailed below
 
 Libft authorized ==> Non-applicable
 
 Description ==> Write your own library, containing an extract of important functions for your cursus.

III.1 Technical considerations

• It is forbidden to declare global variables.
• If you need subfunctions to write a complex function, you should define these sub- functions as static to avoid publishing them with your library. It would be a good habit to do this in your future projects as well.
• Submit all files in the root of your repository.
• It is forbidden to submit unused files.
• Every .c must compile with flags.
• You must use the command ar to create your library, using the command libtool is forbidden.

III.2 Part 1 - Libc functions

In this first part, you must re-code a set of the libc functions, as defined in their man. Your functions will need to present the same prototype and behaviors as the orig- inals. Your functions’ names must be prefixed by “ft_”. For instance strlen becomes ft_strlen.

see subject for the rest

<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [VIM editor](https://www.vim.org)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

in the folder run the make command,
then use with -L. -lft to link libft.a

### Prerequisites

nothing

### Installation

nothing

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

mainly a statity library when creating another function as part of the 42 cursus

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [x] creation of de library
- [x] test with my main
- [X] test with [libftTester](https://github.com/Tripouille/libftTester)
- [X] test with [Libfteste](https://github.com/jtoty/Libftest)
- [X] test with [Libf-unit-test](https://github.com/alelievr/libft-unit-test)
- [X] push and correction ==> 125/100
- [] add comment 
- [] add get_next_line
- [] add printf

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Matthis DoQuocBao - [![LinkedIn][linkedin-shield]][linkedin-url] - matthisdqb@icloud.com

Project Link: [https://github.com/Ticafblanc/42-cursus_libft](https://github.com/Ticafblanc/42-cursus_libft)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Tripouille](https://github.com/Tripouille/libftTester)
* [jtoty](https://github.com/jtoty/Libftest)
* [alelievr](https://github.com/alelievr/libft-unit-test)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Ticafblanc/42-cursus_libft.svg?style=for-the-badge
[contributors-url]: https://github.com/Ticafblanc/42-cursus_libft/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Ticafblanc/42-cursus_libft.svg?style=for-the-badge
[forks-url]: https://github.com/Ticafblanc/42-cursus_libft/network/members
[stars-shield]: https://img.shields.io/github/stars/Ticafblanc/42-cursus_libft.svg?style=for-the-badge
[stars-url]: https://github.com/Ticafblanc/42-cursus_libft/stargazers
[issues-shield]: https://img.shields.io/github/issues/Ticafblanc/42-cursus_libft.svg?style=for-the-badge
[issues-url]: https://github.com/Ticafblanc/42-cursus_libft/issues
[license-shield]: https://img.shields.io/github/license/Ticafblanc/42-cursus_libft.svg?style=for-the-badge
[license-url]: https://github.com/Ticafblanc/42-cursus_libft/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/matthis-doquocbao-a4a381192?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3Bqur1a8wNS0OuvMWTRXIihA%3D%3D
<!--[product-screenshot]: images/Screen Shot.png-->
