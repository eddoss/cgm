

#include <Global.hpp>
#include <OpenGL/VertexArrayObject.hpp>
#include <iostream>


/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

VAO::~VAO()
{
    if( m_objectCreated )
    {
        glDeleteVertexArrays(1, &m_id);
    }
}

/* --------------------------------------------------------------------------------------- */

VAO::VAO()
    :OpenGLObject()
{

}

/* ####################################################################################### */
/* GL object interface */
/* ####################################################################################### */

bool
VAO::bind()
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("[ERROR]: can not bind array object, it is not created")
        return false;
    }
    glBindVertexArray(m_id);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
VAO::release()
{
    if (!m_objectCreated)
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not bind array object, it is not created")
        return false;
    }
    glBindVertexArray(0);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
VAO::create()
{
    if (m_objectCreated)
    {
        CGM_EXAMPLES_FUNC_INFO("Error: array object is already created");
        return false;
    }

    glGenVertexArrays(1, &m_id);

    if (m_id == 0)
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not to create array object")
        m_objectCreated = false;
        return false;
    }

    m_objectCreated = true;
    return true;
}

/* --------------------------------------------------------------------------------------- */

void
VAO::destroy()
{
    if (!m_objectCreated)
    {
        CGM_EXAMPLES_FUNC_INFO("Error: array object is not created")
        return;
    }

    glDeleteVertexArrays(1, &m_id);

    m_id = 0;
    m_objectCreated = false;
}