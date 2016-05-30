/*
** goto.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:41:03 2016 pirou_g
** Last update Thu Mar 17 14:41:04 2016 pirou_g
*/

#ifndef GOTO_H_
#define GOTO_H_

# define LABEL(name) __asm__("\t"name":\n")
# define GOTO(label) __asm__("\tjmp "label"\n")

#endif /* GOTO_H_ */
