qqimport processing.serial.*; //importing serial lib
PImage winner3; //declaring 
Serial arduino;
int serialIn;
int val=0;

void setup()
{
  size(800,800,P2D);
  //fullScreen(P2D);
  printArray(Serial.list());
  arduino = new Serial(this,Serial.list()[1],115200);
  winner3= loadImage("winner3.png");
  imageMode(CENTER);
  winner3.resize(500,500);


  
}
void draw()
{
  background(0);
  image(winner3,width/2,height/2,val*20,val*20);
  
  
  if(arduino.available()>0)
  {
    serialIn=arduino.read();
    println(serialIn);
  }
  val=int(map(serialIn,80,50,10,0));
}
