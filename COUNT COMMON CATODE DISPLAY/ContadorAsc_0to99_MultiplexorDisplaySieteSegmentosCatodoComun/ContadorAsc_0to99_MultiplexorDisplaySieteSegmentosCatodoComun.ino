//Sitio Web con Practicas de Arduino, FPGA, MATLAB y 
//temas sobre Electrónica Digital, Analogica, Procesamiento Digital de Señales, 
//Comunicaciones, etc.
//www.slideshare.net/FerMarcos2

//Sitio Web Curriculum
//www.linkedin.com/in/FerMarcos2

//Canal Youtube
//www.youtube.com/channel/UCLGgLo5SKhDz3cae4YOQosg

void setup(){
  DDRD=B11111111; //Digital Ports 7-1
  DDRB=B111111;}  //Digital Ports 13-8
void loop(){
  for(int count=0;count<100;count++){ //Count 0 to 99
    String scount=String(count);
    for(int repeat=0;repeat<map(analogRead(A0),0,1023,1,150);repeat++){ //Speed Control
      for(int i=0;i<scount.length();i++){
        switch(scount[i]){
          case '0':PORTD=B01111110;break;
          case '1':PORTD=B00001100;break;     
          case '2':PORTD=B10110110;break;     
          case '3':PORTD=B10011110;break;
          case '4':PORTD=B11001100;break;
          case '5':PORTD=B11011010;break;
          case '6':PORTD=B11111010;break;
          case '7':PORTD=B00001110;break;
          case '8':PORTD=B11111110;break;
          case '9':PORTD=B11011110;break;
        }  
        int n=pow(2,scount.length()-i-1)+.5;
        PORTB=B111111-byte(n);
        delay(5/scount.length());
        PORTB=B111111;
      }
    }
  }
}
