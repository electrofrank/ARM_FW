/*
 * retarget.h
 *
 *  Created on: Jan 10, 2020
 *      Author: edoar
 */

#ifndef INC_RETARGET_H_

#include "stm32f4xx_hal.h"
#include <sys/stat.h>

void RetargetInit(UART_HandleTypeDef *huart);
int _isatty(int fd);
int _write(int fd, char* ptr, int len);
int _close(int fd);
int _lseek(int fd, int ptr, int dir);
int _read(int fd, char* ptr, int len);
int _fstat(int fd, struct stat* st);

#define INC_RETARGET_H_



#endif /* INC_RETARGET_H_ */
