

#include <GL/glew.h>
#include <Window.hpp>
#include <iostream>


/* ####################################################################################### */
/* Properties getters */
/* ####################################################################################### */

Window::Window()
{

}

/* --------------------------------------------------------------------------------------- */

Window::~Window()
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
    }
}

/* ####################################################################################### */
/* Properties getters */
/* ####################################################################################### */

int
Window::width() const
{
    return m_width;
}

/* --------------------------------------------------------------------------------------- */

int
Window::height() const
{
    return m_height;
}

/* --------------------------------------------------------------------------------------- */

std::string
Window::title() const
{
    return m_title;
}

/* --------------------------------------------------------------------------------------- */

bool
Window::isDoubleBufferEnabled() const
{
    return m_doubleBuffer;
}

/* --------------------------------------------------------------------------------------- */

int
Window::redChannelBits() const
{
    return m_redChannelBits;
}

/* --------------------------------------------------------------------------------------- */

int
Window::greenChannelBits() const
{
    return m_greenChannelBits;
}

/* --------------------------------------------------------------------------------------- */

int
Window::blueChannelBits() const
{
    return m_blueChannelBits;
}

/* --------------------------------------------------------------------------------------- */

int
Window::alphaChannelBits() const
{
    return m_alphaChannelBits;
}

/* --------------------------------------------------------------------------------------- */

int
Window::depthChannelBits() const
{
    return m_depthBits;;
}

/* --------------------------------------------------------------------------------------- */

int
Window::stencilChannelBits() const
{
    return m_stencilBits;
}

/* --------------------------------------------------------------------------------------- */

GLFWwindow*
Window::raw()
{
    return m_window;
}

/* ####################################################################################### */
/* Properties setters */
/* ####################################################################################### */

void
Window::setWidth(int width)
{
    m_width = width;
    if (m_window)
    {
        glfwSetWindowSize(m_window, width, m_height);
    }
}

/* --------------------------------------------------------------------------------------- */

void
Window::setHeight(int height)
{
    m_height = height;
    if (m_window)
    {
        glfwSetWindowSize(m_window, m_width, height);
    }
}

/* --------------------------------------------------------------------------------------- */

void
Window::setVisible(bool visible)
{
    m_visible = visible;
    glfwWindowHint(GLFW_VISIBLE, visible);
}

/* --------------------------------------------------------------------------------------- */

void
Window::setTitle(const std::string& title)
{
    m_title = title;
    if (m_window)
    {
        glfwSetWindowTitle(m_window, title.data());
    }
}

/* --------------------------------------------------------------------------------------- */

void
Window::setSamples(int samplesCount)
{
    m_samples = samplesCount;
    glfwWindowHint(GLFW_SAMPLES, samplesCount);
}

/* --------------------------------------------------------------------------------------- */

void
Window::setDoubleBufferEnabled(bool enabled)
{
    m_doubleBuffer = enabled;
    glfwWindowHint(GLFW_DOUBLEBUFFER, enabled);
}

/* --------------------------------------------------------------------------------------- */

void
Window::setRedChannelBits(int bits)
{
    m_redChannelBits = bits;
    glfwWindowHint(GLFW_RED_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Window::setGreenChannelBits(int bits)
{
    m_greenChannelBits = bits;
    glfwWindowHint(GLFW_GREEN_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Window::setBlueChannelBits(int bits)
{
    m_blueChannelBits = bits;
    glfwWindowHint(GLFW_BLUE_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Window::setAlphaChannelBits(int bits)
{
    m_alphaChannelBits = bits;
    glfwWindowHint(GLFW_ALPHA_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Window::setDepthChannelBits(int bits)
{
    m_depthBits = bits;
    glfwWindowHint(GLFW_DEPTH_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Window::setStencilChannelBits(int bits)
{
    m_stencilBits = bits;
    glfwWindowHint(GLFW_STENCIL_BITS, bits);
}

/* ####################################################################################### */
/* Methods */
/* ####################################################################################### */

bool
Window::create()
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
        std::cout << "[ERROR] Cant create GLFW window" << std::endl;
        return false;
    }

    GLFWwindowsizefun resizeFunc = [](GLFWwindow* window, int width, int height)
    {
        Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (self->resizeHandler)
        {
            self->resizeHandler(self, width, height);
        }
    };
    glfwSetWindowSizeCallback(m_window, resizeFunc);
    return true;
}

/* --------------------------------------------------------------------------------------- */

void
Window::makeCurrent()
{
    glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, this);
}
