#ifndef __INIT_H
#define __INIT_H

/*
  As of now we have installed only 2 init functions
  init with GDT and init without GDT
*/

void init_all();
void init_without_gdt();

#endif