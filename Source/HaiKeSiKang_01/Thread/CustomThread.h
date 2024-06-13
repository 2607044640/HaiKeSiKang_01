#pragma once

class CustomThread : FRunnable
{
public:
	CustomThread();
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Exit() override;
};
