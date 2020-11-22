#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <string>


class Surface
{

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    Surface();

    virtual
    ~Surface();

/* ####################################################################################### */
public: /* Properties getters */
/* ####################################################################################### */

    /** Get window width */
    inline int
    width() const;

    /** Get window height */
    inline int
    height() const;

    /** Check whether window is visible */
    inline bool
    visible() const;

    /** Get window title */
    inline std::string
    title() const;

    /** Get window samples */
    inline int
    samples() const;

    /** Check whether double buffer enabled */
    inline bool
    isDoubleBufferEnabled() const;

    /** Get window red channel bit depth */
    inline int
    redChannelBits() const;

    /** Get window green channel bit depth */
    inline int
    greenChannelBits() const;

    /** Get window red channel bit depth */
    inline int
    blueChannelBits() const;

    /** Get window blue channel bit depth */
    inline int
    alphaChannelBits() const;

    /** Get window alpha channel bit depth */
    inline int
    depthChannelBits() const;

    /** Get window stencil channel bit depth */
    inline int
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
protected: /* Window protected properties */
/* ####################################################################################### */

    GLFWwindow*
    m_window {nullptr};

/* ####################################################################################### */
private: /* Window private properties */
/* ####################################################################################### */

    int
    m_width {1920};

    int
    m_height {1080};

    int
    m_visible {GLFW_TRUE};

    int
    m_samples {0};

    int
    m_doubleBuffer {GLFW_TRUE};

    int
    m_redChannelBits {8};

    int
    m_greenChannelBits {8};

    int
    m_blueChannelBits {8};

    int
    m_alphaChannelBits {8};

    int
    m_depthBits {32};

    int
    m_stencilBits {16};

    std::string
    m_title {"OpenGL Window"};
};


/* ####################################################################################### */
/* IMPLEMENTATION | Properties getters */
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