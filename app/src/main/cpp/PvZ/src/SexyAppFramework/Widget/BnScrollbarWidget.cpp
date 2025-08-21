#include "PvZ/SexyAppFramework/Widget/BnScrollbarWidget.h"

using namespace Sexy;


BnScrollbarWidget::BnScrollbarWidget(int theId, BnScrollListener *theScrollListener)
{
    mId = theId;
    mScrollListener = theScrollListener;
    mDisabled = true;
    mUpButton = new BnScrollbuttonWidget(0, this);
    mUpButton->mDisabled = true;
    mDownButton = new BnScrollbuttonWidget(1, this);
    mDownButton->mDisabled = true;
    mInvisIfNoScroll = false;
    mPressedOnThumb = false;
    mValue = 0.0;
    mMaxValue = 0.0;
    mPageSize = 0.0;
    mUpdateAcc = 0;
    mButtonAcc = 0;
    mUpdateMode = 0;
    mHorizontal = false;
    mThumbImage = nullptr;
    mBarImage = nullptr;
    mPagingImage = nullptr;
    mButtonLength = 0;
    // AddWidget(mUpButton);
    // AddWidget(mDownButton);
    //SetColors(ScrollbarWidget.gScrollbarWidgetWidgetColors, 6);
}

BnScrollbarWidget::~BnScrollbarWidget()
{
    if (mUpButton != nullptr)
    {
        // RemoveWidget(mUpButton);
        delete mUpButton;
        mUpButton = nullptr;
    }
    if (mDownButton != nullptr)
    {
        // RemoveWidget(mDownButton);
        delete mDownButton;
        mDownButton = nullptr;
    }
}

void BnScrollbarWidget::SetInvisIfNoScroll(bool invisIfNoScroll)
{
    mInvisIfNoScroll = invisIfNoScroll;
    if (mInvisIfNoScroll)
    {
        mVisible = false;
        // mDownButton->mVisible = false;
        // mUpButton->mVisible = false;
    }
}

void BnScrollbarWidget::SetMaxValue(double theNewMaxValue)
{
    mMaxValue = theNewMaxValue;
    ClampValue();
    MarkDirty();
}

void BnScrollbarWidget::SetPageSize(double theNewPageSize)
{
    mPageSize = theNewPageSize;
    ClampValue();
    MarkDirty();
}

void BnScrollbarWidget::SetValue(double theNewValue)
{
    mValue = theNewValue;
    ClampValue();
    mScrollListener->ScrollPosition(mId, mValue);
    MarkDirty();
}

void BnScrollbarWidget::SetHorizontal(bool isHorizontal)
{
    mHorizontal = isHorizontal;
    // mDownButton->mHorizontal = mHorizontal;
    // mUpButton->mHorizontal = mHorizontal;
}

void BnScrollbarWidget::SetButtonImages(Image *button, Image *down)
{
    SetButtonImages(button, down, nullptr);
}

void BnScrollbarWidget::SetButtonImages(Image *button, Image *down, Image *disabled)
{
    // mUpButton->mButtonImage = button;
    // mUpButton->mDownImage = down;
    // mUpButton->mDisabledImage = disabled;
    // mDownButton->mButtonImage = button;
    // mDownButton->mDownImage = down;
    // mDownButton->mDisabledImage = disabled;
}

void BnScrollbarWidget::SetThumbImage(Image *img)
{
    mThumbImage = img;
}

void BnScrollbarWidget::SetBarImages(Image *theBarImage)
{
    SetBarImages(theBarImage, nullptr);
}

void BnScrollbarWidget::SetBarImages(Image *theBarImage, Image *thePagingImage)
{
    mBarImage = theBarImage;
    mPagingImage = thePagingImage;
}

void BnScrollbarWidget::SetButtonColors(int theColors, int theNumColors)
{
}

void BnScrollbarWidget::SetButtonColor(int theIdx, Color &theColor)
{
}

void BnScrollbarWidget::ResizeScrollbarWidget(int theX, int theY, int theWidth, int theHeight)
{
    Resize(theX, theY, theWidth, theHeight);
    int num;
    if (mHorizontal)
    {
        theY = (theX = 0);
        num = theHeight;
        if (mButtonLength > 0)
        {
            num = mButtonLength;
        }
        // mUpButton->Resize(theX, theY, num, theHeight);
        // mDownButton->Resize(theX + theWidth - num, theY, num, theHeight);
        return;
    }
    theY = (theX = 0);
    num = theWidth;
    if (mButtonLength > 0)
    {
        num = mButtonLength;
    }
    // mUpButton->Resize(theX, theY, theWidth, num);
    // mDownButton->Resize(theX, theY + theHeight - num, theWidth, num);
}

bool BnScrollbarWidget::AtBottom()
{
    return mMaxValue - mPageSize - mValue <= 1.0;
}

void BnScrollbarWidget::GoToBottom()
{
    mValue = mMaxValue - mPageSize;
    ClampValue();
    SetValue(mValue);
}

void BnScrollbarWidget::DrawThumb(Graphics *g, int theX, int theY, int theWidth, int theHeight)
{
    if (mThumbImage == nullptr || mThumbImage == NULL || !mThumbImage)
    {
        Color acolor = {125, 125, 125};
        g->SetColor(acolor);
        Rect aRect = {theX, theY, theWidth, theHeight};
        g->FillRect(aRect);
        // g->SetColor(GetColor(2));
        // g->FillRect(theX, theY, theWidth, theHeight);
        // g->SetColor(GetColor(5));
        // g->FillRect(theX + 1, theY + 1, theWidth - 2, 1);
        // g->FillRect(theX + 1, theY + 1, 1, theHeight - 2);
        // g->SetColor(GetColor(3));
        // g->FillRect(theX, theY + theHeight - 1, theWidth, 1);
        // g->FillRect(theX + theWidth - 1, theY, 1, theHeight);
        // g->SetColor(GetColor(4));
        // g->FillRect(theX + 1, theY + theHeight - 2, theWidth - 2, 1);
        // g->FillRect(theX + theWidth - 2, theY + 1, 1, theHeight - 2);
        return;
    }
    // Rect aRect = {theX, theY, theWidth, theHeight};
    // g->DrawImageBox(aRect, mThumbImage);
}

void BnScrollbarWidget::DrawThumb(Graphics *g, Rect &theRect)
{
    DrawThumb(g, theRect.mX, theRect.mY, theRect.mWidth, theRect.mHeight);
}

int BnScrollbarWidget::GetTrackSize()
{
    if (mButtonLength > 0)
    {
        if (mHorizontal)
        {
            return mWidth - 2 * mButtonLength;
        }
        return mHeight - 2 * mButtonLength;
    }
    else
    {
        if (mHorizontal)
        {
            // return mWidth - 2 * mUpButton->mWidth;
            return 0;
        }
        // return mHeight - 2 * mUpButton->mWidth;
        return 0;
    }
}

int BnScrollbarWidget::GetThumbSize()
{
    if (mPageSize > mMaxValue)
    {
        return 0;
    }
    int num = (int)(GetTrackSize() * mPageSize / mMaxValue + 0.5);
    return std::max(8, num);
}

int BnScrollbarWidget::GetThumbPosition()
{
    if (mPageSize > mMaxValue)
    {
        return 0;
    }
    return (int)(mValue * (GetTrackSize() - GetThumbSize()) / (mMaxValue - mPageSize) + 0.5);
}

void BnScrollbarWidget::Draw(Graphics *g)
{
/*    int thumbSize = GetThumbSize();
    int num;
    if (mHorizontal)
    {
        num = (mWidth - GetTrackSize()) / 2;
    }
    else
    {
        num = (mHeight - GetTrackSize()) / 2;
    }
    int thumbPosition = GetThumbPosition();
    TRect trect;
    TRect trect2;
    TRect theRect;
    if (mHorizontal)
    {
        trect = new TRect(num, 0, thumbPosition + thumbSize / 2, mHeight);
        trect2 = new TRect(thumbPosition + thumbSize / 2 + num, 0, GetTrackSize() - thumbPosition - thumbSize / 2, mHeight);
        theRect = new TRect(thumbPosition + num, 0, thumbSize, mHeight);
    }
    else
    {
        trect = new TRect(0, num, mWidth, thumbPosition + thumbSize / 2);
        trect2 = new TRect(0, thumbPosition + thumbSize / 2 + num, mWidth, GetTrackSize() - thumbPosition - thumbSize / 2);
        theRect = new TRect(0, thumbPosition + num, mWidth, thumbSize);
    }
    if (mUpdateMode == 1)
    {
        if (mPagingImage != null)
        {
            g.DrawImageBox(trect, mPagingImage);
        }
        else
        {
            g.SetColor(GetColor(1));
            g.FillRect(trect);
        }
    }
    else if (mBarImage != null)
    {
        g.DrawImageBox(trect, mBarImage);
    }
    else
    {
        g.SetColor(GetColor(0));
        g.FillRect(trect);
    }
    if (mUpdateMode == 2)
    {
        if (mPagingImage != null)
        {
            g.DrawImageBox(trect2, mPagingImage);
        }
        else
        {
            g.SetColor(GetColor(1));
            g.FillRect(trect2);
        }
    }
    else if (mBarImage != null)
    {
        g.DrawImageBox(trect2, mBarImage);
    }
    else
    {
        g.SetColor(GetColor(0));
        g.FillRect(trect2);
    }
    if (thumbSize > 0)
    {
        DrawThumb(g, theRect);
    }*/
}

void BnScrollbarWidget::ClampValue()
{
    double num = mValue;
    if (mValue > mMaxValue - mPageSize)
    {
        mValue = mMaxValue - mPageSize;
    }
    if (mValue < 0.0)
    {
        mValue = 0.0;
    }
    bool flag = mPageSize < mMaxValue;
    mDisabled = !flag;
    // mUpButton->mDisabled = !flag;
    // mDownButton->mDisabled = !flag;
    if (mInvisIfNoScroll)
    {
        mVisible = flag;
        // mDownButton->mVisible = flag;
        // mUpButton->mVisible = flag;
    }
    if (mValue != num)
    {
        mScrollListener->ScrollPosition(mId, mValue);
    }
}

void BnScrollbarWidget::SetThumbPosition(int thePosition)
{
    SetValue(thePosition * (mMaxValue - mPageSize) / (GetTrackSize() - GetThumbSize()));
}

void BnScrollbarWidget::ButtonPress(int theId)
{
    mButtonAcc = 0;
    if (theId == 0)
    {
        SetValue(mValue - 1.0);
        return;
    }
    SetValue(mValue + 1.0);
}

void BnScrollbarWidget::ButtonDepress(int theId)
{
}

void BnScrollbarWidget::ButtonDownTick(int theId)
{
    if (theId == 0)
    {
        if (++mButtonAcc >= 25)
        {
            SetValue(mValue - 1.0);
            mButtonAcc = 24;
            return;
        }
    }
    else if (++mButtonAcc >= 25)
    {
        SetValue(mValue + 1.0);
        mButtonAcc = 24;
    }
}

void BnScrollbarWidget::Update()
{
    // base.Update();
    switch (mUpdateMode)
    {
    case 1:
        if (ThumbCompare(mLastMouseX, mLastMouseY) != -1)
        {
            mUpdateMode = 0;
            MarkDirty();
            return;
        }
        if (++mUpdateAcc >= 25)
        {
            SetValue(mValue - mPageSize);
            mUpdateAcc = 20;
            return;
        }
        break;
    case 2:
        if (ThumbCompare(mLastMouseX, mLastMouseY) != 1)
        {
            mUpdateMode = 0;
            MarkDirty();
            return;
        }
        if (++mUpdateAcc >= 25)
        {
            SetValue(mValue + mPageSize);
            mUpdateAcc = 20;
        }
        break;
    default:
        return;
    }
}

int BnScrollbarWidget::ThumbCompare(int x, int y)
{
    int num;
    if (mHorizontal)
    {
        num = x - (mWidth - GetTrackSize()) / 2;
    }
    else
    {
        num = y - (mHeight - GetTrackSize()) / 2;
    }
    if (num < GetThumbPosition())
    {
        return -1;
    }
    if (num >= GetThumbPosition() + GetThumbSize())
    {
        return 1;
    }
    return 0;
}

void BnScrollbarWidget::MouseDown(int x, int y, int theClickCount)
{
    // base.MouseDown(x, y, theClickCount);
}

void BnScrollbarWidget::MouseDown(int x, int y, int theBtnNum, int theClickCount)
{
    // base.MouseDown(x, y, theBtnNum, theClickCount);
    if (!mDisabled)
    {
        switch (ThumbCompare(x, y))
        {
        case -1:
            SetValue(mValue - mPageSize);
            mUpdateMode = 1;
            mUpdateAcc = 0;
            break;
        case 0:
            mPressedOnThumb = true;
            mMouseDownThumbPos = GetThumbPosition();
            mMouseDownX = x;
            mMouseDownY = y;
            break;
        case 1:
            SetValue(mValue + mPageSize);
            mUpdateMode = 2;
            mUpdateAcc = 0;
            break;
        }
    }
    mLastMouseX = x;
    mLastMouseY = y;
}

void BnScrollbarWidget::MouseUp(int x, int y, int theBtnNum, int theClickCount)
{
    // base.MouseUp(x, y, theBtnNum, theClickCount);
    mUpdateMode = 0;
    mPressedOnThumb = false;
    MarkDirty();
}

void BnScrollbarWidget::MouseDrag(int x, int y)
{
    // base.MouseDrag(x, y);
    if (mPressedOnThumb)
    {
        if (mHorizontal)
        {
            SetThumbPosition(mMouseDownThumbPos + x - mMouseDownX);
        }
        else
        {
            SetThumbPosition(mMouseDownThumbPos + y - mMouseDownY);
        }
    }
    mLastMouseX = x;
    mLastMouseY = y;
}

void BnScrollbarWidget::RemoveAllWidgets(bool doDelete, bool recursive)
{
    // base.RemoveAllWidgets(doDelete, recursive);
    if (doDelete)
    {
        // mUpButton = nullptr;
        // mDownButton = nullptr;
    }
}

void BnScrollbarWidget::ButtonPress(int theId, int theClickCount)
{
    ButtonPress(theId);
}

void BnScrollbarWidget::ButtonMouseEnter(int theId)
{
}

void BnScrollbarWidget::ButtonMouseLeave(int theId)
{
}

void BnScrollbarWidget::ButtonMouseMove(int theId, int theX, int theY)
{
}