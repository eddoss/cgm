#pragma once


#include <OpenGL/BaseObject.hpp>
#include <memory>


/**
 * OpenGL vertex array object (VAO).
 */
class VAO : public OpenGLObject
{
//    CGM_EXAMPLES_DISABLE_COPY(VAO)

/* ####################################################################################### */
public: /* Aliases */
/* ####################################################################################### */

    using Shared    = std::shared_ptr<VAO>;
    using Unique    = std::unique_ptr<VAO>;
    using Weak      = std::weak_ptr<VAO>;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Default constructor with no parameters.
     */
    VAO();

    /**
     * Destructor.
     */
    ~VAO() override;

/* ####################################################################################### */
public: /* GL object interface */
/* ####################################################################################### */

    /**
     * Bind this object.
     * @return true if binding was succeded, false otherwise.
     */
    bool
    bind() const override;

    /**
     * Release this object.
     * @return true if releasing was succeded, false otherwise.
     */
    bool
    release() const override;

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