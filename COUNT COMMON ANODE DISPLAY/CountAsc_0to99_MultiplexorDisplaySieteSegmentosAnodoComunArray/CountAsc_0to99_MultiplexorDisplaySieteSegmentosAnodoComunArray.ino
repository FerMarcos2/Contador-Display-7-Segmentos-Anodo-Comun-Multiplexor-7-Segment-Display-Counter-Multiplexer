//Sitio Web con Practicas de Arduino, FPGA, MATLAB y 
//temas sobre Electrónica Digital, Analogica, Procesamiento Digital de Señales, 
//Comunicaciones, etc.
//www.slideshare.net/FerMarcos2

//Sitio Web Curriculum
//www.linkedin.com/in/FerMarcos2

//Canal Youtube
//www.youtube.com/channel/UCLGgLo5SKhDz3cae4YOQosg

char num[]={0x81,0xF3,0x49,0x61,0x33,0x25,0x05,0xF1,0x01,0x21};
String snum="";
void setup(){
  DDRD=B11111111; //Digital Ports 7-1  OUTPUT
  DDRB=B111111;}  //Digital Ports 13-8 OUTPUT
void loop(){
  for(int count=0;count<100;count++){ //Count 0 to 99
    String scount=String(count);
    for(int repeat=0;repeat<100;repeat++){ //Speed COntrol WithOut Analog Read
      for(int i=0;i<scount.length();i++){
        snum=scount[i];
        PORTD=num[snum.toInt()];  
        int n=pow(2,scount.length()-i-1)+.5;
        PORTB=byte(n);
        delay(5/scount.length());
        PORTB=B000000;
      }
    }
  }
}
