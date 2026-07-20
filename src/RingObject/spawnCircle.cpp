#define PL GameManager::sharedState()->getPlayLayer()
/*
	====== RingObject::spawnCircle ======
	
	Spawns the expanding ripple effect when the player
	touches an orb, unless it's a player touch toggle block.
	
*/
void RingObject::spawnCircle()
{
	int playerTouchToggleBlockID = 3643;
	if ( PL && !m_hasNoEffects && m_objectID != playerTouchToggleBlockID )
	{
		float startRadius = 5.0f;
		float endRadius = 55.0f;
		float duration = 0.25f;
		bool fadeIn = false;

		auto circleEffect = CCCircleWave::create(startRadius, endRadius, duration, fadeIn);

		circleEffect->setPosition(getPosition());
		PL->m_objectLayer->addChild(circleEffect, 0);

		circleEffect->m_circleMode = CircleMode::Outline;
		circleEffect->followObject(this, false);
		circleEffect->m_delegate = PL;
		
		PL->addCircle(circleEffect);
	}
}