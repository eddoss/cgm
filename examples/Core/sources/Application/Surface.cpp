

#include <Application/Surface.hpp>
#include <Global.hpp>


/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

Surface::Surface()
{
    if (glfwInit() != GLFW_TRUE)
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
    glfwMakeContextCurrent(m_window);

    glewExperimental = GL_TRUE;
    GLenum GLEWInitResult = glewInit();
    if (GLEWInitResult != GLEW_OK)
    {
        CGM_EXAMPLES_FUNC_ERROR(glewGetErrorString(GLEWInitResult));
    }
}

/* --------------------------------------------------------------------------------------- */

Surface::~Surface()
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
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
        glfwSetWindowSize(m_window, m_width, m_height);
    }
}

/* --------------------------------------------------------------------------------------- */

void
Surface::setHeight(int height)
{
    m_height = height;
    if (m_window)
    {
        glfwSetWindowSize(m_window, m_width, m_height);
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
