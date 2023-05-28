# Pipex

Simulate the pipe "|" function of the shell.

## How to get it work

Clone the repository and go to it's root folder

```bash
  make
```
## Usage

```bash
  ./pipex <Infile> <cmd 1> <cmd 2> ... <cmd n> <Outfile>
```
## Bonus part  

 The bonus part covers heredoc functionnality, first you should
 ```bash
  make bonus
```
Then you can use it like this
```bash
  ./pipex_bonus here_doc DELIMITER <cmd 1> <cmd 2> ... <cmd n> <Outfile>
```
