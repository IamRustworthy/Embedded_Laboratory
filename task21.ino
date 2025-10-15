// C++ code
//
unsigned int light = 0;
bool dir = 0;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, INPUT_PULLUP);//Input with Pull up Resistor
  
}

void loop()
{   
  switch(light){
    case 1://red light
    	analogWrite(5, 0);
    	analogWrite(3, 192);
    	delay(5000);
    	dir = 1;//direction back
    	light = 2;//go to traffic yellow
    break;
    
    case 2://orange light
    	analogWrite(3, 0);
    	analogWrite(6, 0);
    	analogWrite(5, 192);
    
    	if(dir == 0){//if direction coming from traffic red
          light = 5;//go to pedestrian green
        }else{
          light = 4;//go to pedestrian red
        }
    
    break;
    
    case 3://green light
    	analogWrite(5, 0);
    	analogWrite(6, 192);
    	delay(5000);
    	dir = 0;
    	light = 0;//go to button
    break;
    
    case 4://ped red
    	analogWrite(9, 192);
    	analogWrite(10, 0);
    	delay(2000);
    	light = 3;//go to traffic green
    break;
    
    case 5://ped green
    	delay(2000);
    	analogWrite(9, 0);
    	analogWrite(10, 192);
    	light = 1;//go to traffic red
    break;
    
    default://is button pressed?
    	while(bool button = digitalRead(12) == true){
      		light = 2;
    	}
    break;
  
 }
}
