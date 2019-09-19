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
