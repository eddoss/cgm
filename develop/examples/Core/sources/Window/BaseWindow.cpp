

#include <Window/BaseWindow.hpp>
#include <iostream>
#include <Global.hpp>


BaseWindow::~BaseWindow()
{
    if (m_window)
    {
        glfwTerminate();
    }
}

/* ####################################################################################### */
/* Public methods */
/* ####################################################################################### */

bool
BaseWindow::create()
{
    setVisible(m_visible);
    setSamples(m_samples);
    setRedChannelBits(m_redChannelBits);
    setGreenChannelBits(m_greenChannelBits);
    setBlueChannelBits(m_blueChannelBits);
    setAlphaChannelBits(m_alphaChannelBits);
    setDepthChannelBits(m_depthBits);
    setStencilChannelBits(m_stencilBits);
    setDoubleBufferEnabled(m_doubleBuffer);

    m_window = glfwCreateWindow(m_width, m_height, m_title.data(), nullptr, nullptr);

    if (!m_window)
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant create GLFW window");
        return false;
    }

    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
    {
        auto* self = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
        self->resizeEvent(width, height);
    });

    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        auto* self = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
        self->keyEvent
        (
            *reinterpret_cast<const EKey*>(&key),
            *reinterpret_cast<const EState*>(&action),
            *reinterpret_cast<const EModifier*>(&mods)
        );
    });

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y)
    {
        auto* self = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
        self->mouseMoveEvent(cgm::Vector<2,double>{x,y});
    });

    glfwSetCursorEnterCallback(m_window, [](GLFWwindow* window, int entered)
    {
        auto* self = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
        self->mouseAreaEvent(bool(entered));
    });

    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
    {
        auto* self = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
        self->buttonEvent
        (
            *reinterpret_cast<const EButton*>(&button),
            *reinterpret_cast<const EState*>(&action),
            *reinterpret_cast<const EModifier*>(&mods)
        );
    });

    glfwSetScrollCallback(m_window, [](GLFWwindow* window, double x, double y)
    {
        auto* self = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
        self->scrollEvent(cgm::Vector<2,double>{x,y});
    });
    glfwSetWindowUserPointer(m_window, this);
    glfwMakeContextCurrent(m_window);

    return true;
}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::start()
{
    if (!m_window)
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant start window event loop. GLFW window was not created.");
    }

    beforeLoop();

    glfwSetTime(0.0);

    while (!glfwWindowShouldClose(m_window))
    {
        glfwPollEvents();

        const double time = glfwGetTime();
        const double tickDelta = time - m_previousTick;
        m_previousTick = time;

        loopEvent(tickDelta, time);

        glfwSwapBuffers(m_window);
    }

    afterLoop();
}

/* ####################################################################################### */
/* Protected methods */
/* ####################################################################################### */

BaseWindow::EState
BaseWindow::keyState(EKey key)
{
    auto val = glfwGetKey(m_window, size_t(key));
    return *reinterpret_cast<const EState*>(&val);
}

/* --------------------------------------------------------------------------------------- */

BaseWindow::EState
BaseWindow::buttonState(EButton button)
{
    auto val = glfwGetMouseButton(m_window, size_t(button));
    return *reinterpret_cast<const EState*>(&val);
}

/* --------------------------------------------------------------------------------------- */

cgm::Vector<2,double>
BaseWindow::mousePosition()
{
    cgm::Vector<2,double> pos {};
    glfwGetCursorPos(m_window, &pos.x, &pos.y);
    return pos;
}

/* --------------------------------------------------------------------------------------- */

bool
BaseWindow::isMouseInWindow()
{
    return bool(glfwGetWindowAttrib(m_window, GLFW_HOVERED));
}

/* ####################################################################################### */
/* Window events */
/* ####################################################################################### */

void
BaseWindow::beforeLoop()
{

}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::loopEvent(double tickDelta, double time)
{

}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::afterLoop()
{

}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::resizeEvent(size_t width, size_t height)
{
    m_width = width;
    m_height = height;
}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::keyEvent(EKey key, EState state, EModifier modifier)
{

}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::mouseAreaEvent(bool entered)
{

}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::mouseMoveEvent(cgm::Vector<2,double> position)
{

}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::buttonEvent(EButton button, EState state, EModifier modifier)
{

}

/* --------------------------------------------------------------------------------------- */

void
BaseWindow::scrollEvent(cgm::Vector<2,double> offset)
{

}