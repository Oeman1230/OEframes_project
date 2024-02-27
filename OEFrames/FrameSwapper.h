
#ifndef __FRAME_SWAPPER_H__
#define __FRAME_SWAPPER_H__

#include <exception>
#include <memory>

#include "OEWindow.h"
#include "OEFrameWrapper.h"
#include "OELabelWrapper.h"



class FrameSwapper
{
public:

	/*struct AllProperties
	{
		AllProperties(OEFrameWrapper::FrameProperties fProp = 0)

		OEFrameWrapper::FrameProperties frameProperties;
		OELabelWrapper::LabelProperties labelProperties;

	};*/

	FrameSwapper()
	{

	}
	~FrameSwapper()
	{
		_currentFrame.reset();
		_frameOne.reset();
		_frameTwo.reset();
	}

public:

	std::weak_ptr<OEFrame> getCurrentFrame() { return _currentFrame; }

	void setFirstFrame(std::weak_ptr<OEFrame> newFrame) { _frameOne = newFrame; }
	void setSecondFrame(std::weak_ptr<OEFrame> newFrame) { _frameTwo = newFrame; }

	void swap()
	{

		if (_frameNum == 0)
		{
			_currentFrame = _frameTwo;
			_frameNum = 1;
		}
		else
		{
			_currentFrame = _frameOne;
			_frameNum = 0;
		}
	}



	/*void setFrameOneProperties(AllProperties newProperties);
	void setFrameTwoProperties(AllProperties newProperties);
	AllProperties getFrameOneProperties() {};*/



private:

	short int _frameNum = 0;

	std::weak_ptr<OEFrame> _currentFrame;

	//AllProperties _frameOneProp;
	std::weak_ptr<OEFrame> _frameOne;

	//AllProperties _frameTwoProp;
	std::weak_ptr<OEFrame> _frameTwo;


};



#endif // !__FRAME_SWAPPER_H__

