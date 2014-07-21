int row1 = 12;
int row2 = 11;
int row3 = 10;
int row4 = 9;
int row5 = 8;

int col1= 2;
int col2= 3;
int col3= 4;
int col4= 5;
int col5= 6;

int JoyStick_X = 0; //　搖桿x 
int JoyStick_Y = 1; //  搖桿y 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(row1, OUTPUT);     
  pinMode(row2, OUTPUT);    
  pinMode(row3, OUTPUT);     
  pinMode(row4, OUTPUT);  
  pinMode(row5, OUTPUT);
  
  pinMode(col1, OUTPUT);      
  pinMode(col2, OUTPUT);      
  pinMode(col3, OUTPUT);        
  pinMode(col4, OUTPUT);   
  pinMode(col5, OUTPUT);     
   
  pinMode(JoyStick_X, INPUT); //　搖桿X
  pinMode(JoyStick_Y, INPUT); //　搖桿Y   
  
  lightFood();
      
  Serial.begin(9600); // 9600 bps    
  
  
}

//int head[] = {1,2};
//int body[] = {1,1};
int snakeRowBody[] = {1,1,0,0,0,0,0,0,0,0};   //　the first of array is head
int snakeColBody[] = {2,1,0,0,0,0,0,0,0,0};   //　the first of array is head
int snakeLength = 2;

int food[] = {0,0};
void lightRow(int rowNum){
    switch(rowNum){
        case 1:
          digitalWrite(row1, HIGH);
          digitalWrite(row2, LOW);
          digitalWrite(row3, LOW);
          digitalWrite(row4, LOW);
          digitalWrite(row5, LOW);
        
          break;
        case 2:
          digitalWrite(row1, LOW);
          digitalWrite(row2, HIGH);
          digitalWrite(row3, LOW);
          digitalWrite(row4, LOW);
          digitalWrite(row5, LOW);
        
          break;
        case 3:
          digitalWrite(row1, LOW);
          digitalWrite(row2, LOW);
          digitalWrite(row3, HIGH);
          digitalWrite(row4, LOW);
          digitalWrite(row5, LOW);
        
          break;
        case 4:
          digitalWrite(row1, LOW);
          digitalWrite(row2, LOW);
          digitalWrite(row3, LOW);
          digitalWrite(row4, HIGH);
          digitalWrite(row5, LOW);
        
          break;
        case 5:
          digitalWrite(row1, LOW);
          digitalWrite(row2, LOW);
          digitalWrite(row3, LOW);
          digitalWrite(row4, LOW);
          digitalWrite(row5, HIGH);
        
          break;          
    }
}
void lightCol(int colNum){
    switch(colNum){
        case 1:
          digitalWrite(col1, LOW);
          digitalWrite(col2, HIGH);
          digitalWrite(col3, HIGH);
          digitalWrite(col4, HIGH);
          digitalWrite(col5, HIGH);
        
          break;
        case 2:
          digitalWrite(col1, HIGH);
          digitalWrite(col2, LOW);
          digitalWrite(col3, HIGH);
          digitalWrite(col4, HIGH);
          digitalWrite(col5, HIGH);
        
          break;
        case 3:
          digitalWrite(col1, HIGH);
          digitalWrite(col2, HIGH);
          digitalWrite(col3, LOW);
          digitalWrite(col4, HIGH);
          digitalWrite(col5, HIGH);
        
          break;
        case 4:
          digitalWrite(col1, HIGH);
          digitalWrite(col2, HIGH);
          digitalWrite(col3, HIGH);
          digitalWrite(col4, LOW);
          digitalWrite(col5, HIGH);
        
          break;
        case 5:
          digitalWrite(col1, HIGH);
          digitalWrite(col2, HIGH);
          digitalWrite(col3, HIGH);
          digitalWrite(col4, HIGH);
          digitalWrite(col5, LOW);        
          break;
    }
}
void lightSnake(){
        delay(20);        
        lightRow(snakeRowBody[0]);
        lightCol(snakeColBody[0]);
        delay(20);
        lightRow(snakeRowBody[1]);
        lightCol(snakeColBody[1]);
        delay(20);
        lightRow(food[0]);
        lightCol(food[1]);        
}
void lightFood(){
  food[0]  = random(1,5);
  food[1]  = random(1,5);  
  int i=1;
  

  while(i<=snakeLength){          
      while(food[0]==snakeRowBody[i]&&food[1]==snakeColBody[i]){
            
        food[0]  = random(1,5);
        food[1]  = random(1,5);  
        i=0;
      }
      i++;          
  }         
   
  
  
  lightRow(food[0]);
  lightCol(food[0]);
      
  delay(5);        
}
int x,y,z; 
int foodHaveEat=false;
int currSnakeDirction=6;   //2 down  8 up   6 right   4 left. default is right
boolean isSnakeEatFood(){
	if(food[0] == snakeRowBody[0] && food[1] == snakeColBody[0]){
		lightFood();
		return true;
	}else{
		return false;
	}	

}
void addSnakeBody(){
    

}
int collisionWall = 0;   // if collisionWall==2 then Game Over.
void judgeDirection(){
  x=analogRead(JoyStick_X); 
  y=analogRead(JoyStick_Y); 
  Serial.print(x ,DEC); 
  Serial.print(","); 
  Serial.print(y ,DEC); 
  Serial.print(","); 
  Serial.println(z ,DEC); 

  //right
  if(x>450 && x< 550 && y > 550){
      Serial.println("right");
      currSnakeDirction = 6;
  }
  //left
  if(x>450 && x< 550 && y < 500){
      Serial.println("left");
      currSnakeDirction = 4;
  }
  //up
  if(y>450 && y< 550 && x > 550){
      Serial.println("up");
	  currSnakeDirction = 8;
      
  }  
  //down
  if(y>450 && y< 550 && x < 500){
      Serial.println("down");
	  currSnakeDirction = 2;
  }    
}

long previousTime = 0;          // 用來保存前一次 LED 更新狀態的時間
long interval = 500;           // 燈號閃爍間隔時間&#65292;單位為毫秒(miliseconds)

void loop() { 
  if(collisionWall==2){
    digitalWrite(row1, HIGH);
	digitalWrite(row2, HIGH);
	digitalWrite(row3, HIGH);
	digitalWrite(row4, HIGH);
	digitalWrite(row5, HIGH);
	digitalWrite(col1, LOW);
	digitalWrite(col2, LOW);
	digitalWrite(col3, LOW);
	digitalWrite(col4, LOW);
	digitalWrite(col5, LOW);
  }else{

//      	delay(1000);     
  	unsigned long currentTime = millis();
 
  // 檢查是否已超過間隔時間
  // 是的話&#65292;就切換燈號並且記錄更新時間
  	if(currentTime - previousTime > interval) {    
 	  collisionWall++;   // if collisionWall==2 then Game Over.
      // 　讓蛇前進
      switch(currSnakeDirction){       // default is right
		case 6:  //6 right
		if(snakeColBody[0]+1 < 6 ){
          snakeRowBody[1] = snakeRowBody[0];
          snakeColBody[1] = snakeColBody[0];
          snakeColBody[0] = snakeColBody[0]+1;
          isSnakeEatFood();
          lightSnake();   
  		  collisionWall = 0; //reset
      	}	
		break;
		case 4:  //4 left
      	if(snakeColBody[0]-1 > 0){
          snakeRowBody[1] = snakeRowBody[0];
          snakeColBody[1] = snakeColBody[0];        
          snakeColBody[0] = snakeColBody[0]-1;
          isSnakeEatFood();
          lightSnake();      
          collisionWall = 0; //reset
      	}	 
      
		break;
		case 8:  //8 up
      	if(snakeRowBody[0]-1 > 0){
          snakeRowBody[1] = snakeRowBody[0];
          snakeColBody[1] = snakeColBody[0];        
          snakeRowBody[0] = snakeRowBody[0]-1;
          isSnakeEatFood();
          lightSnake();      
          collisionWall = 0; //reset
     	 }
      
		 break;
		case 2:  //2 down

      	if(snakeRowBody[0]+1 < 6){
          snakeRowBody[1] = snakeRowBody[0];
          snakeColBody[1] = snakeColBody[0];        
          snakeRowBody[0] = snakeRowBody[0]+1;
          isSnakeEatFood();
          lightSnake();      
          collisionWall = 0; //reset
      	 } 

		 break;	

      	}


      // 記錄更新時間
      previousTime = currentTime;        
    }

    // 你可以在這裏做其它事情
    judgeDirection();

  }  
    
}
