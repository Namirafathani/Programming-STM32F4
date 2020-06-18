# Programming-STM32F4
Programming STM32F407VG with LCD and displaying RTC DS1307.

But actually the RTC not display Date and Time accurately. In this program i have already try only display date or time.

i used ST Link V2 to uploading the program. Dont forget to change the mode bbot in DFU mode when programming and back it to normal mode if progras has finished to upload.

This is the wiring

# LCD to STM32F407VG

VSS --> GND,
VDD --> Vcc,
Vo  --> data Potensio,
RS  --> PB11 (pin lainnya bisa, asalkan pin tersebut dapat digunakan sebagai komunikasi I2C SDA),
RW  --> GND,
E   --> PB10 (pin lainnya pada STM32 bisa digunakan, asalkan pin tersebut mengandung fungsi komunikasi I2C SCL),
D4  --> PE3 (pin lainnya dapat digunakan untuk I/O pin),
D5  --> PE6 (pin lainnya dapat digunakan untuk I/O pin),
D6  --> PE4 (pin lainnya dapat digunakan untuk I/O pin),
D7  --> PE2 (pin lainnya dapat digunakan untuk I/O pin),
A   --> Resistor --> Vcc,
K   --> GND.

# DS1307 to STM32F4

Vcc --> Vcc,
GND --> GND,
SDA --> PB6 ( Pin lainnya pada STM32 bisa digunakan, asalkan pin tsb mengandung fungsi komunikasi I2C SDA),
SCL --> PB7 ( Pin lainnya pada STM32 bisa digunakan, asalkan pin tsb mengandung fungsi komunikasi I2C SCL).

# STM32F4 RTC without RTC module (using internal oscillator)
see the program "rtc_without_module.ino". Program dan osilasi rtc akan tetap berlangsung apabila kristal yang ada pada rangkaian STM32 tetap diberikan sumber tegangan. Apabila sumber hilang maka yang dapat terjadi ialah program rtc menghitung ke awal.
Apabila menginginkan RTC terus berjalan secara real time maka pasang batre eksternal pada rangkaian untuk men-suplai 
