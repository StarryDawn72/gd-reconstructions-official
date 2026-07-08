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
/*
	====== PLAYEROBJECT::LIMITDASHROTATION ======
	
	Limits the dash angle in classic mode to ±70 degrees, preventing
	the player from shooting up into the world ceiling from a near-vertical
	dash ring.
	
*/
void PlayerObject::limitDashRotation(float& rotation)
{
	float limit = 70.0f;
    float offset = m_isSideways ? -90.0f : 0.0f;
    if (m_isGoingLeft) offset += 180.0f;

    if (offset != 0.0f) {
        rotation += offset;
        snapRotation360(rotation);
    }

    if (fabs(rotation) > 90.0f) {
        float baseRotation = (rotation <= 0.0f) ? -180.0f : 180.0f;
        rotation = baseRotation - rotation;
        snapRotation360(rotation);
    }

    if (rotation > limit)
		rotation = (rotation >= 180.0f) ? -limit : limit;
    else if (rotation < -limit)
		rotation = (rotation > -180.0f) ? -limit : limit;

    if (offset != 0.0f) {
        rotation -= offset;
        snapRotation360(rotation);
    }
}