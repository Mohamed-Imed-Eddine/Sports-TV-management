## Table of contents

- [Table of contents](#table-of-contents)
- [Description](#description)
- [What's included](#whats-included)
- [Features](#features)
- [Notes](#notes)
- [Compile and Run](#compile-and-run)
- [Creators](#creators)
- [Copyright and license](#copyright-and-license)


## Description

Sports TV management program written in C language.
The goal is to automate the choice of match to broadcast on a given day.




## What's included

Repository structure

```text
folder_name/
├──── main.c
├──── TV_LLC_BIBLIO.c
├──── TV_LLC_BIBLIO.h
├──── rang.txt 
├──── Equipes.txt
└──── images

```

## Features

* Choose the match to broadcast from the schedule and team ranks and display it.
* Enter match results at the end of the day.
* Update the rank file "rang.txt".
* Create a rank file for each 



* A rank text file "rang.txt" in which the data of each team in the
championship:
  Rank: rank of the team in the championship from 1 to 16- Eq: Name of a team formed by 10 characters maximum
  * Npt: Total points of the team
  * NbJ, NbG, NbN, NbP: number of games played, won, drawn and lost of the team
  * BP and BC: for goals scored and conceded
  * And finally Diff which represents the difference between the goals scored and the goals conceded by
each team

* This file is considered completed for the previous X-1 days. The fields are separated by blank space and each team will be on a different line.
  


## Notes
For each match, the names of the teams will be taken from the schedule of the daytime.


## Compile and Run

```text
Compile : gcc -Wall main.c TV_LLC_BIBLIO.c -o prog

Run : prog
```



## Creators

- [GHEBRIOUT Mohamed Imed Eddine](https://github.com/Mohamed-Imed-Eddine)
- [KANAAN Loueiy](https://github.com/loueiy)




## Copyright and license

Code and documentation copyright the authors. 
Code released under the [MIT License](https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt).


---



 


