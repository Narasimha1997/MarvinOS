#ifndef __STARTUP_H
#define __STARTUP_H


//MBR boot info will be added later, this file is in active dev

#define CSHELL_LOGIN_COMMAND "cshell\n"
#define SYS_SHUTDOWN_COMMAND "shutdown\n"

#define SHELL_BEGIN_OPERATOR ">>> "

#define STARTUP_MESSAGE  "Waiting for command\n"

//public methods : 

void delegate_to_console();



#endif