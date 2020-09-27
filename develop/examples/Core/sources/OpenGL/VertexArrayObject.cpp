

#include <Global.hpp>
#include <OpenGL/VertexArrayObject.hpp>
#include <iostream>


/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

VertexArrayObject::~VertexArrayObject()
{
    if( m_objectCreated )
    {
        glDeleteVertexArrays(1, &m_id);
    }
}

/* --------------------------------------------------------------------------------------- */

VertexArrayObject::VertexArrayObject()
    :OpenGLObject()
{

}

/* ####################################################################################### */
/* GL object interface */
/* ####################################################################################### */

bool
VertexArrayObject::bind()
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
VertexArrayObject::release()
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
VertexArrayObject::create()
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
VertexArrayObject::destroy()
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