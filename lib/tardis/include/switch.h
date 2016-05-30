//
// Created by pirou_g on 20/03/16.
//

#ifndef SWITCH_H_
# define SWITCH_H_

# ifndef __cplusplus

#  define SWITCH(var) {typeof(a) cpy = var; int breaked = 0;
#  define END_SWITCH }
#  define CASE(value) if (!breaked && cpy == value)
#  define RANGE_CASE(start, end) if (!breaked && (cpy >= start && cpy < end))
#  define IRANGE_CASE(stt, end) if (!breaked && (cpy >= stt && cpy <= end))
#  define CUSTOM_CASE(cdt) if (!breaked && (cpy cdt))
#  define BREAK breaked = 1
#  define DEFAULT if (!breaked)

# endif /* __cplusplus */

#endif /* SWITCH_H_ */
