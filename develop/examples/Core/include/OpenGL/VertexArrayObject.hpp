#pragma once


#include <OpenGL/BaseObject.hpp>


/**
 * OpenGL vertex array object (VAO).
 */
class VertexArrayObject : public OpenGLObject
{
    CGM_EXAMPLES_DISABLE_COPY(VertexArrayObject)

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Default constructor with no parameters.
     */
    VertexArrayObject();

    /**
     * Destructor.
     */
    ~VertexArrayObject() override;

/* ####################################################################################### */
public: /* GL object interface */
/* ####################################################################################### */

    /**
     * Bind this object.
     * @return true if binding was succeded, false otherwise.
     */
    bool
    bind() override;

    /**
     * Release this object.
     * @return true if releasing was succeded, false otherwise.
     */
    bool
    release() override;

    /**
     * Create this object.
     * @return true if was created, false otherwise.
     */
    bool
    create() override;

    /**
     * Destroy this object.
     * @return true if was destroyed, false otherwise.
     */
    void
    destroy() override;
};