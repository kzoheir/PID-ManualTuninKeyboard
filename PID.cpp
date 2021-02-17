First- **PID.h**: Remove private at line 34, so that main can change those values: 
```
// private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
```

Second- **main.cpp**
Line 8: Add the following includes:
```
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
```
Line 37 (after adding the above lines): Add the following functions: Before main()
```
void changemode(int);
int    kbhit(void);

void changemode(int dir)
{
  static struct termios oldt, newt;
 
  if ( dir == 1 )
  {
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  }
  else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
 
int kbhit (void)
{
  struct timeval tv;
  fd_set rdfs;
 
  tv.tv_sec = 0;
  tv.tv_usec = 0;
 
  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);
 
  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);
 
}
```

Third. Near Line 111: Inside: h.onMessage:
```
        char ch; 
        changemode(1);
        if ( kbhit() )
        {
          ch = getchar();
            printf("%c\tFrom: P: %2.2f\tI: %f\tD:%2.2f", ch, pid.Kp , pid.Ki, pid.Kd);
            switch (ch){
                case 'T':
                    Twiddle = true; 
                    break;
                case 't':
                    twiddle = false;
                    break;
                case 'P':
                    pid.Kp += pid.Kp*0.1; // Or += 0.01; 
                    break;
                case 'p':
                    pid.Kp -= pid.Kp*0.1; // Or -= 0.01;
                    break;
                case 'I':
                    pid.Ki += pid.Ki*0.1; // Or += 0.001; 
                    break;
                case 'i':
                    pid.Ki -= pid.Ki*0.1; // Or -= 0.001; 
                    break;
                case 'D':
                    pid.Kd += pid.Kd*0.1; // Or += 0.1; 
                    break;
                case 'd':
                    pid.Kd -= pid.Kd*0.1; // Or -=0.1;
                    break;
            }
            printf("\tto: P: %2.2f\tI: %f\tD:%2.2f\n", pid.Kp , pid.Ki, pid.Kd);
        }
        
        changemode(0);
```

Forth: Modify the **cout** statements to better see the Ks
```
          // DEBUG
          std::cout << "CTE: " << cte << " Steering Value: " << steer_value 
                    << std::endl;
```
To:
```
          // DEBUG
          std::cout << "CTE: " << cte << " Steering Value: " << steer_value << " Kp: " << pid.Kp << " Ki: " << pid.Ki << " Kd: " << pid.Kd 
                    << std::endl;
```

You can modify the code to instead of incrementing or decrementing a specific value it increments or decrements certain %. This will get you closer to **TWIDDLE**. You can also comment the ```cout``` statements to focus on the parameters.
