/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2013 Charlie C.

    Contributor(s): Thomas Trocha(dertom)
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
#ifndef _gkSkeleton_h_
#define _gkSkeleton_h_

#include "gkGameObject.h"
#include "gkSerialize.h"


class gkSkeleton : public gkGameObject
{
public:
	gkSkeleton(gkInstancedManager* creator, const gkResourceName& name, const gkResourceHandle& handle);
	virtual ~gkSkeleton();

	void                 _setInternalSkeleton(gkSkeletonResource* skr);


	gkEntity*            getController(void)        {return m_controller;}
	void                 setController(gkEntity* v) {m_controller = v;}
	void                 updateFromController(void);


	gkSkeletonResource*  getInternalSkeleton(void) {return m_resource;}


	gkBone*              getBone(const gkHashedString& name);

	// attach a gameobject to the specified bone with optional transformation
	void attachObjectToBone(gkString boneName,gkGameObject* gobj,gkTransformState* transform=0);
	// attach a gameobject inplace to a specified bone
	void attachObjectToBoneInPlace(gkString boneName,gkGameObject* gobj);

protected:

	gkGameObject* clone(const gkString& name);


	gkSkeletonResource*  m_resource;
	gkEntity*            m_controller;

	virtual void createInstanceImpl(void);
	virtual void destroyInstanceImpl(void);
};


#endif//_gkSkeleton_h_
