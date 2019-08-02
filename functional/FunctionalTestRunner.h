//
// Created by Roman on 02/08/2019.
//

#ifndef SDLTEST_FUNCTIONALTESTRUNNER_H
#define SDLTEST_FUNCTIONALTESTRUNNER_H

#include "IFunctionalTest.h"

class FunctionalTestRunner
{
public:
	FunctionalTestRunner();
	bool Init();
	void Release();
	void Draw();
private:
	IFunctionalTest *_activeTest;
};


#endif //SDLTEST_FUNCTIONALTESTRUNNER_H
