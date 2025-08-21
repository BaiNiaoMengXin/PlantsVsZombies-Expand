/*
 * Copyright (C) 2023-2025  PvZ TV Touch Team
 *
 * This file is part of PlantsVsZombies-AndroidTV.
 *
 * PlantsVsZombies-AndroidTV is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * PlantsVsZombies-AndroidTV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * PlantsVsZombies-AndroidTV.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef PVZ_SEXYAPPFRAMEWORK_WIDGET_BNSCROLLBAR_WIDGET_H
#define PVZ_SEXYAPPFRAMEWORK_WIDGET_BNSCROLLBAR_WIDGET_H

#include "PvZ/Symbols.h"

#include "BnScrollbuttonWidget.h"
#include "BnScrollListener.h"
#include "Widget.h"
#include "ButtonListener.h"

namespace Sexy {

class BnScrollbarWidget : public __Widget, ButtonListener {
private:
const int gScrollbarWidgetWidgetColors[6][3] = {
    {232, 232, 232},
    {48, 48, 48},
    {212, 212, 212},
    {0, 0, 0},
    {132, 132, 132},
    {255, 255, 255}
};

        
    enum  
    {
        UPDATE_MODE_IDLE,
        UPDATE_MODE_PGUP,
        UPDATE_MODE_PGDN
    };

    enum ScrollbarColors
    {
        Bar,
        BarPaging,
        Thumb,
        DarkOutline,
        MediumOutline,
        LightOutline,
        NUM_COLORS
    };
public:
    BnScrollbuttonWidget *mUpButton;      // 65
    BnScrollbuttonWidget *mDownButton;    // 66
    bool mInvisIfNoScroll;  // 268
    int mId;                // 68
    double mValue;          // 69 ~ 70
    double mMaxValue;       // 71 ~ 72
    double mPageSize;       // 73 ~ 74
    bool mHorizontal;       // 300
    int mButtonLength;      // 76
    bool mPressedOnThumb;   // 77
    int mMouseDownThumbPos; // 78
    int mMouseDownX;        // 79
    int mMouseDownY;        // 80
    int mUpdateMode;        // 81
    int mUpdateAcc;         // 82
    int mButtonAcc;         // 83
    int mLastMouseX;        // 84
    int mLastMouseY;        // 85
    BnScrollListener *mScrollListener;   // 86
    Image *mThumbImage;     // 87
    Image *mBarImage;       // 88
    Image *mPagingImage;    // 89
    // 大小90个整数
public:
    BnScrollbarWidget(int theId, BnScrollListener *theScrollListener);
    ~BnScrollbarWidget();
    void SetInvisIfNoScroll(bool invisIfNoScroll);
    void SetMaxValue(double theNewMaxValue);
    void SetPageSize(double theNewPageSize);
    void SetValue(double theNewValue);
    void SetHorizontal(bool isHorizontal);
    void SetButtonImages(Image* button, Image *down);
    void SetButtonImages(Image *button, Image *down, Image *disabled);
    void SetThumbImage(Image *img);
    void SetBarImages(Image *theBarImage);
    void SetBarImages(Image *theBarImage, Image *thePagingImage);
    void SetButtonColors(int theColors, int theNumColors);
    void SetButtonColor(int theIdx, Color &theColor);
    void ResizeScrollbarWidget(int theX, int theY, int theWidth, int theHeight);
    bool AtBottom();
    void GoToBottom();
    void DrawThumb(Graphics *g, int theX, int theY, int theWidth, int theHeight);
    void DrawThumb(Graphics *g, Rect &theRect);
    int GetTrackSize();
    int GetThumbSize();
    int GetThumbPosition();
    void Draw(Graphics *g);
    void ClampValue();
    void SetThumbPosition(int thePosition);
    void ButtonPress(int theId);
    void ButtonDepress(int theId);
    void ButtonDownTick(int theId);
    void Update();
    int ThumbCompare(int x, int y);
    void MouseDown(int x, int y, int theClickCount);
    void MouseDown(int x, int y, int theBtnNum, int theClickCount);
    void MouseUp(int x, int y, int theBtnNum, int theClickCount);
    void MouseDrag(int x, int y);
    void RemoveAllWidgets(bool doDelete, bool recursive);
    void ButtonPress(int theId, int theClickCount);
    void ButtonMouseEnter(int theId);
    void ButtonMouseLeave(int theId);
    void ButtonMouseMove(int theId, int theX, int theY);

};

} // namespace Sexy

#endif // PVZ_SEXYAPPFRAMEWORK_WIDGET_BNSCROLLBAR_WIDGET_H
