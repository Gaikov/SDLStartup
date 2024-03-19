//
// Created by Roman on 02/08/2019.
//

#ifndef SDLTEST_IFUNCTIONALTEST_H
#define SDLTEST_IFUNCTIONALTEST_H


class IFunctionalTest
{
public:
	virtual ~IFunctionalTest() = default;
	virtual bool Init() = 0;
	virtual void Release() = 0;
	virtual void Update(float deltaTime) = 0;
};


#endif //SDLTEST_IFUNCTIONALTEST_H
