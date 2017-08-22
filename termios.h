#pragma once

// c_cflag用于设置控制参数，除了波特率外还包含以下内容：
// EXTA         External rate clock
// EXTB         External rate clock
// CSIZE         Bit mask for data bits
// CS5         5个数据位
// CS6         6个数据位
// CS7         7个数据位
// CS8         8个数据位
// CSTOPB         2个停止位（清除该标志表示1个停止位
// PARENB         允许校验位
// PARODD         使用奇校验（清除该标志表示使用偶校验）
// CREAD         Enable receiver
// HUPCL         Hangup(drop DTR) on last close
// CLOCAL         Local line – do not change “owner” of port
// LOBLK         Block job control outpu
// c_cflag标志可以定义CLOCAL和CREAD，这将确保该程序不被其他端口控制和信号干扰，同时串口驱动将读取进入的数据。CLOCAL和CREAD通常总是被是能的。
// 
// c_lflag用于设置本地模式，决定串口驱动如何处理输入字符，设置内容如下：
// ISIG            Enable SIGINTR, SIGSUSP, SIGDSUSP, and SIGQUIT signals
// ICANON         Enable canonical input(else raw)
// XCASE         Map uppercase \lowercase(obsolete)
// ECHO         Enable echoing of input characters
// ECHOE         Echo erase character as BS - SP - BS
// ECHOK         Echo NL after kill character
// ECHONL         Echo NL
// NOFLSH         Disable flushing of input buffers after interrupt or quit characters
// IEXTEN         Enable extended functions
// ECHOCTL         Echo control characters as ^char and delete as ~?
// ECHOPRT         Echo erased character as character erased
// ECHOKE         BS - SP - BS entire line on line kill
// FLUSHO         Output being flushed
// PENDIN         Retype pending input at next read or input char
// TOSTOP         Send SIGTTOU for background output
// 
// c_iflag用于设置如何处理串口上接收到的数据，包含如下内容：
// INPCK         Enable parity check
// IGNPAR         Ignore parity errors
// PARMRK      Mark parity errors
// ISTRIP         Strip parity bits
// IXON         Enable software flow control(outgoing)
// IXOFF         Enable software flow control(incoming)
// IXANY         Allow any character to start flow again
// IGNBRK         Ignore break condition
// BRKINT         Send a SIGINT when a break condition is detected
// INLCR         Map NL to CR
// IGNCR         Ignore CR
// ICRNL         Map CR to NL
// IUCLC         Map uppercase to lowercase
// IMAXBEL      Echo BEL on input line too long
// 
// c_oflag用于设置如何处理输出数据，包含如下内容：
// OPOST         Postprocess output(not set = raw output)
// OLCUC         Map lowercase to uppercase
// ONLCR         Map NL to CR - NL
// OCRNL         Map CR to NL
// NOCR         No CR output at column 0
// ONLRET      NL performs CR function
// OFILL         Use fill characters for delay
// OFDEL         Fill character is DEL
// NLDLY         Mask for delay time needed between lines
// NL0            No delay for NLs
// NL1            Delay further output after newline for 100 milliseconds
// CRDLY      Mask for delay time needed to return carriage to left column
// CR0            No delay for CRs
// CR1            Delay after CRs depending on current column position
// CR2            Delay 100 milliseconds after sending CRs
// CR3            Delay 150 milliseconds after sending CRs
// TABDLY      Mask for delay time needed after TABs
// TAB0            No delay for TABs
// TAB1         Delay after TABs depending on current column position
// TAB2         Delay 100 milliseconds after sending TABs
// TAB3         Expand TAB characters to spaces
// BSDLY      Mask for delay time needed after BSs
// BS0         No delay for BSs
// BS1         Delay 50 milliseconds after sending BSs
// VTDLY      Mask for delay time needed after VTs
// VT0         No delay for VTs
// VT1         Delay 2 seconds after sending VTs
// FFDLY      Mask for delay time needed after FFs
// FF0         No delay for FFs
// FF1         Delay 2 seconds after sending FFs
// 
// c_cc定义了控制字符，包含以下内容：
// VINTR  Interrupt  CTRL - C
// VQUIT  Quit    CTRL - Z
// VERASE   Erase    Backspace(BS)
// VKILL   Kill - line   CTRL - U
// VEOF   End - of - file   CTRL - D
// VEOL   End - of - line   Carriage return (CR)
// VEOL2   Second    end - of - line Line feed(LF)
// VMIN   Minimum number of characters to read
// VSTART   Start flow   CTRL - Q(XON)
// VSTOP   Stop flow   CTRL - S(XOFF)
// VTIME   Time to wait for data(tenths of seconds)