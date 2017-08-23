// Copyright YummyCarrot(huyuzhe)

// My Github Location:
// https://github.com/CRThu

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>    

#include <iostream>
#include <string>

using namespace std;

// ParityBit
#define PARITY_BIT_NONE 0   // 无校验
#define PARITY_BIT_ODD 1    // 奇校验
#define PARITY_BIT_EVEN 2   // 偶校验
// file operation
#define FILE_OPEN_ERROR -1
#define FILE_READ_EOF 0
#define FILE_READ_ERROR -1
#define FILE_WRITE_ERROR -1
#define FILE_CLOSE_ERROR -1
// isatty
#define ISATTY_ERROR 0  // not a valid descriptor associated with a terminal
// ConvertBaudRate
#define BAUD_RATE_NOT_FOUND -1
// ConvertDataSize
#define DATA_SIZE_NOT_FOUND -1
// ConvertParityBit
#define CONVERT_PARITY_BIT_SUCCESS 0
#define CONVERT_PARITY_BIT_NOT_FOUND -1
// ConvertStopBit
#define CONVERT_STOP_BIT_SUCCESS 0
#define CONVERT_STOP_BIT_NOT_FOUND -1
// SetPortOpen
#define SET_PORT_OPEN_FILE_OPEN_ERROR -1
#define SET_PORT_OPEN_FCNTL_ERROR -2
#define SET_PORT_OPEN_ISATTY_ERROR -3
#define SET_PORT_OPEN_SUCCESS 0
// SetPortConfig
// when SetPortConfig return >0 , that's tcsetattr() failed
#define SET_PORT_CONFIG_BAUD_RATE_NOT_FOUND -4
#define SET_PORT_CONFIG_DATA_SIZE_NOT_FOUND -5
#define SET_PORT_CONFIG_PARITY_BIT_NOT_FOUND -6
#define SET_PORT_CONFIG_STOP_BIT_NOT_FOUND -7
#define SET_PORT_CONFIG_SUCCESS 0

class Serial
{
public:
    // SetPort*
    void SetPort(string get_COM, int get_BaudRate, int get_DataSize, int get_ParityBit, int get_StopBit);
    int SetPortConfig();
    int SetPortOpen();
    int SetPortRead(void *Buf, int Length);
    int SetPortWrite(string Buf, int Length);
    int SetChangeString(string& Buf);
    int SetPortReadRefresh(void *Buf);
    int SetPortClose();
private:
    // Convert*
    int ConvertBaudRate(int get_BaudRate);
    int ConvertDataSize(int get_DataSize);
    int ConvertParityBit(int get_ParityBit);
    int ConvertStopBit(int get_StopBit);
    // Set*
    void SetCOM(string get_COM);
    void SetBaudRate(int get_BaudRate);
    void SetDataSize(int get_DataSize);
    void SetParityBit(int get_ParityBit);
    void SetStopBit(int get_StopBit);

    string COM; // dev/ttyS$COM$
    int BaudRate;   // E.g. 115200
    int DataSize;   // E.g. 8
    int ParityBit;  // E.g. 0
    int StopBit;    // E.g. 1
    int fd; // File descriptor
    int status; // return status
    termios config;    // config termios
};

#endif