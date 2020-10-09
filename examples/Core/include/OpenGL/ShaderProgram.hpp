#pragma once


#include <vector>
#include <string>
#include <CGM/Core>
#include <CGM/Cartesian/3D>
#include <OpenGL/BaseObject.hpp>
#include <Global.hpp>


/**
 * OpenGL shader program.
 */
class ShaderProgram : public OpenGLObject
{
    CGM_EXAMPLES_DISABLE_COPY(ShaderProgram);

/* ####################################################################################### */
public: /* Aliases */
/* ####################################################################################### */

    using Shared    = std::shared_ptr<ShaderProgram>;
    using Unique    = std::unique_ptr<ShaderProgram>;
    using Weak      = std::weak_ptr<ShaderProgram>;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * OpenGL shader types.
     */
    enum EShaderType
    {
        Vertex                 = GL_VERTEX_SHADER,          /**< Vertex shader type */
        Fragment               = GL_FRAGMENT_SHADER,        /**< Fragment shader type */
        Geometry               = GL_GEOMETRY_SHADER,        /**< Geometry shader type */
        TessellationControl    = GL_TESS_CONTROL_SHADER,    /**< TessellationControl shader type */
        TessellationEvaluation = GL_TESS_EVALUATION_SHADER, /**< TessellationEvaluation shader type */
        Compute                = GL_COMPUTE_SHADER          /**< Compute shader type */
    };

/* ####################################################################################### */
public: /* Static methods */
/* ####################################################################################### */

    /**
     * Gets shaders source file extension by types.
     * @param shaderType Type of shader.
     * @return shader source file extension.
     */
    static std::wstring
    getShaderFileExtensionByType(EShaderType shaderType);

    /**
     * Gets shaders type by source file extension.
     * @param file Path to shader source file. This path should contain extension.
     * @return shader type int(shaderType) if all ok, -1 otherwise.
     */
    static int
    getShaderTypeByFile(const std::wstring& file);

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Default constructor with no parameters.
     */
    ShaderProgram();

    /**
     * Destructor.
     */
    ~ShaderProgram() override;

/* ####################################################################################### */
public: /* Methods */
/* ####################################################################################### */

    /**
     * Link compiled OpenGL shaders.
     * @return true if shaders was linked, false otherwise.
     */
    bool
    link();

    /**
     * Check whether shaders was linked.
     * @return true if shaders was linked, false otherwise.
     */
    bool
    linked();

    /**
     * Add shader to program.
     * @param shaderType Type included shader.
     * @param sourceCode Shader source code.
     * @return true if shaders was included, false otherwise.
     */
    bool
    addShader(EShaderType shaderType, const std::string& sourceCode);

    /**
     * Load shader from file and add to program.
     * @param shaderType Type included shader.
     * @param file Shader source file path.
     * @return true if shaders was included, false otherwise.
     */
    bool
    addShaderFromFile(EShaderType shaderType, const std::wstring& file);

    /**
     * Load pack of shaders from file in specified folder and add to program.
     * @param directory Shader pack directory path.
     * @return true if shaders was included, false otherwise.
     */
    bool
    addShaderPack(const std::wstring& directory);

    /**
     * Get the location of an shader attribute variable.
     * @param name Attribute name.
     * @return index of attribute if succecced, -1 otherwise.
     */
    int
    attributeLocation(const std::string& name) const;

    /**
     * Get the uniform location of an shader attribute variable.
     * @param name Attribute name.
     * @return index of attribute if succecced, -1 otherwise.
     */
    int
    uniformLocation(const std::string& name) const;

    /**
     * Enable a generic vertex attribute array.
     * @param name Attribute name.
     */
    void
    enableAttributeArray(const std::string& name);

    /**
     * Disable a generic vertex attribute array.
     * @param name Attribute name.
     */
    void
    disableAttributeArray(const std::string& name);

    /**
     * Define an array of generic vertex attribute data.
     * @param name Attribute name.
     * @param type Buffer elements data type.
     * @param componentCount Components count of buffer elements (2 for 2D vectors, 3D for 3D vectors ...).
     * @param offset Attribute offset element start (in bytes).
     * @param stride Size of buffer element (in bytes).
     */
    void
    setAttributeBuffer(const std::string& name, EGLType type, uint32_t componentCount, uint32_t offset, uint32_t stride = 0);

/* ####################################################################################### */
public: /* Uniform variables setters: scalar */
/* ####################################################################################### */

    /**
     * Set uniform attribute value.
     * Signature: 32 bit integer scalar.
     * @param name Attribute name.
     * @param scalar Attribute value.
     */
    void
    setUniform(const std::string& name, int32_t scalar);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit unsigned integer scalar.
     * @param name Attribute name.
     * @param scalar Attribute value.
     */
    void
    setUniform(const std::string& name, uint32_t scalar);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float scalar.
     * @param name Attribute name.
     * @param scalar Attribute value.
     */
    void
    setUniform(const std::string& name, cgm::float32 scalar);

/* ####################################################################################### */
public: /* Uniform variables setters: x, y */
/* ####################################################################################### */

    /**
     * Set uniform attribute value.
     * Signature: 32 bit integer 2D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     */
    void
    setUniform(const std::string& name, int32_t x, int32_t y);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit unsigned integer 2D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     */
    void
    setUniform(const std::string& name, uint32_t x, uint32_t y);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float 2D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     */
    void
    setUniform(const std::string& name, cgm::float32 x, cgm::float32 y);

/* ####################################################################################### */
public: /* Uniform variables setters: x, y, z */
/* ####################################################################################### */

    /**
     * Set uniform attribute value.
     * Signature: 32 bit integer 3D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     * @param z Attribute Z value.
     */
    void
    setUniform(const std::string& name, int32_t x, int32_t y, int32_t z);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit unsigned integer 3D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     * @param z Attribute Z value.
     */
    void
    setUniform(const std::string& name, uint32_t x, uint32_t y, uint32_t z);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float 3D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     * @param z Attribute Z value.
     */
    void
    setUniform(const std::string& name, cgm::float32 x, cgm::float32 y, cgm::float32 z);

/* ####################################################################################### */
public: /* Uniform variables setters: x, y, z, w */
/* ####################################################################################### */

    /**
     * Set uniform attribute value.
     * Signature: 32 bit integer 4D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     * @param z Attribute Z value.
     * @param w Attribute w value.
     */
    void
    setUniform(const std::string& name, int32_t x, int32_t y, int32_t z, int32_t w);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit unsigned integer 4D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     * @param w Attribute w value.
     */
    void
    setUniform(const std::string& name, uint32_t x, uint32_t y, uint32_t z, uint32_t w);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float 4D.
     * @param name Attribute name.
     * @param x Attribute X value.
     * @param y Attribute Y value.
     * @param z Attribute Z value.
     * @param w Attribute w value.
     */
    void
    setUniform(const std::string& name, cgm::float32 x, cgm::float32 y, cgm::float32 z, cgm::float32 w);

/* ####################################################################################### */
public: /* Uniform variables setters: array */
/* ####################################################################################### */

    /**
     * Set uniform attribute value.
     * Signature: 32 bit integer array.
     * @param name Attribute name.
     * @param values Attribute values array.
     * @param count Array elements count.
     * @param componentsCount Array element components count (if element is cgm::vec3, componentCount = 3).
     */
    void
    setUniform(const std::string& name, const int32_t* values, uint32_t count, uint32_t componentsCount);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit unsigned integer array.
     * @param name Attribute name.
     * @param values Attribute values array.
     * @param count Array elements count.
     * @param componentsCount Array element components count (if element is cgm::vec3, componentCount = 3).
     */
    void
    setUniform(const std::string& name, const uint32_t* values, uint32_t count, uint32_t componentsCount);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float array.
     * @param name Attribute name.
     * @param values Attribute values array.
     * @param count Array elements count.
     * @param componentsCount Array element components count (if element is cgm::vec3, componentCount = 3).
     */
    void
    setUniform(const std::string& name, const cgm::float32* values, uint32_t count, uint32_t componentsCount);

/* ####################################################################################### */
public: /* Uniform variables setters: float vectors */
/* ####################################################################################### */

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float vector 2D.
     * @param name Attribute name.
     * @param vector Attribute value.
     */
    void
    setUniform(const std::string& name, const cgm::vec2& vector);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float vector 3D.
     * @param name Attribute name.
     * @param vector Attribute value.
     */
    void
    setUniform(const std::string& name, const cgm::vec3& vector);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float vector 4D.
     * @param name Attribute name.
     * @param vector Attribute value.
     */
    void
    setUniform(const std::string& name, const cgm::vec4& vector);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float 4x4 matrix.
     * @param name Attribute name.
     * @param vector Attribute value.
     */
    void
    setUniform(const std::string& name, const cgm::xyz::quat& quaternion);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float 2x2 matrix.
     * @param name Attribute name.
     * @param matrix Attribute value.
     */
    void
    setUniform(const std::string& name, const cgm::mat2& matrix);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float 3x3 matrix.
     * @param name Attribute name.
     * @param matrix Attribute value.
     */
    void
    setUniform(const std::string& name, const cgm::mat3& matrix);

    /**
     * Set uniform attribute value.
     * Signature: 32 bit float 4x4 matrix.
     * @param name Attribute name.
     * @param matrix Attribute value.
     */
    void
    setUniform(const std::string& name, const cgm::mat4& matrix);

/* ####################################################################################### */
public: /* GL object interface */
/* ####################################################################################### */

    /**
     * Bind this object.
     * @return true if binding was succeeded, false otherwise.
     */
    bool
    bind() override;

    /**
     * Release this object.
     * @return true if releasing was succeeded, false otherwise.
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

/* ####################################################################################### */
public: /* Private members */
/* ####################################################################################### */

    bool
    m_linked = false;

    std::vector<uint32_t>
    m_shadersIDs;
};
