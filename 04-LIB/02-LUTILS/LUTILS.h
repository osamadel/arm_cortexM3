#ifndef __LUTILS_H
#define __LUTILS_H

#define LUTILS_SET_BIT(port, pin)   port = port | (1 << pin)
#define LUTILS_CLR_BIT(port, pin)   port = port & ~(1 << pin)

#endif