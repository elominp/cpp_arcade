##
## Makefile for libtardis in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis
## 
## Made by pirou_g
## Login   <pirou_g@epitech.net>
## 
## Started on  Wed Mar 16 17:03:46 2016 pirou_g
## Last update Sat Apr  2 17:09:05 2016 pirou_g
##

LIBNAME		= libtardis.so

STATICLIB	= $(LIBNAME:.so=.a)

AR		= ar -r

CC		= gcc

CXX		= g++

CFLAGS		= -Wall -Wextra -std=gnu11 -I./include -fPIC

CXXFLAGS	= -Wall -Wextra -std=c++11 -I./include -fPIC

SCFLAGS		= -Wall -Wextra -std=gnu11 -I./include -c

SCXXFLAGS	= -Wall -Wextra -std=c++11 -I./include -c

LDFLAGS		= -shared

CSRCS		= src/c/file/get_ram.c \
		  src/c/file/my_fdup.c \
		  src/c/file/my_fgeti.c \
		  src/c/file/my_fgetsize.c \
		  src/c/file/my_fread.c \
		  src/c/file/my_fwrite.c \
		  src/c/file/my_opcl.c \
		  src/c/convert_base.c \
		  src/c/flip_endian.c \
		  src/c/gen_flip_endian.c \
		  src/c/get_next_line.c \
		  src/c/get_option.c \
		  src/c/hashtable.c \
		  src/c/hashtable2.c \
		  src/c/hashtable3.c \
		  src/c/hexdump.c \
		  src/c/is_option.c \
		  src/c/listes.c \
		  src/c/listes2.c \
		  src/c/my_atoi.c \
		  src/c/my_countnb_b.c \
		  src/c/my_epur_str.c \
		  src/c/my_find_prime_sup.c \
		  src/c/my_get_el.c \
		  src/c/my_getnbr.c \
		  src/c/my_getnbr_base.c \
		  src/c/my_isneg.c \
		  src/c/my_is_prime.c \
		  src/c/my_malloc.c \
		  src/c/my_malloc2.c \
		  src/c/my_malloc3.c \
		  src/c/my_memcpy.c \
		  src/c/my_parse.c \
		  src/c/my_power_it.c \
		  src/c/my_power_rec.c \
		  src/c/my_printf.c \
		  src/c/my_ptrcmp.c \
		  src/c/my_ptrdup.c \
		  src/c/my_put.c \
		  src/c/my_putblank.c \
		  src/c/my_putchar.c \
		  src/c/my_putchar2.c \
		  src/c/my_putint.c \
		  src/c/my_put_nbr.c \
		  src/c/my_putnbr_base.c \
		  src/c/my_putnbr_base2.c \
		  src/c/my_putptr.c \
		  src/c/my_putstr.c \
		  src/c/my_putstr2.c \
		  src/c/my_revstr.c \
		  src/c/my_round.c \
		  src/c/my_showstr.c \
		  src/c/my_show_wordtab.c \
		  src/c/my_sort_int_tab.c \
		  src/c/my_square_root.c \
		  src/c/my_strcapitalize.c \
		  src/c/my_strcat.c \
		  src/c/my_strcmp.c \
		  src/c/my_strcpy.c \
		  src/c/my_strdup.c \
		  src/c/my_str_isalpha.c \
		  src/c/my_str_islower.c \
		  src/c/my_str_isnum.c \
		  src/c/my_str_isprintable.c \
		  src/c/my_str_isupper.c \
		  src/c/my_strlcat.c \
		  src/c/my_strlen.c \
		  src/c/my_strlowcase.c \
		  src/c/my_strnbr.c \
		  src/c/my_strncat.c \
		  src/c/my_strncmp.c \
		  src/c/my_strncpy.c \
		  src/c/my_strndup.c \
		  src/c/my_strstr.c \
		  src/c/my_strtab.c \
		  src/c/my_strtok.c \
		  src/c/my_str_to_wordtab.c \
		  src/c/my_strupcase.c \
		  src/c/my_swap.c \
		  src/c/my_uppercase.c \
		  src/c/print_binary.c \
		  src/c/tab_len.c \
		  src/c/trace.c \
		  src/c/variable.c \
		  src/c/worknb.c \
		  src/c/init.c \
		  src/c/aplay.c

CXXSRCS		= src/cpp/my_mem.cpp

COBJS		= $(CSRCS:.c=.o)

CXXOBJS		= $(CXXSRCS:.cpp=.o)

RM		= rm -rf

all:		$(COBJS) $(CXXOBJS)
		$(CXX) $(COBJS) $(CXXOBJS) $(LDFLAGS) -o $(LIBNAME)
		$(AR) $(STATICLIB) $(COBJS) $(CXXOBJS)

clean:
		$(RM) $(COBJS) $(CXXOBJS)

fclean:		clean
		$(RM) $(LIBNAME) $(STATICLIB)

re:		fclean all

.PHONY:		all clean fclean re
