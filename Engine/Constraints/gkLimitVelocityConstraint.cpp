/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2013 Charlie C.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#include "gkLimitVelocityConstraint.h"
#include "gkGameObject.h"
#include "btBulletDynamicsCommon.h"





gkLimitVelocityConstraint::gkLimitVelocityConstraint()
	:   gkConstraint(),
	    m_lim(0.f, 0.f)
{
}


gkConstraint* gkLimitVelocityConstraint::clone(gkGameObject* clob)
{
	gkLimitVelocityConstraint* cl = new gkLimitVelocityConstraint(*this);
	cl->setObject(clob);
	return cl;
}



bool gkLimitVelocityConstraint::update(gkScalar delta)
{
	if (!m_object) return false;


	const gkVector3& vel = m_object->getLinearVelocity();
	const gkScalar len = vel.length();


	if (m_lim.y > 0.f && len > m_lim.y)
		m_object->setLinearVelocity((vel * (m_lim.y / len)) *m_influence, TRANSFORM_WORLD);
	else if (m_lim.x > 0.f && !gkFuzzy(len) && len < m_lim.x)
		m_object->setLinearVelocity((vel * (m_lim.x / len)) * m_influence, TRANSFORM_WORLD);

	return false;
}
