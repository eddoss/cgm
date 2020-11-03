#pragma once


#include <CGM/Modules/Core.hpp>
#include <Application/Surface.hpp>


class BaseWindow : public Surface
{

/* ####################################################################################### */
public: /* Enums */
/* ####################################################################################### */

    enum class EModifier
    {
        Alt             = GLFW_MOD_ALT,
        Ctrl            = GLFW_MOD_CONTROL,
        Shift           = GLFW_MOD_SHIFT,
        Super           = GLFW_MOD_SUPER,
        CapsLock        = GLFW_MOD_CAPS_LOCK,
        NumLock         = GLFW_MOD_NUM_LOCK
    };

    enum class EState
    {
        Press           = GLFW_PRESS,
        Release         = GLFW_RELEASE,
        Repeat          = GLFW_REPEAT
    };

    enum class EKey
    {
        A               = GLFW_KEY_A,
        B               = GLFW_KEY_B,
        C               = GLFW_KEY_C,
        D               = GLFW_KEY_D,
        E               = GLFW_KEY_E,
        F               = GLFW_KEY_F,
        G               = GLFW_KEY_G,
        H               = GLFW_KEY_H,
        I               = GLFW_KEY_I,
        J               = GLFW_KEY_J,
        K               = GLFW_KEY_K,
        L               = GLFW_KEY_L,
        M               = GLFW_KEY_M,
        N               = GLFW_KEY_N,
        O               = GLFW_KEY_O,
        P               = GLFW_KEY_P,
        Q               = GLFW_KEY_Q,
        R               = GLFW_KEY_R,
        S               = GLFW_KEY_S,
        T               = GLFW_KEY_T,
        U               = GLFW_KEY_U,
        V               = GLFW_KEY_V,
        W               = GLFW_KEY_W,
        X               = GLFW_KEY_X,
        Y               = GLFW_KEY_Y,
        Z               = GLFW_KEY_Z,
        Num0            = GLFW_KEY_0,
        Num1            = GLFW_KEY_1,
        Num2            = GLFW_KEY_2,
        Num3            = GLFW_KEY_3,
        Num4            = GLFW_KEY_4,
        Num5            = GLFW_KEY_5,
        Num6            = GLFW_KEY_6,
        Num7            = GLFW_KEY_7,
        Num8            = GLFW_KEY_8,
        Num9            = GLFW_KEY_9,
        Space           = GLFW_KEY_SPACE,
        Comma           = GLFW_KEY_COMMA,
        Minus           = GLFW_KEY_MINUS,
        Slash           = GLFW_KEY_SLASH,
        Period          = GLFW_KEY_PERIOD,
        Equal           = GLFW_KEY_EQUAL,
        Backslash       = GLFW_KEY_BACKSLASH,
        Semicolon       = GLFW_KEY_SEMICOLON,
        Apostrophe      = GLFW_KEY_APOSTROPHE,
        GraveAccent     = GLFW_KEY_GRAVE_ACCENT,
        LeftBracket     = GLFW_KEY_LEFT_BRACKET,
        RightBracket    = GLFW_KEY_RIGHT_BRACKET,
        Escape          = GLFW_KEY_ESCAPE,
        Enter           = GLFW_KEY_ENTER,
        Tab             = GLFW_KEY_TAB,
        Backspace       = GLFW_KEY_BACKSPACE,
        Insert          = GLFW_KEY_INSERT,
        Delete          = GLFW_KEY_DELETE,
        Right           = GLFW_KEY_RIGHT,
        Left            = GLFW_KEY_LEFT,
        Down            = GLFW_KEY_DOWN,
        Up              = GLFW_KEY_UP,
        PageUp          = GLFW_KEY_PAGE_UP,
        PageDown        = GLFW_KEY_PAGE_DOWN,
        Home            = GLFW_KEY_HOME,
        End             = GLFW_KEY_END,
        CapsLock        = GLFW_KEY_CAPS_LOCK,
        ScrollLock      = GLFW_KEY_SCROLL_LOCK,
        NumLock         = GLFW_KEY_NUM_LOCK,
        PrintScreen     = GLFW_KEY_PRINT_SCREEN,
        Pause           = GLFW_KEY_PAUSE,
        F1              = GLFW_KEY_F1,
        F2              = GLFW_KEY_F2,
        F3              = GLFW_KEY_F3,
        F4              = GLFW_KEY_F4,
        F5              = GLFW_KEY_F5,
        F6              = GLFW_KEY_F6,
        F7              = GLFW_KEY_F7,
        F8              = GLFW_KEY_F8,
        F9              = GLFW_KEY_F9,
        F10             = GLFW_KEY_F10,
        F11             = GLFW_KEY_F11,
        F12             = GLFW_KEY_F12,
        F13             = GLFW_KEY_F13,
        F14             = GLFW_KEY_F14,
        F15             = GLFW_KEY_F15,
        F16             = GLFW_KEY_F16,
        F17             = GLFW_KEY_F17,
        F18             = GLFW_KEY_F18,
        F19             = GLFW_KEY_F19,
        F20             = GLFW_KEY_F20,
        F21             = GLFW_KEY_F21,
        F22             = GLFW_KEY_F22,
        F23             = GLFW_KEY_F23,
        F24             = GLFW_KEY_F24,
        F25             = GLFW_KEY_F25,
        KP0             = GLFW_KEY_KP_0,
        KP1             = GLFW_KEY_KP_1,
        KP2             = GLFW_KEY_KP_2,
        KP3             = GLFW_KEY_KP_3,
        KP4             = GLFW_KEY_KP_4,
        KP5             = GLFW_KEY_KP_5,
        KP6             = GLFW_KEY_KP_6,
        KP7             = GLFW_KEY_KP_7,
        KP8             = GLFW_KEY_KP_8,
        KP9             = GLFW_KEY_KP_9,
        KPDecimal       = GLFW_KEY_KP_DECIMAL,
        KPDivide        = GLFW_KEY_KP_DIVIDE,
        KPMultiply      = GLFW_KEY_KP_MULTIPLY,
        KPSubtract      = GLFW_KEY_KP_SUBTRACT,
        KPAdd           = GLFW_KEY_KP_ADD,
        KPEnter         = GLFW_KEY_KP_ENTER,
        KPEqual         = GLFW_KEY_KP_EQUAL,
        LeftShift       = GLFW_KEY_LEFT_SHIFT,
        LeftCtrl        = GLFW_KEY_LEFT_CONTROL,
        LeftAlt         = GLFW_KEY_LEFT_ALT,
        LeftSuper       = GLFW_KEY_LEFT_SUPER,
        RightShift      = GLFW_KEY_RIGHT_SHIFT,
        RightCtrl       = GLFW_KEY_RIGHT_CONTROL,
        RightAlt        = GLFW_KEY_RIGHT_ALT,
        RightSuper      = GLFW_KEY_RIGHT_SUPER,
        Menu            = GLFW_KEY_MENU,
        Last            = GLFW_KEY_LAST,
        World1          = GLFW_KEY_WORLD_1,
        World2          = GLFW_KEY_WORLD_2,
        Unknown         = GLFW_KEY_UNKNOWN,
};

    enum class EButton
    {
        Left            = GLFW_MOUSE_BUTTON_LEFT,
        Right           = GLFW_MOUSE_BUTTON_RIGHT,
        Middle          = GLFW_MOUSE_BUTTON_MIDDLE,
        Last            = GLFW_MOUSE_BUTTON_LAST
    };

/* ####################################################################################### */
public: /* Public methods */
/* ####################################################################################### */

    virtual
    ~BaseWindow();

    BaseWindow();

    /**
     * Start window main loop.
     */
    void
    run();

/* ####################################################################################### */
protected: /* Protected methods */
/* ####################################################################################### */

    /**
     * Gets state of key.
     * @param key Key to check.
     * @return key state.
     */
    EState
    keyState(EKey key);

    /**
     * Gets state of mouse button.
     * @param button Button to check.
     * @return button state.
     */
    EState
    buttonState(EButton button);

    /**
     * Gets mouse position.
     * @return mouse position.
     */
    cgm::Vector<2,int>
    mousePosition();

    /**
     * Gets mouse offset between position in current tick and previous tick.
     * @return Mouse position offset.
     */
    cgm::Vector<2,double>
    mouseOffset();

    /**
     * Convert window coordinate to screen coordinate (in to [-1,1] range).
     * @param pos Window coordinate to convert.
     * @return Converted coord.
     */
    template<typename T>
    cgm::Vector<2,T>
    convertToScreen(const cgm::Vector<2,int>& pos) const;

    /**
     * Checks is mouse in window area.
     * @return True if mouse in window area, false otherwise.
     */
    bool
    isMouseInWindow();

    /**
     * Gets current time (in seconds).
     * @return Time since event loop was started.
     */
    CGM_FORCEINLINE double
    time() const;

    /**
     * Gets delta between previous and current ticks (in seconds).
     * @return Tick delta time.
     */
    CGM_FORCEINLINE double
    tickDelta() const;

    /**
     * Gets window aspect ratio (width / height).
     * @return Aspect ratio.
     */
    template<typename T=float>
    CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
    aspect() const;

    /**
     * Close window.
     */
    virtual void
    close();

/* ####################################################################################### */
protected: /* Window events */
/* ####################################################################################### */

    /**
     * Call this handler before window main loop started.
     */
    virtual void
    beforeLoop();

    /**
     * Window tick event handler.
     */
    virtual void
    tickEvent();

    /**
     * Window clear event. Called before 'renderEvent'.
     */
    virtual void
    clearEvent();

    /**
     * Window render event handler.
     */
    virtual void
    renderEvent();

    /**
     * Call this handler after window main loop finished.
     */
    virtual void
    afterLoop();

    /**
     * Resize event handler.
     */
    virtual void
    resizeEvent();

    /**
     * Key event handler.
     * @param key Input key.
     * @param state Key state.
     * @param modifier Modifier key pressed.
     */
    virtual void
    keyEvent(EKey key, EState state, EModifier modifier);

    /**
     * Mouse area event handler.
     * @param entered If it is True, mouse was entered to window area, otherwise mouse was leaved.
     */
    virtual void
    mouseAreaEvent(bool entered);

    /**
     * Mouse move event handler.
     * @param position Mouse position.
     */
    virtual void
    mouseMoveEvent(cgm::Vector<2,int> position);

    /**
     * Mouse button event handler.
     * @param button Input button.
     * @param state Button state.
     * @param modifier Modifier key pressed.
     */
    virtual void
    buttonEvent(EButton button, EState state, EModifier modifier);

    /**
     * Scroll event handler.
     * @param offset Scroll offset.
     */
    virtual void
    scrollEvent(cgm::Vector<2,double> offset);

/* ####################################################################################### */
private: /* Internals */
/* ####################################################################################### */

    double
    m_time = 0.0;

    double
    m_currentTick = 0.0;

    double
    m_previousTick = 0.0;

    cgm::Vector<2,double>
    m_previous_tick_mouse_pos {0,0};
};

/* --------------------------------------------------------------------------------------- */

CGM_FORCEINLINE double
BaseWindow::time() const
{
    return m_time;
}

/* --------------------------------------------------------------------------------------- */

CGM_FORCEINLINE double
BaseWindow::tickDelta() const
{
    return m_currentTick;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
BaseWindow::aspect() const
{
    return static_cast<T>(width()) / height();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
cgm::Vector<2,T>
BaseWindow::convertToScreen(const cgm::Vector<2,int>& pos) const
{
    return
    {
        cgm::fit<T>(T(pos.x), T(0), T(width()), T(-1.0), T(1.0)),
        cgm::fit<T>(T(pos.y), T(0), T(height()), T(1.0), T(-1.0))
    };
}