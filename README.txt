This program interprets commands send through UART from comuter to arduino nano microcontroller 
and flashes 5 leds connected to pins D2-D6 accordingly

Commands:
HELLO - writes response in serial monitor
LED X Y - sets state Y of LED number X, 0<=X<5, Y = 0 || Y = 1
PATTERN X Y - sets pattern number Y to LED number X, 0<=X<5, 0<=Y<=5
TEST X - executes preprogrammed test number X, 0<=X<=2