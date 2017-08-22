#include "serial.h"

int Serial::ConvertBaudRate(int get_BaudRate)
{
    // how to use this function :
    // cfsetospeed(&config, ConvertBaudRate(BaudRate));
    switch (get_BaudRate)
    {
    case 0:
        return B0;  // hang up
        break;
    case 50:
        return B50;
        break;
    case 75:
        return B75;
        break;
    case 110:
        return B110;
        break;
    case 134:
        return B134;
        break;
    case 150:
        return B150;
        break;
    case 200:
        return B200;
        break;
    case 300:
        return B300;
        break;
    case 600:
        return B600;
        break;
    case 1200:
        return B1200;
        break;
    case 1800:
        return B1800;
        break;
    case 2400:
        return B2400;
        break;
    case 4800:
        return B4800;
        break;
    case 9600:
        return B9600;
        break;
    case 19200:
        return B19200;
        break;
    case 38400:
        return B38400;
        break;
    case 57600:
        return B57600;
        break;
    case 115200:
        return B115200;
        break;
    case 230400:
        return B230400;
        break;
    case 460800:
        return B460800;
        break;
    case 500000:
        return B500000;
        break;
    case 576000:
        return B576000;
        break;
    case 921600:
        return B921600;
        break;
    case 1000000:
        return B1000000;
        break;
    case 1152000:
        return B1152000;
        break;
    case 1500000:
        return B1500000;
        break;
    case 2000000:
        return B2000000;
        break;
    case 2500000:
        return B2500000;
        break;
    case 3000000:
        return B3000000;
        break;
    case 3500000:
        return B3500000;
        break;
    case 4000000:
        return B4000000;
        break;
    default:
        return BAUD_RATE_NOT_FOUND;
        break;
    }
}
int Serial::ConvertDataSize(int get_DataSize)
{
    // how to use this function :
    // config.c_cflag |= ConvertDataSize(DataSize);
    switch (get_DataSize)
    {
    case 5:
        return CS5;
        break;
    case 6:
        return CS6;
        break;
    case 7:
        return CS7;
        break;
    case 8:
        return CS8;
        break;
    default:
        return DATA_SIZE_NOT_FOUND;
    }
}
int Serial::ConvertParityBit(int get_ParityBit)
{
    // how to use this function :
    // ConvertParityBit(ParityBit);
    switch (get_ParityBit)
    {
    case PARITY_BIT_NONE:
        config.c_cflag &= (~PARENB);
        return CONVERT_PARITY_BIT_SUCCESS;
        break;
    case PARITY_BIT_ODD:
        config.c_cflag |= PARENB;
        config.c_cflag |= PARODD;
        config.c_iflag |= (INPCK | ISTRIP);
        return CONVERT_PARITY_BIT_SUCCESS;
        break;
    case PARITY_BIT_EVEN:
        config.c_cflag |= PARENB;
        config.c_cflag &= (~PARODD);
        config.c_iflag |= (INPCK | ISTRIP);
        return CONVERT_PARITY_BIT_SUCCESS;
        break;
    default:
        return CONVERT_PARITY_BIT_NOT_FOUND;
        break;
    }
}
int Serial::ConvertStopBit(int get_StopBit)
{
    // how to use this function :
    // ConvertStopBit(StopBit);
    switch (get_StopBit)
    {
    case 1:
        config.c_cflag &= (~CSTOPB);
        return CONVERT_STOP_BIT_SUCCESS;
        break;
    case 2:
        config.c_cflag |= CSTOPB;
        return CONVERT_STOP_BIT_SUCCESS;
        break;
    default:
        return CONVERT_STOP_BIT_NOT_FOUND;
        break;
    }
}
void Serial::SetCOM(string get_COM)
{
    COM = get_COM;
}
void Serial::SetBaudRate(int get_BaudRate)
{
    BaudRate = get_BaudRate;
}
void Serial::SetDataSize(int get_DataSize)
{
    DataSize = get_DataSize;
}
void Serial::SetParityBit(int get_ParityBit)
{
    ParityBit = get_ParityBit;
}
void Serial::SetStopBit(int get_StopBit)
{
    StopBit = get_StopBit;
}
void Serial::SetPort(string get_COM, int get_BaudRate, int get_DataSize, int get_ParityBit, int get_StopBit)
{
    SetCOM(get_COM);
    SetBaudRate(get_BaudRate);
    SetDataSize(get_DataSize);
    SetParityBit(get_ParityBit);
    SetStopBit(get_StopBit);
}
int Serial::SetPortConfig()
{
    // c_cflag : control mode flags
    // CLOCAL : Ignore modem status lines
    // CREAD : Enable receiver
    config.c_cflag = CLOCAL | CREAD;    // Enable the receiver and set local mode
    
    // set BaudRate
    if (ConvertBaudRate(BaudRate) == BAUD_RATE_NOT_FOUND)
        return SET_PORT_CONFIG_BAUD_RATE_NOT_FOUND;
    cfsetispeed(&config, ConvertBaudRate(BaudRate));    // SetInPutSpeed
    cfsetospeed(&config, ConvertBaudRate(BaudRate));    // SetOutPutSpeed

    // set DataSize
    if (ConvertDataSize(DataSize) == DATA_SIZE_NOT_FOUND)
        return SET_PORT_CONFIG_DATA_SIZE_NOT_FOUND;
    config.c_cflag &= ~CSIZE;   // Mask the character size bits
    config.c_cflag |= ConvertDataSize(DataSize);  // Select $DataSize$ data bits

    // set ParityBit
    if (ConvertParityBit(ParityBit) == CONVERT_PARITY_BIT_NOT_FOUND)
        return  SET_PORT_CONFIG_PARITY_BIT_NOT_FOUND;

    // set StopBit
    if (ConvertStopBit(StopBit) == CONVERT_STOP_BIT_NOT_FOUND)
        return SET_PORT_CONFIG_STOP_BIT_NOT_FOUND;

    // other configuration
    // drivers has no functions to do this !
    // so mess !
    // wait for update
    config.c_iflag &= ~(IXON | IXOFF | IXANY);  // ignore XON/XOFF
    config.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  //ignore \n
    config.c_iflag &= ~(INLCR | ICRNL | IGNCR); // ignore NL - CR and CR - NL
    config.c_oflag &= ~(ONLCR | OCRNL); // ignore NL - CR and CR - NL

    config.c_cc[VTIME] = 0; // time for wait
    config.c_cc[VMIN] = 0;  // min string length
    tcflush(fd, TCIFLUSH);  // refresh input and output Buffers

    // set now
    status = tcsetattr(fd, TCSANOW, &config);
    if (status > 0)
        return status;  // EBADF or EINTR or EINVAL or ENOTTY or EIO
    else
        return SET_PORT_CONFIG_SUCCESS;
}
int Serial::SetPortOpen()
{
    fd = open(("/dev/" + COM).c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
    // O_RDWR       Read +Write
    // O_NOCTTY    (terminal device) don't make it the controlling terminal for the process E.g. Ctrl-C
    // O_NDELAY    non-blocking ( ignore DCD - Data Carrier Detect )
    if (fd == FILE_OPEN_ERROR)
        return SET_PORT_OPEN_FILE_OPEN_ERROR;

    status = fcntl(fd,F_SETFL, 0);    // Block
    //status = fcntl(fd, F_SETFL, FNDELAY);    // Non-Block
    if (status < 0)
        return SET_PORT_OPEN_FCNTL_ERROR;

    status = isatty(fd);    // fd or STDIN_FILENO ?
    if (status == ISATTY_ERROR)
        return SET_PORT_OPEN_ISATTY_ERROR;

    cout << "Port opened successfully, fd = " << fd << " ." << endl;

    return SET_PORT_OPEN_SUCCESS;
}
int Serial::SetPortRead(void *Buf, int Length)
{
    // if return 0 : EOF ( use FILE_READ_EOF )
    // if return -1 : ERROR ( use FILE_READ_ERROR )
    return read(fd, Buf, Length);
}
int Serial::SetPortWrite(string Buf, int Length)
{
    // if return -1 : error ( use FILE_WRITE_ERROR )
    return write(fd, Buf.c_str(), Length);
}
int Serial::SetChangeString(string& Buf)     // TODO test
{
    const string OldStr = ";";
    const char NewLine[2] = {0x0a,'\0'};
    const string NewStr = NewLine;

    while (true)
    {
        string::size_type pos(0);
        if ((pos = Buf.find(OldStr)) != string::npos)
            Buf.replace(pos, OldStr.length(), string(NewStr));
        else
            break;
    }
}
int Serial::SetPortReadRefresh(void *Buf)
{
    //tcflush(fd, TCIFLUSH);  // refresh input and output Buffers
    bzero(Buf, sizeof(Buf));
}
int Serial::SetPortClose()
{
    // if return -1 : error ( use FILE_CLOSE_ERROR )
    return close(fd);
}