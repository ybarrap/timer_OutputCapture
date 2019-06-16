void setup() {

  Serial.begin(115200);
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR2A = 0;
  TCCR2B = 0;
  OCR1A = 1; // 1 sec timer @ prescaler = 1024
  OCR1B = 1; // 1 sec timer @ prescaler = 1024
  OCR2A = 2; // 1 sec timer @ prescaler = 1024
//  OCR2B = 15624; // 1 sec timer @ prescaler = 1024
//  OCR2A = 46874; // 3 sec timer @ prescaler = 1024
  TCCR1B |= (1<< WGM12) | (1<<WGM13); // Set CTC mode with OCR1A as TOP value
  TCCR1A |= (1<<COM1A1) | (1<<COM1B1) |(1<<WGM11) ;
  TCCR1B |= (1 << CS10) ; // set prescaler @ 1024
  TCCR2A |= (1<< WGM21); // Set CTC mode with OCR1A as TOP value
//  TCCR2A |= 0x02;
//  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // set prescaler @ 1024
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // set prescaler @ 1024
//  TCCR2A |= (1<<COM2A0);
  TCCR2B &= ~(1 << WGM21);
//  TIMSK1 |= (1 << OCIE1A) | (1 << OCIE1B) ;
//  TCCR2A |= (1<<COM2A0); // Toggle OC2A on Compare Match
//  TIMSK2 |= (1 << OCIE2A);
  
  //TIMSK1 |= (1<<TOIE1); 
//  DDRB |= (1<<PB1) | (1<<PB2) | (1<<PB3);
//  PORTB |= (1<<PB1) | (1<<PB2) | (1<<PB3);

  DDRB |= (1<<PB1) | (1<<PB2);
  PORTB |= (1<<PB1) | (1<<PB2);

}

void loop() {
  ICR1 = map(analogRead(A0),0,1023,0,255);
  OCR1A = map(analogRead(A1),0,1023,0,ICR1);
}

ISR(TIMER1_OVF_vect) {
//  PORTB ^= (1<<1);
//  PORTB ^= (1 << 3);
//  TCNT1 = 3036;
}

// 3 sec

ISR(TIMER2_COMPA_vect) {

// Serial.println(millis());
//PORTB = (1<<3);
  
}

ISR(TIMER1_COMPA_vect) {
// PORTB &= ~(1<<1);
  
}

// 1 sec
ISR(TIMER1_COMPB_vect) {
//  PORTB ^= (1<<PB2);

  
  
}

