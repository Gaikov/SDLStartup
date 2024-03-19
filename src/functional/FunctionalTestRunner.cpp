//
// Created by Roman on 02/08/2019.
//

#include "FunctionalTestRunner.h"
#include "TexturesTest.h"
#include "VertexColorTest.h"

FunctionalTestRunner::FunctionalTestRunner()
{
	//_activeTest = new TexturesTest();
	_activeTest = new VertexColorTest();
}

bool FunctionalTestRunner::Init()
{
	return _activeTest->Init();
}

void FunctionalTestRunner::Release()
{
	_activeTest->Release();
	delete _activeTest;
}

void FunctionalTestRunner::Update(float deltaTime)
{
    _activeTest->Update(deltaTime);
}

