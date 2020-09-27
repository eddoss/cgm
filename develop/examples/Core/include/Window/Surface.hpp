#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <functional>


#define INIT_GLFW                                               \
if (glfwInit() != GLFW_TRUE)                                    \
{                                                               \
    glfwTerminate();                                            \
    std::cout                                                   \
    << "[ERROR] Cant initialize GLFW"                           \
    << std::endl;                                               \
    exit(-1);                                                   \
}                                                               \
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  \
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                  \
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

/* --------------------------------------------------------------------------------------- */

#define INIT_GLEW                                               \
glewExperimental = GL_TRUE;                                     \
GLenum GLEWInitResult = glewInit();                             \
if( GLEWInitResult != GLEW_OK )                                 \
{                                                               \
    std::cout                                                   \
    << "[ERROR] Cant initialize GLEW: "                         \
    << glewGetErrorString(GLEWInitResult)                       \
    << std::endl;                                               \
    exit(-1);                                                   \
}


class Surface
{

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Destructor.
     */
    virtual
    ~Surface();

/* ####################################################################################### */
public: /* Properties getters */
/* ####################################################################################### */

    /** Get window width */
    int
    width() const;

    /** Get window height */
    int
    height() const;

    /** Check whether window is visible */
    bool
    visible() const;

    /** Get window title */
    std::string
    title() const;

    /** Get window samples */
    int
    samples() const;

    /** Check whether double buffer enabled */
    bool
    isDoubleBufferEnabled() const;

    /** Get window red channel bit depth */
    int
    redChannelBits() const;

    /** Get window green channel bit depth */
    int
    greenChannelBits() const;

    /** Get window red channel bit depth */
    int
    blueChannelBits() const;

    /** Get window blue channel bit depth */
    int
    alphaChannelBits() const;

    /** Get window alpha channel bit depth */
    int
    depthChannelBits() const;

    /** Get window stencil channel bit depth */
    int
    stencilChannelBits() const;

/* ####################################################################################### */
public: /* Properties setters */
/* ####################################################################################### */

    /**
     * Set window width.
     * @param width Window width
     */
    void
    setWidth(int width);

    /**
     * Set window height
     * @param width Window height
     */
    void
    setHeight(int height);

    /**
     * Set window visibility
     * @param visible Window visibility
     */
    void
    setVisible(bool visible);

    /**
     * Set window title
     * @param title Title string
     */
    void
    setTitle(const std::string& title);

    /**
     * Set window samples
     * @param samplesCount Window samples count
     */
    void
    setSamples(int samplesCount);

    /**
     * Set double buffer enabled or disabled
     * @param enabled Enabled or disabled double buffer
     */
    void
    setDoubleBufferEnabled(bool enabled);

    /**
     * Set window red channel bit depth
     * @param bits Channel bit depth
     */
    void
    setRedChannelBits(int bits);

    /**
     * Set window green channel bit depth
     * @param bits Channel bit depth
     */
    void
    setGreenChannelBits(int bits);

    /**
     * Set window blue channel bit depth
     * @param bits Channel bit depth
     */
    void
    setBlueChannelBits(int bits);

    /**
     * Set window blue channel bit depth
     * @param bits Channel bit depth
     */
    void
    setAlphaChannelBits(int bits);

    /**
     * Set window alpha channel bit depth
     * @param bits Channel bit depth
     */
    void
    setDepthChannelBits(int bits);

    /**
     * Set window stencil channel bit depth
     * @param bits Channel bit depth
     */
    void
    setStencilChannelBits(int bits);

/* ####################################################################################### */
protected: /* Window protected attributes */
/* ####################################################################################### */

    int
    m_width {1280};

    int
    m_height {720};

    int
    m_visible {GLFW_TRUE};

    int
    m_samples {16};

    int
    m_doubleBuffer {GLFW_TRUE};

    int
    m_redChannelBits {16};

    int
    m_greenChannelBits {16};

    int
    m_blueChannelBits {16};

    int
    m_alphaChannelBits {16};

    int
    m_depthBits {32};

    int
    m_stencilBits {16};

    std::string
    m_title {"OpenGL Window"};

    GLFWwindow*
    m_window {nullptr};
};