
const int RCLKPin = 8;
// Pin connected to SRCLK -- shift register clock pin -- of 74HC595
const int SRCLKPin = 12;
// Pin connected to SER -- serial data input -- of 74HC595
const int SERPin = 11;

const int nums[10] = {
0b11110110, //0 -ok
0b11000000, //1 -ok
0b10101110, //2 -ok
0b11101100, //3 -ok
0b11011000, //4 -ok
0b01111100, //5 -ok
0b01111110, //6 -ok
0b11100000, //7 -ok
0b11111110, //8 -ok
0b11111100 //9 -ok
};

int dig1count;
int dig2count;
int dig3count;
int dig4count;

void setup() {

// set pins to output so you can control the shift register
pinMode(RCLKPin, OUTPUT);
pinMode(SRCLKPin, OUTPUT);
pinMode(SERPin, OUTPUT);

}

void loop() {

  dig1count++;

  if (dig1count >= 10) {
    dig1count = 0;
    dig2count++;
  }

  if (dig2count >= 10) {
    dig2count = 0;
    dig3count++;
  }
  
  if (dig3count >= 10) {
    dig3count = 0;
    dig4count++;
  }
  
  if (dig4count >= 10) {
    dig4count = 0;
  }
    
// set RCLK low; wait till we transmit the byte, and they moving it high will output the data
digitalWrite(RCLKPin, LOW);

// shift out the bits (MSBFIRST = most significant bit first)
shiftOut(SERPin, SRCLKPin, MSBFIRST, nums[dig4count]);
shiftOut(SERPin, SRCLKPin, MSBFIRST, nums[dig3count]);
shiftOut(SERPin, SRCLKPin, MSBFIRST, nums[dig2count]);
shiftOut(SERPin, SRCLKPin, MSBFIRST, nums[dig1count]);
/*
 = E
 = D
 = F
 = C
 = B
 = A
 = G
 = H
0 = 0b11110110
1 = 0b11000000
2 = 0b10101110
3 = 0b11101100
4 = 0b11011000
5 = 0b01111100
6 = 0b01111110
7 = 0b11100000
8 = 0b11111110
9 = 0b11111100
*/


// send shift register data to the storage register
digitalWrite(RCLKPin, HIGH);

// catch our breath before repeating
delay(1000);
}
