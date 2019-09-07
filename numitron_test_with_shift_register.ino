
const int latchPin = 8; //latch pin on shift register

const int clockPin = 12; //clock pin on shift register

const int dataPin = 11; //data pin on shift register

const int nums[10] = { //numbers array - from 0 to 9, BTW - (0b00000000 is blank as in 'turned off') according to docs: pin1 is common, pin2 is dot(unused), rest should be connected to shift registers one by one
  0b11110110, //0
  0b11000000, //1
  0b10101110, //2
  0b11101100, //3
  0b11011000, //4
  0b01111100, //5
  0b01111110, //6
  0b11100000, //7
  0b11111110, //8
  0b11111100 //9
};

int digit1count; //setting first counting number
int digit2count; //setting second counting number
int digit3count; //setting third counting number
int digit4count; //setting fourth counting number

void setup() { //setting outputs

  pinMode(latchPin, OUTPUT); //latch output to shift register
  pinMode(clockPin, OUTPUT); //clock output to shift register
  pinMode(dataPin, OUTPUT); //data output to shift register

}

void loop() { //main program body

  digit1count++; //mathematic operations so sketch is counting to 9999 and then resetting and starting from 0000. Simple addition

  if (digit1count >= 10) { //if number is greater or equal to 10
    digit1count = 0; //then it is set as zero
    digit2count++; //and 1 is added to the next number displayed on next numitron
  }

  if (digit2count >= 10) { //if number is greater or equal to 10
    digit2count = 0; //then it is set as zero
    digit3count++; //and 1 is added to the next number displayed on next numitron
  }

  if (digit3count >= 10) { //if number is greater or equal to 10
    digit3count = 0; //then it is set as zero
    digit4count++; //and 1 is added to the next number displayed on next numitron
  }

  if (digit4count >= 10) { //if number is greater or equal to 10
    digit4count = 0; //then it is set as zero
  }

  digitalWrite(latchPin, LOW); // setting latch low and awaiting data

  
  shiftOut(dataPin, clockPin, MSBFIRST, nums[digit4count]); // shift out the bits (MSBFIRST = most significant bit first)
  shiftOut(dataPin, clockPin, MSBFIRST, nums[digit3count]);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[digit2count]);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[digit1count]);

  digitalWrite(latchPin, HIGH); //send everything

  delay(200); //setting speed
}
