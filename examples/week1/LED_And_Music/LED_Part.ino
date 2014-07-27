
/* Analog and Digital Input and Output Server for MATLAB     */
/* Giampiero Campa, Copyright 2013 The MathWorks, Inc        */

/* This file is meant to be used with the MATLAB arduino IO 
   package, however, it can be used from the IDE environment
   (or any other serial terminal) by typing commands like:
   
   0e0 : assigns digital pin #4 (e) as input
   0f1 : assigns digital pin #5 (f) as output
   0n1 : assigns digital pin #13 (n) as output   
   
   1c  : reads digital pin #2 (c) 
   1e  : reads digital pin #4 (e) 
   2n0 : sets digital pin #13 (n) low
   2n1 : sets digital pin #13 (n) high
   2f1 : sets digital pin #5 (f) high
   2f0 : sets digital pin #5 (f) low
   4j2 : sets digital pin #9 (j) to  50=ascii(2) over 255
   4jz : sets digital pin #9 (j) to 122=ascii(z) over 255
   3a  : reads analog pin #0 (a) 
   3f  : reads analog pin #5 (f) 

   R0    : sets analog reference to DEFAULT
   R1    : sets analog reference to INTERNAL
   R2    : sets analog reference to EXTERNAL
  
   X3    : roundtrip example case returning the input (ascii(3)) 
   99    : returns script type (0 adio.pde ... 3 motor.pde ) */
   
/* define internal for the MEGA as 1.1V (as as for the 328)  */
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define INTERNAL INTERNAL1V1
#endif
int pin[] = {2,3,4,5,6,7,8,9,10,11,12,13}; //12個
int sec[] ={687,956,1260,1535,1817,2082,2387,2570,2675,2821,2959,3223,3514,3820,4096,4368,4573,4683,4941,5240,5526,5815,6118,6408,6667,6865,6959,7227,7392,7559,7794,8085,8390,8677,8962,9143,9231,9539,9825,10090}; 
 int count=0;
int buttonpin=A0;
int analogvalue=0;
void setup() {
  /* initialize serial                                       */
  Serial.begin(115200);
   for (int i = 0;i<12;i++ )
  {
  pinMode(pin[i],OUTPUT);
  } 
}


void loop() {
  analogvalue = analogRead(buttonpin);
  /* variables declaration and initialization                */
  static int  s   = -1;    /* state                          */
  static int  pin1 = 13;    /* generic pin number             */
 
  int  val =  0;           /* generic value read from serial */
  int  agv =  0;           /* generic analog value           */
  int  dgv =  0;           /* generic digital value          */


  /* The following instruction constantly checks if anything 
     is available on the serial port. Nothing gets executed in
     the loop if nothing is available to be read, but as soon 
     as anything becomes available, then the part coded after 
     the if statement (that is the real stuff) gets executed */

  if (Serial.available() >0) {

    /* whatever is available from the serial is read here    */
    val = Serial.read();
    
    /* This part basically implements a state machine that 
       reads the serial port and makes just one transition 
       to a new state, depending on both the previous state 
       and the command that is read from the serial port. 
       Some commands need additional inputs from the serial 
       port, so they need 2 or 3 state transitions (each one
       happening as soon as anything new is available from 
       the serial port) to be fully executed. After a command 
       is fully executed the state returns to its initial 
       value s=-1                                            */

    switch (s) {

      /* s=-1 means NOTHING RECEIVED YET ******************* */
      case -1:      

      /* calculate next state                                */
      if (val>47 && val<90) {
	  /* the first received value indicates the mode       
           49 is ascii for 1, ... 90 is ascii for Z          
           s=0 is change-pin mode;
           s=10 is DI;  s=20 is DO;  s=30 is AI;  s=40 is AO; 
           s=90 is query script type (1 basic, 2 motor);
           s=340 is change analog reference;
           s=400 example echo returning the input argument;
                                                             */
        s=10*(val-48);
      }
      
      /* the following statements are needed to handle 
         unexpected first values coming from the serial (if 
         the value is unrecognized then it defaults to s=-1) */
      if ((s>40 && s<90) || (s>90 && s!=340 && s!=400)) {
        s=-1;
      }

      /* the break statements gets out of the switch-case, so
      /* we go back and wait for new serial data             */
      break; /* s=-1 (initial state) taken care of           */


     
      /* s=0 or 1 means CHANGE PIN MODE                      */
      
      case 0:
      /* the second received value indicates the pin 
         from abs('c')=99, pin 2, to abs('¦')=166, pin 69    */
      if (val>98 && val<167) {
        pin1=val-97;                /* calculate pin          */
        s=1; /* next we will need to get 0 or 1 from serial  */
      } 
      else {
        s=-1; /* if value is not a pin then return to -1     */
      }
      break; /* s=0 taken care of                            */


      case 1:
      /* the third received value indicates the value 0 or 1 */
      if (val>47 && val<50) {
        /* set pin mode                                      */
        if (val==48) {
          pinMode(pin1,INPUT);
        }
        else {
          pinMode(pin1,OUTPUT);
        }
      }
      s=-1;  /* we are done with CHANGE PIN so go to -1      */
      break; /* s=1 taken care of                            */
      


      /* s=10 means DIGITAL INPUT ************************** */
      
      case 10:
      /* the second received value indicates the pin 
         from abs('c')=99, pin 2, to abs('¦')=166, pin 69    */
      if (val>98 && val<167) {
        pin1=val-97;                /* calculate pin          */
        dgv=digitalRead(pin1);      /* perform Digital Input  */
        Serial.println(dgv);       /* send value via serial  */
      }
      s=-1;  /* we are done with DI so next state is -1      */
      break; /* s=10 taken care of                           */

      

      /* s=20 or 21 means DIGITAL OUTPUT ******************* */
      
      case 20:
      /* the second received value indicates the pin 
         from abs('c')=99, pin 2, to abs('¦')=166, pin 69    */
      if (val>98 && val<167) {
        pin1=val-97;                /* calculate pin          */
        s=21; /* next we will need to get 0 or 1 from serial */
      } 
      else {
        s=-1; /* if value is not a pin then return to -1     */
      }
      break; /* s=20 taken care of                           */

      case 21:
      /* the third received value indicates the value 0 or 1 */
      if (val>47 && val<50) {
        dgv=val-48;                /* calculate value        */
	digitalWrite(pin1,dgv);     /* perform Digital Output */
      }
      s=-1;  /* we are done with DO so next state is -1      */
      break; /* s=21 taken care of                           */


	
      /* s=30 means ANALOG INPUT *************************** */
      
      case 30:
      /* the second received value indicates the pin 
         from abs('a')=97, pin 0, to abs('p')=112, pin 15    */
      if (val>96 && val<113) {
        pin1=val-97;                /* calculate pin          */
        agv=analogRead(pin1);       /* perform Analog Input   */
        Serial.println(millis());
	Serial.println(agv);       /* send value via serial  */
        
      }
       digitalWrite(pin[9],LOW); //layer1
  digitalWrite(pin[10],HIGH); //layer2
  digitalWrite(pin[11],HIGH); //layer3
  
 delay(150);
  delay(sec[count]);
  
  for (int i =0;i< 9 ;i++)
  {
    count = count + 1;
    digitalWrite( pin[i],HIGH );
    delay(50);
    digitalWrite(pin[10],LOW); //layer2
    delay(50);
    digitalWrite(pin[11],LOW); //layer2
    delay(sec[count]-sec[count-1]-100);
    digitalWrite(pin[i],LOW);
    
  digitalWrite(pin[9],LOW); //layer1
  digitalWrite(pin[10],HIGH); //layer2
  digitalWrite(pin[11],HIGH); //layer3
  }
  
 // digitalWrite(pin[9],HIGH); //layer1
  //digitalWrite(pin[10],LOW); //layer2
  //digitalWrite(pin[11],HIGH); //layer3
  
  
    for (int i =0;i< 3 ;i++)
  {
    
    count = count+1;
    digitalWrite(pin[9],LOW); //layer1
    digitalWrite(pin[10],HIGH); //layer2
    digitalWrite(pin[11],HIGH); //layer3
    for (int j=0;j<9;j++){
      digitalWrite(pin[j],HIGH);
    }
    
    delay(sec[count]-sec[count-1]);
    
    for (int j=0;j<9;j++){
      digitalWrite(pin[j],LOW);
    }
    /////////////////////////////////////
        count = count+1;
    digitalWrite(pin[9],HIGH); //layer1
    digitalWrite(pin[10],LOW); //layer2
    digitalWrite(pin[11],HIGH); //layer3
    for (int j=0;j<9;j++){
      digitalWrite(pin[j],HIGH);
    }
    
    delay(sec[count]-sec[count-1]);
    
    for (int j=0;j<9;j++){
      digitalWrite(pin[j],LOW);
    }
    //////////////////////////////////
    
           count = count+1;
    digitalWrite(pin[9],HIGH); //layer1
    digitalWrite(pin[10],HIGH); //layer2
    digitalWrite(pin[11],LOW); //layer3
    for (int j=0;j<9;j++){
      digitalWrite(pin[j],HIGH);
    }
    
    delay(sec[count]-sec[count-1]);
    
    for (int j=0;j<9;j++){
      digitalWrite(pin[j],LOW);
    }
  }
    digitalWrite(pin[9],LOW); //layer1
    digitalWrite(pin[10],HIGH); //layer2
    digitalWrite(pin[11],HIGH); //layer3
  //digitalWrite(pin[9],HIGH); //layer1
  //digitalWrite(pin[10],HIGH); //layer2
  //digitalWrite(pin[11],LOW); //layer3
  
  
    for (int i =0;i< 9 ;i++)
  {
    count = count+1;
    digitalWrite(pin[i],HIGH);
    delay(sec[count]-sec[count-1]);
    digitalWrite(pin[i],LOW);
    
  }
  
  digitalWrite(pin[9],HIGH); //layer1
  digitalWrite(pin[10],LOW); //layer2
  digitalWrite(pin[11],HIGH); //layer3
 // delay(sec[count]);
  
  
    for (int i =0;i< 9 ;i++)
  {
    count = count+1;
    digitalWrite(pin[i],HIGH);
    delay(sec[count]-sec[count-1]);
    digitalWrite(pin[i],LOW);
    
  }
  
  digitalWrite(pin[9],HIGH); //layer1
  digitalWrite(pin[10],HIGH); //layer2
  digitalWrite(pin[11],LOW); //layer3
 // delay(sec[count]);
  
  
    for (int i =0;i<3 ;i++)
  {
    count = count+1;
    digitalWrite(pin[i],HIGH);
    delay(sec[count]-sec[count-1]);
    digitalWrite(pin[i],LOW);
    
  }
      s=-1;  /* we are done with AI so next state is -1      */
      //////
      break; /* s=30 taken care of                           */



      /* s=40 or 41 means ANALOG OUTPUT ******************** */
      
      case 40:
      /* the second received value indicates the pin 
         from abs('c')=99, pin 2, to abs('¦')=166, pin 69    */
      if (val>98 && val<167) {
        pin1=val-97;                /* calculate pin          */
        s=41; /* next we will need to get value from serial  */
      }
      else {
        s=-1; /* if value is not a pin then return to -1     */
      }
      break; /* s=40 taken care of                           */


      case 41:
      /* the third received value indicates the analog value */
      analogWrite(pin1,val);        /* perform Analog Output  */
      s=-1;  /* we are done with AO so next state is -1      */
      break; /* s=41 taken care of                           */
      
      
      
      /* s=90 means Query Script Type: 
         (0 adio, 1 adioenc, 2 adiosrv, 3 motor)             */
      
      case 90:
      if (val==57) { 
        /* if string sent is 99  send script type via serial */
        Serial.println(0);
      }
      s=-1;  /* we are done with this so next state is -1    */
      break; /* s=90 taken care of                           */



      /* s=340 or 341 means ANALOG REFERENCE *************** */
      
      case 340:
      /* the second received value indicates the reference,
         which is encoded as is 0,1,2 for DEFAULT, INTERNAL  
         and EXTERNAL, respectively. Note that this function 
         is ignored for boards not featuring AVR or PIC32    */
         
#if defined(__AVR__) || defined(__PIC32MX__)

      switch (val) {
        
        case 48:
        analogReference(DEFAULT);
        break;        
        
        case 49:
        analogReference(INTERNAL);
        break;        
                
        case 50:
        analogReference(EXTERNAL);
        break;        
        
        default:                 /* unrecognized, no action  */
        break;
      } 

#endif

      s=-1;  /* we are done with this so next state is -1    */
      break; /* s=341 taken care of                          */



      /* s=400 roundtrip example function (returns the input)*/
      
      case 400:
      /* the second value (val) can really be anything here  */
      
      /* This is an auxiliary function that returns the ASCII 
         value of its first argument. It is provided as an 
         example for people that want to add their own code  */
         
      /* your own code goes here instead of the serial print */
      Serial.println(val);

      s=-1;  /* we are done with the aux function so -1      */
      break; /* s=400 taken care of                          */



      /* ******* UNRECOGNIZED STATE, go back to s=-1 ******* */
      
      default:
      /* we should never get here but if we do it means we 
         are in an unexpected state so whatever is the second 
         received value we get out of here and back to s=-1  */
      
      s=-1;  /* go back to the initial state, break unneeded */



    } /* end switch on state s                               */
       
 
    
  } /* end if serial available    */
  

  
  
} /* end loop statement                                      */

