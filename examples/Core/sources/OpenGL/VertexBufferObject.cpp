

#include <OpenGL/VertexBufferObject.hpp>
#include <iostream>


/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

VBO::~VBO()
{
    if( m_objectCreated )
    {
        glDeleteBuffers(1, &m_id);
    }
}

/* --------------------------------------------------------------------------------------- */

VBO::VBO(EBufferType bufferType, EUsagePattern usagePattern, EAccessPattern accessPattern)
    : OpenGLObject()
    , m_bufferType(bufferType)
    , m_usagePattern(usagePattern)
    , m_accessPattern(accessPattern)
{

}

/* ####################################################################################### */
/* Properties getters */
/* ####################################################################################### */

VBO::EBufferType
VBO::bufferType() const
{
    return m_bufferType;
}

/* --------------------------------------------------------------------------------------- */

VBO::EUsagePattern
VBO::usagePattern() const
{
    return m_usagePattern;
}

/* --------------------------------------------------------------------------------------- */

VBO::EAccessPattern
VBO::accessPattern() const
{
    return m_accessPattern;
}

/* --------------------------------------------------------------------------------------- */

bool
VBO::readable() const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: buffer is not created");
        return false;
    }

    switch( m_accessPattern )
    {
        case ReadOnly:  return true;
        case ReadWrite: return true;
        default:        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

int32_t
VBO::size() const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: buffer is not created");
        return -1;
    }
    GLint value = -1;
    glGetBufferParameteriv(m_bufferType, GL_BUFFER_SIZE, &value);
    return value;
}

/* ####################################################################################### */
/* Methods: IO */
/* ####################################################################################### */

bool
VBO::read(uint32_t from, uint32_t count, void* outData) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: buffer is not created");
        return false;
    }

    GLenum error;
    while( true ) // Clear error state
    {
        error = glGetError();
        if( error == GL_NO_ERROR )
        {
            break;
        }
        if( error == GL_CONTEXT_LOST )
        {
            CGM_EXAMPLES_FUNC_INFO("Error: context lost");
            return false;
        }
    };

    glGetBufferSubData(m_bufferType, from, count, outData);
    return glGetError() == GL_NO_ERROR;
}

/* --------------------------------------------------------------------------------------- */

bool
VBO::write(uint32_t offset, uint32_t count, const void* data )
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: buffer is not created");
        return false;
    }

    GLenum error;
    while( true ) // Clear error state
    {
        error = glGetError();
        if( error == GL_NO_ERROR )
        {
            break;
        }
        if( error == GL_CONTEXT_LOST )
        {
            CGM_EXAMPLES_FUNC_INFO("Error: context lost");
            return false;
        }
    };

    glBufferSubData(m_bufferType, offset, count, data);
    return glGetError() == GL_NO_ERROR;
}

/* --------------------------------------------------------------------------------------- */

void
VBO::allocate(uint32_t byteCount, const void* data )
{
    glBufferData(m_bufferType, byteCount, data, m_usagePattern);
}

/* ####################################################################################### */
/* GL object interface */
/* ####################################################################################### */

bool
VBO::bind() const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not bind buffer, it is not created");
        return false;
    }
    glBindBuffer(m_bufferType, m_id);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
VBO::release() const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not bind buffer, it is not created");
        return false;
    }
    glBindBuffer(m_bufferType, 0);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
VBO::create()
{
    if( m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Warrning: buffer is already created");
        return false;
    }

    glGenBuffers(1, &m_id);

    if( m_id == 0 )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not to create buffer");
        m_objectCreated = false;
        return false;
    }

    m_objectCreated = true;
    return true;
}

/* --------------------------------------------------------------------------------------- */

void
VBO::destroy()
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO( "Warrning: can not destroy buffer, it is not created" );
        return;
    }
    glDeleteBuffers(1, &m_id);
    m_id = 0;
    m_objectCreated = false;
}
