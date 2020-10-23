#pragma once


#include <GL/glew.h>


/**
 * OpenGL primitive types.
 */
enum EGLType
{
    SByte   = GL_BYTE,              /**< Signed byte */
    SShort  = GL_SHORT,             /**< Signed short integer */
    SInt    = GL_INT,               /**< Signed integer */
    UByte   = GL_UNSIGNED_BYTE,     /**< Unsigned byte */
    UShort  = GL_UNSIGNED_SHORT,    /**< Unsigned short integer */
    UInt    = GL_UNSIGNED_INT,      /**< Unsigned integer */
    Float   = GL_FLOAT,             /**< 32 bit float */
    Double  = GL_DOUBLE,            /**< 64 bit float */
    Byte2   = GL_2_BYTES,           /**< 2 byte number */
    Byte3   = GL_3_BYTES,           /**< 3 byte number */
    Byte4   = GL_4_BYTES            /**< 4 byte number */
};

/**
 * OpenGL base object. It describe create/destroy, bind/release
 * and get object ID functionality. All GL objects inherited from
 * this class.
 */
class OpenGLObject
{

/* ####################################################################################### */
public: /* Destructor */
/* ####################################################################################### */

    virtual
    ~OpenGLObject() = default;

/* ####################################################################################### */
public: /* Properties getters */
/* ####################################################################################### */

    /**
     * Get GL object ID.
     * @return Object ID.
     */
    GLuint
    id()
    {
        return m_id;
    }

    /**
     * Check whether the object is created.
     * @return true if object was created, false otherwise.
     */
    bool
    created() const
    {
        return m_objectCreated;
    }

/* ####################################################################################### */
public: /* Public virtual methods */
/* ####################################################################################### */

    /**
     * Bind this object.
     * @return true if binding was succeded, false otherwise.
     */
    virtual bool
    bind() const = 0;

    /**
     * Release this object.
     * @return true if releasing was succeded, false otherwise.
     */
    virtual bool
    release() const = 0;

    /**
     * Create this object.
     * @return true if was created, false otherwise.
     */
    virtual bool
    create() = 0;

    /**
     * Destroy this object.
     * @return true if was destroyed, false otherwise.
     */
    virtual void
    destroy() = 0;

/* ####################################################################################### */
protected: /* Protected attributes */
/* ####################################################################################### */

    GLuint
    m_id;

    bool
    m_objectCreated = false;
};
