// Here you will find a list of free functions
// RobTop used that don't belong to any class.


/*
	====== SNAPROTATION360 (FREE FUNCTION) ======
	
	Normalizes the given rotation to a -180 to 180 degree
	range. It's used exclusively in limitDashRotation and
	startDashing for dash ring mechanics.
	
*/
void snapRotation360(float& rotation)
{
	if (rotation <= 180.0f) {
		if (rotation < -180.0f) {
			rotation += 360.0f;
		}
	}
	else {
		rotation -= 360.0f;
	}
}