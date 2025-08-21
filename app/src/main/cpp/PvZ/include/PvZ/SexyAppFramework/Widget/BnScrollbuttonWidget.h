#ifndef PVZ_SEXYAPPFRAMEWORK_WIDGET_BNSCROLLBUTTON_WIDGET_H
#define PVZ_SEXYAPPFRAMEWORK_WIDGET_BNSCROLLBUTTON_WIDGET_H

#include "ButtonWidget.h"

namespace Sexy {

class BnScrollbuttonWidget : public ButtonWidget {
public:
    bool mHorizontal;
    int mType;

public:
    BnScrollbuttonWidget(int theId, ButtonListener* theButtonListener) : BnScrollbuttonWidget(theId, theButtonListener, 0) {}
    BnScrollbuttonWidget(int theId, ButtonListener* theButtonListener, int theType) : ButtonWidget(theId, theButtonListener)
    {
        mHorizontal = false;
        mType = theType;
    }
    void Draw(Graphics *g);
    
};

}
#endif // PVZ_SEXYAPPFRAMEWORK_WIDGET_BNSCROLLBUTTON_WIDGET_H