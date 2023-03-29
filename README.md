# <p align="center">pipex </p>

<p align="center">
    <a href="https://www.cprogramming.com/"><img alt="Made with C" src="https://img.shields.io/badge/Made%20with-C-1f425f.svg"/></a>
    <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/bylkuss/pipex?color=lightblue" />
    <img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/bylkuss/pipex?color=critical" />
    <img alt="Code language count" src="https://img.shields.io/github/languages/count/bylkuss/pipex?color=yellow" />
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/bylkuss/pipex?color=blue" />
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/bylkuss/pipex?color=green" />
</p>

Pipex is a UNIX mechanism that reproduces in C the behaviour of a shell command. It launches as 
`./pipex infile cmd1 cmd2 outfile` and behaves as this following bash command line does: `$> < file1 cmd1 | cmd2 > file2`



## Functions introduced in this project
- open() -  The open() function shall establish the connection between a file and a file descriptor.
- pipe() -  pipe() creates a pipe, a unidirectional data channel that can be used for interprocess communication.
- fork() -  fork() creates a new process by duplicating the calling process.
- waitpid() - system call used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed
- access()  - check real user's permissions for a file.
- dup2() -  duplicate a file descriptor.
- close() - close() closes a file descriptor, so that it no longer refers to any file and may be reused.
- execve() -  execute program.
- perror() -  print a system error message.
- exit() -   cause normal process termination.
