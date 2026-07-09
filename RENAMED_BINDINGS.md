Some nasty variables I had to rename. Found through extensive runtime analysis and reverse-engineering
---

**PlayerObject**:
- m_isOnGround -> canJump
- m_isOnGround2 -> onGround
- m_maybeChangedDirectionAngle -> lastPlatformerSlopeAngle
- m_platformerMovingRight -> slopeForceRight
- m_platformerMovingLeft -> slopeForceLeft
- m_collidingWithSlopeId -> lastSlopeID
- m_playEffects -> isInPlayLayer
- m_unkA99 -> isInDualMode
- m_ringJumpRelated -> ringJumpingThisTick
- m_padRingRelated -> canDisableAutoJump
- m_ringRelatedSet -> activatedRingIDs? (maybe something to do with J blocks as well)
- m_maybeIsBoosted -> isJumping (seen on-stream)
- m_isAccelerating -> isVelocityUncapped
- m_touchedGravityPortal -> touchedTeleportRing
- m_maybeReducedEffects -> isRespawning