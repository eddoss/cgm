

#include <iostream>
#include <Application/Surface.hpp>


/* ####################################################################################### */
/* Properties getters */
/* ####################################################################################### */

Surface::~Surface()
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
Surface::width() const
{
    return m_width;
}

/* --------------------------------------------------------------------------------------- */

int
Surface::height() const
{
    return m_height;
}

/* --------------------------------------------------------------------------------------- */

bool
Surface::visible() const
{
    return m_visible;
}

/* --------------------------------------------------------------------------------------- */

std::string
Surface::title() const
{
    return m_title;
}

/* --------------------------------------------------------------------------------------- */

int
Surface::samples() const
{
    return m_samples;
}

/* --------------------------------------------------------------------------------------- */

bool
Surface::isDoubleBufferEnabled() const
{
    return m_doubleBuffer;
}

/* --------------------------------------------------------------------------------------- */

int
Surface::redChannelBits() const
{
    return m_redChannelBits;
}

/* --------------------------------------------------------------------------------------- */

int
Surface::greenChannelBits() const
{
    return m_greenChannelBits;
}

/* --------------------------------------------------------------------------------------- */

int
Surface::blueChannelBits() const
{
    return m_blueChannelBits;
}

/* --------------------------------------------------------------------------------------- */

int
Surface::alphaChannelBits() const
{
    return m_alphaChannelBits;
}

/* --------------------------------------------------------------------------------------- */

int
Surface::depthChannelBits() const
{
    return m_depthBits;;
}

/* --------------------------------------------------------------------------------------- */

int
Surface::stencilChannelBits() const
{
    return m_stencilBits;
}

/* ####################################################################################### */
/* Properties setters */
/* ####################################################################################### */

void
Surface::setWidth(int width)
{
    m_width = width;
    if (m_window)
    {
        glfwSetWindowSize(m_window, width, m_height);
    }
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setHeight(int height)
{
    m_height = height;
    if (m_window)
    {
        glfwSetWindowSize(m_window, m_width, height);
    }
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setVisible(bool visible)
{
    m_visible = visible;
    glfwWindowHint(GLFW_VISIBLE, visible);
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setTitle(const std::string& title)
{
    m_title = title;
    if (m_window)
    {
        glfwSetWindowTitle(m_window, title.data());
    }
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setSamples(int samplesCount)
{
    m_samples = samplesCount;
    glfwWindowHint(GLFW_SAMPLES, samplesCount);
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setDoubleBufferEnabled(bool enabled)
{
    m_doubleBuffer = enabled;
    glfwWindowHint(GLFW_DOUBLEBUFFER, enabled);
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setRedChannelBits(int bits)
{
    m_redChannelBits = bits;
    glfwWindowHint(GLFW_RED_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setGreenChannelBits(int bits)
{
    m_greenChannelBits = bits;
    glfwWindowHint(GLFW_GREEN_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setBlueChannelBits(int bits)
{
    m_blueChannelBits = bits;
    glfwWindowHint(GLFW_BLUE_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setAlphaChannelBits(int bits)
{
    m_alphaChannelBits = bits;
    glfwWindowHint(GLFW_ALPHA_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setDepthChannelBits(int bits)
{
    m_depthBits = bits;
    glfwWindowHint(GLFW_DEPTH_BITS, bits);
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setStencilChannelBits(int bits)
{
    m_stencilBits = bits;
    glfwWindowHint(GLFW_STENCIL_BITS, bits);
}
