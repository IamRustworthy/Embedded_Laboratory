// C++ code
//
unsigned int light = 0;
bool dir = 0;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  
  switch(light){
    case 1://red light
    	analogWrite(5, 0);
    	analogWrite(3, 192);
    	delay(5000);
    	dir = 1;
    	light = 2;
    break;
    
    case 2://orange light
    	analogWrite(3, 0);
    	analogWrite(6, 0);
    	analogWrite(5, 192);
    	delay(2000);
    
    	if(dir == 0){
          light = 1;
        }else{
          light = 3;
        }
    
    break;
    
    case 3://green light
    	analogWrite(5, 0);
    	analogWrite(6, 192);
    	delay(5000);
    	dir = 0;
    	light = 2;
    break;
    
    default:
    	light = 3;
    break;
  }
}