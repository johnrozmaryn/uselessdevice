if startpos < endpos
	for(pos = startpos; pos < endpos; pos += increment)
	{
		myservo.write(pos);
		delay(dTime);
	}
else if starpos > endpos
	for(pos = startpos; pos > endpos; pos -= increment)
	{
		myservo.write(pos);
		delay(dTime);
	}


void sweep(Servo serv, int startpos, int endpos, int increment, int dTime){
	if (startpos < endpos) {
		for(pos = startpos; pos < endpos; pos += increment)
		{
			myservo.write(pos);
			delay(dTime);
		}
	}
	else {
		for(pos = startpos; pos > endpos; pos -= increment)
		{
			myservo.write(pos);
			delay(dTime);
		}
	}
}