void setup() {
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 <<CS12);
  TIMSK1 |= (1 << TOIE1);
  DDRB |= (1<<1);

}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_OVF_vect) {
  
  PORTB ^= (1<<1);
  
}

