//
// Created by Roman on 02/08/2019.
//

#include "FunctionalTestRunner.h"
#include "TexturesTest.h"

FunctionalTestRunner::FunctionalTestRunner()
{
	_activeTest = new TexturesTest();
}

bool FunctionalTestRunner::Init()
{
	return _activeTest->Init();
}

void FunctionalTestRunner::Release()
{
	_activeTest->Release();
}

void FunctionalTestRunner::Draw()
{
	_activeTest->Draw();
}

