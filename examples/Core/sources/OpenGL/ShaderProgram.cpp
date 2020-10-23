#include <Global.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <filesystem>
#include <streambuf>
#include <iostream>
#include <fstream>
#include <string>


/* ####################################################################################### */
/* Support implementation macro */
/* ####################################################################################### */

#ifndef IMPL_SUPPORT_SET_UNIFORM_COMMON
    #define IMPL_SUPPORT_SET_UNIFORM_COMMON\
    GLint location = glGetUniformLocation(m_id, name.data()); \
    if (location == -1) \
    {\
        CGM_EXAMPLES_FUNC_INFO("Error: can not enable attribute array. Attribute is alreay disabled or not exist");\
        std::cout << "Attribute: " << name << std::endl;\
        return;\
    }
#endif

/* ####################################################################################### */
/* Static methods */
/* ####################################################################################### */

std::wstring
ShaderProgram::getShaderFileExtensionByType(ShaderProgram::EShaderType shaderType)
{
    switch (shaderType)
    {
        case ShaderProgram::EShaderType::Vertex:                    return L".vert";
        case ShaderProgram::EShaderType::TessellationControl:       return L".tesc";
        case ShaderProgram::EShaderType::TessellationEvaluation:    return L".tese";
        case ShaderProgram::EShaderType::Geometry:                  return L".geom";
        case ShaderProgram::EShaderType::Fragment:                  return L".frag";
        default:                                                    return L".comp";
    }
}

/* --------------------------------------------------------------------------------------- */

int
ShaderProgram::getShaderTypeByFile(const std::wstring& file)
{
    std::wstring ext = std::filesystem::path(file).extension();

    if (ext == L".vert") return ShaderProgram::EShaderType::Vertex;
    if (ext == L".tesc") return ShaderProgram::EShaderType::TessellationControl;
    if (ext == L".tese") return ShaderProgram::EShaderType::TessellationEvaluation;
    if (ext == L".geom") return ShaderProgram::EShaderType::Geometry;
    if (ext == L".frag") return ShaderProgram::EShaderType::Fragment;
    if (ext == L".comp") return ShaderProgram::EShaderType::Compute;

    return -1;
}

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

ShaderProgram::~ShaderProgram()
{
    if( m_objectCreated )
    {
        glDeleteProgram(m_id);
        glUseProgram(0);
    }
}

/* --------------------------------------------------------------------------------------- */

ShaderProgram::ShaderProgram()
    :OpenGLObject()
{

}

/* ####################################################################################### */
/* Methods */
/* ####################################################################################### */

bool
ShaderProgram::link()
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: shader program is not created");
        return false;
    }

    GLint success;

    for( size_t i = 0; i < m_shadersIDs.size(); ++i )
    {
        glAttachShader(m_id, m_shadersIDs[i]);
    }

    glLinkProgram( m_id );
    glGetProgramiv( m_id, GL_LINK_STATUS, &success );

    if( !success )
    {
        GLint logLength;
        glGetProgramiv( m_id, GL_INFO_LOG_LENGTH, &logLength );

        if( logLength > 0 )
        {
            char* logData = new char[uint64_t(logLength)];

            glGetShaderInfoLog( m_id, logLength, nullptr, logData );
            CGM_EXAMPLES_FUNC_INFO("Error: can not link shader program");
            CGM_EXAMPLES_PRINT(std::string(logData));
        }
        else
        {
            CGM_EXAMPLES_FUNC_INFO("Error: can not link shader program");
        }

        m_linked = false;
        return false;
    }

    for(auto m_shadersID : m_shadersIDs)
    {
        glDeleteShader(m_shadersID);
    }

    m_shadersIDs.clear();

    m_linked = true;
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::linked()
{
    return m_linked;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::addShader(ShaderProgram::EShaderType shaderType, const std::string& sourceCode)
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO( "Error: shader program is not created. Create shader program before shader attaching" );
        return false;
    }

    const char* source = sourceCode.data();
    GLint       success;
    GLuint      shaderId;

    shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &source, nullptr);
    glCompileShader(shaderId);
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

    if( !success )
    {
        GLint logLength;
        glGetShaderiv( shaderId, GL_INFO_LOG_LENGTH, &logLength );

        if( logLength > 0 )
        {
            char* logData = new char[uint64_t(logLength)];

            glGetShaderInfoLog(shaderId, logLength, nullptr, logData);
            CGM_EXAMPLES_FUNC_INFO(std::string(logData));
        }
        return false;
    }
    m_shadersIDs.push_back(shaderId);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::addShaderFromFile(ShaderProgram::EShaderType shaderType, const std::wstring& file)
{
    std::ifstream stream(file);
    std::string sourceCode((std::istreambuf_iterator<char>(stream)),std::istreambuf_iterator<char>());
    if (sourceCode.empty()) {return false;}
    addShader(shaderType, sourceCode);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::addShaderPack(const std::wstring& directory)
{
    auto absdir = std::filesystem::absolute(directory);

    for (const auto& it : std::filesystem::directory_iterator(absdir))
    {
        if (!std::filesystem::is_regular_file(it.path())) continue;
        int type = getShaderTypeByFile(it.path());
        if (type == -1) continue;
        addShaderFromFile(ShaderProgram::EShaderType(type), it.path());
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

int
ShaderProgram::attributeLocation(const std::string& name) const
{
    return glGetAttribLocation(m_id, name.data());
}

/* --------------------------------------------------------------------------------------- */

int
ShaderProgram::uniformLocation(const std::string& name) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: shader program is not created");
        return -1;
    }
    return glGetUniformLocation(m_id, name.data());
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::enableAttributeArray(const std::string& name) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: shader program is not created");
        return;
    }

    GLint location = glGetAttribLocation(m_id, name.data());
    if( location == -1 )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not enable attribute array");
        return;
    }
    glEnableVertexAttribArray(GLuint(location));
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::disableAttributeArray(const std::string& name) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: shader program is not created");
        return;
    }
    GLint location = glGetAttribLocation(m_id, name.data());
    if( location == -1 )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not enable attribute array. Attribute is alreay disable or not exist");
        return;
    }
    glDisableVertexAttribArray(GLuint(location));
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setAttributeBuffer(const std::string& name, EGLType type, uint32_t componentCount, uint32_t offset, uint32_t stride) const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: shader program is not created");
        return;
    }

    GLint location = glGetAttribLocation(m_id, name.data());
    if( location == -1 )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not set attribute array. Attribute disable or not exist");
        return;
    }

    glVertexAttribPointer(GLuint(location), GLint(componentCount), type, GL_TRUE, GLsizei(stride), reinterpret_cast<void*>(offset));
}

/* ####################################################################################### */
/* Uniform variables setters: scalar */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, int32_t scalar) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform1i(location, scalar);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, uint32_t scalar) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform1ui(location, scalar);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::float32 scalar) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform1f(location, scalar);
}

/* ####################################################################################### */
/* Uniform variables setters: x, y */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, int32_t x, int32_t y) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform2i(location, x, y);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, uint32_t x, uint32_t y) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform2ui(location, x, y);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::float32 x, cgm::float32 y) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform2f(location, x, y);
}

/* ####################################################################################### */
/* Uniform variables setters: x, y, z */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, int32_t x, int32_t y, int32_t z) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform3i(location, x, y, z);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, uint32_t x, uint32_t y, uint32_t z) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform3ui(location, x, y, z);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::float32 x, cgm::float32 y, cgm::float32 z) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform3f(location, x, y, z);
}

/* ####################################################################################### */
/* Uniform variables setters: x, y, z, w */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, int32_t x, int32_t y, int32_t z, int32_t w) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4i(location, x, y, z, w);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, uint32_t x, uint32_t y, uint32_t z, uint32_t w) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4ui(location, x, y, z, w);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, cgm::float32 x, cgm::float32 y, cgm::float32 z, cgm::float32 w) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4f(location, x, y, z, w);
}

/* ####################################################################################### */
/* Uniform variables setters: array */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, const int32_t* values, uint32_t count, uint32_t componentsCount) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    if (componentsCount == 1) {glUniform1iv(location, GLsizei(count), values); return;}
    if (componentsCount == 2) {glUniform2iv(location, GLsizei(count), values); return;}
    if (componentsCount == 3) {glUniform3iv(location, GLsizei(count), values); return;}
    if (componentsCount == 4) {glUniform4iv(location, GLsizei(count), values); return;}
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const uint32_t* values, uint32_t count, uint32_t componentsCount) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    if (componentsCount == 1) {glUniform1uiv(location, GLsizei(count), values); return;}
    if (componentsCount == 2) {glUniform2uiv(location, GLsizei(count), values); return;}
    if (componentsCount == 3) {glUniform3uiv(location, GLsizei(count), values); return;}
    if (componentsCount == 4) {glUniform4uiv(location, GLsizei(count), values); return;}
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::float32* values, uint32_t count, uint32_t componentsCount) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    if (componentsCount == 1) {glUniform1fv(location, GLsizei(count), reinterpret_cast<const GLfloat*>(values)); return;}
    if (componentsCount == 2) {glUniform2fv(location, GLsizei(count), reinterpret_cast<const GLfloat*>(values)); return;}
    if (componentsCount == 3) {glUniform3fv(location, GLsizei(count), reinterpret_cast<const GLfloat*>(values)); return;}
    if (componentsCount == 4) {glUniform4fv(location, GLsizei(count), reinterpret_cast<const GLfloat*>(values)); return;}
}

/* ####################################################################################### */
/* Uniform variables setters: float vectors */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, const cgm::vec2& vector) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform2f(location, vector.x, vector.y);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::vec3& vector) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform3f(location, vector.x, vector.y, vector.z);
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::vec4& vector) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
}

/* ####################################################################################### */
/* Uniform variables setters: angles, matrices and quaternon */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, const cgm::xyz::quat& quaternion) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniform4f(location, quaternion.scalar, quaternion.vector.x, quaternion.vector.y, quaternion.vector.z);
}

/* ####################################################################################### */
/* Uniform variables setters: angles, matrices and quaternon */
/* ####################################################################################### */

void
ShaderProgram::setUniform(const std::string& name, const cgm::mat2& matrix) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniformMatrix2fv(location, 1, GL_FALSE, matrix.data());
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::mat3& matrix) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniformMatrix3fv(location, 1, GL_FALSE, matrix.data());
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::setUniform(const std::string& name, const cgm::mat4& matrix) const
{
    IMPL_SUPPORT_SET_UNIFORM_COMMON
    glUniformMatrix4fv(location, 1, GL_FALSE, matrix.data());
}

/* ####################################################################################### */
/* GL object interface */
/* ####################################################################################### */

bool
ShaderProgram::bind() const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not bind shader program, it is not created");
        return false;
    }
    glUseProgram(m_id);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::release() const
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not bind shader program, it is not created");
        return false;
    }
    glUseProgram(0);
    return true;
}

/* --------------------------------------------------------------------------------------- */

bool
ShaderProgram::create()
{
    if( m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: shader program is already created");
        return false;
    }

    m_id = glCreateProgram();

    if( m_id == 0 )
    {
        CGM_EXAMPLES_FUNC_INFO("Error: can not to create shader program");
        m_objectCreated = false;
        return false;
    }

    m_objectCreated = true;
    return true;
}

/* --------------------------------------------------------------------------------------- */

void
ShaderProgram::destroy()
{
    if( !m_objectCreated )
    {
        CGM_EXAMPLES_FUNC_INFO("Warrning: can not destroy shader program, it is not created");
        return;
    }
    glDeleteProgram(m_id);
    glUseProgram(0);

    m_objectCreated = false;
    m_linked = false;
}